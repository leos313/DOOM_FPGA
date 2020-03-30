#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/11_prepare_sd_card.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Prepare the sd card image with the linaro debian 9 FS with required mali
#   userspace drivers and mali.ko module.
#
# TODO:
#	- Add variables to use instead of paths.
#
# CHANGELOG:
#   [11-9-2018] Mali drivers:
#     - Defined loop10 as loop device
#     - Mali userspace drivers steps
#     - Module mali.ko compilation
#     - Xorg drivers and configuration
#     - Script install_desktop.sh
#   [19-11-2018] Now It uses the first unused loop device 
#
#------------------------------------------------------------------------------

cd $WD/rootfs

# Create SD image file
dd if=/dev/zero of=desktop_image_zcu102.img bs=1M count=4k status=progress

# Mount SD image file in loop device
sudo -H losetup -D

# Get first empty loop device
LOOP_DEVICE=$(sudo -H losetup -f)
sudo -H losetup -P $LOOP_DEVICE desktop_image_zcu102.img

#
# Create partitions
#
# to create the partitions programatically (rather than manually)
# we're going to simulate the manual input to fdisk
# The sed script strips off all the comments so that we can
# document what we're doing in-line with the actual commands
# Note that a blank line (commented as "default" will send a empty
# line terminated with a newline to take the fdisk default.
#
sed -e 's/\s*\([\+0-9a-zA-Z]*\).*/\1/' << EOF | sudo -H fdisk $LOOP_DEVICE
  o # clear the in memory partition table
  n # new partition
  p # primary partition
  1 # partition number 1
    # default - start at beginning of disk
  +100M # 100 MB boot parttion
  n # new partition
  p # primary partition
  2 # partion number 2
    # default, start immediately after preceding partition
    # default, extend partition to end of disk
  a # make a partition bootable
  1 # bootable partition is partition 1 -- /dev/sda1
  t # change a partition type
  1 # target partition is partition 1
  c # partition type is W95 FAT32 (LBA)
  p # print the in-memory partition table
  w # write the partition table
  q # and we're done
EOF

# Format partitions
LOOP_DEVICE_P1="${LOOP_DEVICE}p1"
LOOP_DEVICE_P2="${LOOP_DEVICE}p2"

sudo -H mkfs.vfat $LOOP_DEVICE_P1
sudo -H mkfs.ext4 $LOOP_DEVICE_P2

# Mount partitions
mkdir $WD/rootfs/boot
mkdir $WD/rootfs/root
sudo -H mount -o defaults,uid=1000,gid=1000 $LOOP_DEVICE_P1 $WD/rootfs/boot
sudo -H mount -t ext4 $LOOP_DEVICE_P2 $WD/rootfs/root

# Set up boot partition
cp $WD/boot/boot.bin $WD/rootfs/boot
cp $WD/linux-xlnx/arch/arm64/boot/Image $WD/rootfs/boot
cp $WD/devicetree/zcu102/dts/system.dtb $WD/rootfs/boot
sync

# Download Linaro (Debian) and extract rootfs
wget http://releases.linaro.org/debian/images/developer-arm64/18.04/linaro-stretch-developer-20180416-89.tar.gz
sudo -H tar --strip-components=1 -xzphf linaro-stretch-developer-20180416-89.tar.gz -C root
sync

# Create script to initialize ARTICo3
cat > $WD/rootfs/setup.sh << EOF
# Load ARTICo3 device tree overlay
echo "Loading ARTICo3 device tree overlay..."
mkdir /sys/kernel/config/device-tree/overlays/artico3
echo overlays/artico3.dtbo > /sys/kernel/config/device-tree/overlays/artico3/path

# Load DMA proxy driver
echo "Loading DMA proxy driver..."
modprobe mdmaproxy

# Remove kernel messages from serial port
echo 1 > /proc/sys/kernel/printk
EOF
chmod +x $WD/rootfs/setup.sh

# Create script to move kernel modules to /lib/modules/...
cat > $WD/rootfs/artico3_init.sh << EOF
mkdir -p /lib/modules/\$(uname -r)
mv /root/mdmaproxy.ko /lib/modules/\$(uname -r)
touch /lib/modules/\$(uname -r)/modules.order
touch /lib/modules/\$(uname -r)/modules.builtin
depmod
rm -f /root/artico3_init.sh
EOF
chmod +x $WD/rootfs/artico3_init.sh

# Copy additional files
sudo -H mkdir -p $WD/rootfs/root/lib/firmware/overlays
#
# TODO: Discomment this ?
#
#sudo -H mv $WD/rootfs/artico3.dts $WD/rootfs/root/lib/firmware/overlays
#sudo -H mv $WD/rootfs/artico3.dtbo $WD/rootfs/root/lib/firmware/overlays
#sudo -H cp $WD/artico3/linux/drivers/dmaproxy/mdmaproxy.ko $WD/rootfs/root/root
#sudo -H mv $WD/rootfs/setup.sh $WD/rootfs/root/root
#sudo -H mv $WD/rootfs/artico3_init.sh $WD/rootfs/root/root
sync


# Create temp dir to store temp files
mkdir $WD/temp
cd $WD/temp

# Mali userspace drivers:
# Xilinx release
REL="rel-v2018.1"
# Driver version
RP="r8p0-01rel0"

# Download mali userspace drivers
wget https://www.xilinx.com/publications/products/tools/mali-400-userspace.tar

# Extract until have the libraries
tar -xf mali-400-userspace.tar -C $WD/temp/
tar -xf $WD/temp/mali/$REL/downloads-mali.tar -C $WD/temp/
mkdir $WD/temp/mali-userspace.git
tar -xf $WD/temp/downloads-mali/git2_gitenterprise.xilinx.com.Graphics.mali400-xlnx-userspace.git.tar.gz -C $WD/temp/mali-userspace.git
git clone $WD/temp/mali-userspace.git $WD/temp/mali-userspace

# Copy to rootfs
sudo -H cp -r $WD/temp/mali-userspace/$RP/aarch64-linux-gnu/x11/usr/ $WD/rootfs/root/


# mali.ko compilation
# Extracted source code directory
drv_dir="$WD/temp/DX910-SW-99002-$RP/driver/src/devicedrv/mali"

# Patches directory
#patches_mali="$WD/temp/patches/kernel-module-mali"
#mkdir -p $patches_mali

# Download abd extract mali utgard drivers source code from ARM website
wget https://armkeil.blob.core.windows.net/developer/Files/downloads/mali-drivers/kernel/mali-utgard-gpu/DX910-SW-99002-r8p0-01rel0.tgz
tar -xf DX910-SW-99002-$RP.tgz -C $WD/temp/

# Download and apply patches
# cd $patches_mali

patch $drv_dir/Makefile                         $PATCHES_DIR/mali/kernel_module/0001-Change-Makefile-to-be-compatible-with-Yocto.patch
patch $drv_dir/platform/arm/arm.c               $PATCHES_DIR/mali/kernel_module/0002-staging-mali-r8p0-01rel0-Add-the-ZYNQ-ZYNQMP-platfor.patch
patch $drv_dir/linux/mali_linux_trace.h         $PATCHES_DIR/mali/kernel_module/0003-staging-mali-r8p0-01rel0-Remove-unused-trace-macros.patch
patch $drv_dir/platform/arm/arm.c               $PATCHES_DIR/mali/kernel_module/0004-staging-mali-r8p0-01rel0-Don-t-include-mali_read_phy.patch
patch $drv_dir/linux/mali_kernel_linux.c        $PATCHES_DIR/mali/kernel_module/0005-linux-mali_kernel_linux.c-Handle-clock-when-probed-a.patch
patch $drv_dir/platform/arm/arm.c               $PATCHES_DIR/mali/kernel_module/0006-arm.c-global-variable-dma_ops-is-removed-from-the-ke.patch

# Patch 0007 and 0008 modify two files each
cd $drv_dir/linux/
patch -i                                        $PATCHES_DIR/mali/kernel_module/0007-Replace-__GFP_REPEAT-by-__GFP_RETRY_MAYFAIL.patch
patch -i                                        $PATCHES_DIR/mali/kernel_module/0008-mali_internal_sync-Rename-wait_queue_t-with-wait_que.patch

patch $drv_dir/linux/mali_memory_swap_alloc.c   $PATCHES_DIR/mali/kernel_module/0009-mali_memory_swap_alloc.c-Rename-global_page_state-wi.patch
patch $drv_dir/common/mali_pm.c                 $PATCHES_DIR/mali/kernel_module/0010-common-mali_pm.c-Add-PM-runtime-barrier-after-removi.patch
patch $drv_dir/linux/mali_kernel_linux.c        $PATCHES_DIR/mali/kernel_module/0011-linux-mali_kernel_linux.c-Enable-disable-clock-for-r.patch

# Change to source directory and compile the module
cd $drv_dir
KDIR=$WD/linux-xlnx ARCH=arm64 BUILD=release MALI_PLATFORM="arm" USING_DT=1 MALI_SHARED_INTERRUPTS=1 MALI_QUIET=1 make
# NOTE: If you try to compile with -j$(nproc) it fails.

# Copy to rootfs
sudo -H cp $drv_dir/mali.ko $WD/rootfs/root/root/
sync

# Modify the rc.local file to load the module automatically each boot
sudo -H sed -i '21i insmod /root/mali.ko' $WD/rootfs/root/etc/rc.local

# xorg-driver and xorg-xserver
# This is the version that should be used with 2017.1:
# GITTAG_XF86="1.3.0"
# NOTE: Compile errors with this version

# For 2018.1:
GITTAG_XF86="1.4.1"

# Extracted source code directory
xorg_dir="$WD/temp/xf86-video-armsoc"
# Patches directory
#patches_xorg="$WD/temp/patches/xf86-video-armsoc"
#mkdir -p $patches_xorg

# Download repo
cd $WD/temp
git clone https://gitlab.freedesktop.org/xorg/driver/xf86-video-armsoc
cd $xorg_dir
echo "-------------------------------------------------------------------------"
#git checkout -b "wb" $GITTAG_XF86

# Download and apply patches
#cd $patches_xorg


# The patch modifies multiple files
cd $xorg_dir/src
patch -i $PATCHES_DIR/mali/xf86_video_armsoc/0001-src-drmmode_xilinx-Add-the-dumb-gem-support-for-Xili.patch
# One of the patches files is wrong located
mkdir -p $xorg_dir/src/drmmode_xilinx
mv $xorg_dir/src/drmmode_xilinx.c $xorg_dir/src/drmmode_xilinx/drmmode_xilinx.c

# Copy the complete folder, it will be compiled after xfce4 installation
sudo -H cp -r $WD/temp/xf86-video-armsoc $WD/rootfs/root/home/linaro

cd $WD/temp

# Xorg configuration file
wget https://raw.githubusercontent.com/Xilinx/meta-xilinx/rel-v2018.1/meta-xilinx-bsp/recipes-graphics/xorg-xserver/xserver-xf86-config/zynqmp/xorg.conf

# Copy to rootfs, it will be moved after xfce installation
sudo -H cp $WD/temp/xorg.conf $WD/rootfs/root/home/linaro/
sync

# Script to set up the desktop-like environment in the zcu102
cat > $WD/rootfs/desktop_install.sh << EOF
#!/bin/sh

# Update and upgrade from repos
sudo -H apt-get update
printf 'Y' | sudo -H apt-get upgrade

# Install desktop-like environment packages
printf 'Y' | sudo -H apt-get install xfce4 xorg-dev libudev-dev xutils-dev autoconf libtool autogen

# Configure xorg
sudo -H chmod 777 xorg.conf
sudo -H cp xorg.conf /usr/share/X11/xorg.conf.d/

# Compile and install armsoc.so driver
sudo chmod 777 /home/linaro/xf86-video-armsoc/*
cd /home/linaro/xf86-video-armsoc
sudo -H autoreconf -fi
sudo -H ./configure --with-drmmode=xilinx --enable-maintainer-mode
sudo -H make
sudo -H make install

# Change te location of armsoc.so file
sudo -H cp /usr/local/lib/xorg/modules/drivers/armsoc_drv.so /usr/lib/xorg/modules/drivers/
sudo chmod 777 /usr/lib/xorg/modules/drivers/armsoc_drv.so

# Reboot
sudo -H reboot
EOF
chmod +x $WD/rootfs/desktop_install.sh

sudo -H mv $WD/rootfs/desktop_install.sh $WD/rootfs/root/home/linaro/
sync

# Unmount partitions
sudo -H umount $LOOP_DEVICE_P1
sudo -H umount $LOOP_DEVICE_P2
rm -rf $WD/rootfs/boot
rm -rf $WD/rootfs/root

# Remove SD image file from loop device
sudo -H losetup -D

cd $WD
