#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/8_build_kernel.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Apply a patch to enable the required features and compile the kernel.
#
# TODO:
#
# CHANGELOG:
#
#------------------------------------------------------------------------------

cd $WD/linux-xlnx
git checkout -b wb "$GITTAG_LINUX"

make -j $(nproc) xilinx_zynqmp_defconfig

# Apply the kernel patch to enable all required features, which are:
#
# *[DISABLE] General setup->Initial RAM filesystem and RAM disk (initramfs/initrd) support 
#
# *[DISABLE] Bus cupport->PCI support
#
# *[ENABLE]  Device Drivers->Input device support->Mouse interface
# *[ENABLE]  Device Drivers->Staging drivers->Xilinx APF Acelerator Driver->Xilinx APF DMA engines support
#
# *[ENABLE]  Kernel hacking->Tracers->Kernel Function Tracer
#
patch $WD/linux-xlnx/.config $PATCHES_DIR/kernel/0001-enable-required-features.patch

# Compile the kernel
make -j $(nproc)
