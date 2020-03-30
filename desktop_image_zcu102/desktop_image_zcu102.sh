#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "desktop_image_zcu102.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Script to automatically build an SD Card image to boot a Debian 9 Stretch
#   based system with a desktop-like environment in the Xilinx 
#	zcu102 ultrascale+ platform.
#
#   It is recommended to run this script with the following command:
#
#   $ source doom.sh | tee log.txt
#
#   This will save all the output in a log file for future debug, if needed.
#
# TODO:
#   - Complete the step 10: artico3 files.
#	- Add compatibility with other vivado versions. 
#
# CHANGELOG:
# 	[22-11-2018]: Init separated repository.
#
#-------------------------------------------------------------------------------

# Git tags to get known stable versions
#
# NOTE: users can decide to comment the respective lines in the code to
#       get the latest versions, but these are provided as failsafe
#       alternatives.
GITTAG_LINUX="xilinx-v2018.1"
GITTAG_DTC="v1.4.7"

# Scripts directory
SCRIPTS="$PWD/scripts"

#
# [0] Parse command line arguments
#

if [ "$#" -ne 0 ]; then
    printf "Illegal number of arguments\n"
    printf "Usage: $0\n"
    exit 1
fi

#
# [1] Check dependencies
#
echo  "----------------------------------"
printf "Checking dependencies ...\n"
source $SCRIPTS/01_check_dependencies.sh
printf "\n"

#
# [2] Setup environment variables and working directory
#
echo "----------------------------------"
printf "Setting environment variables and working directory ...\n"
source $SCRIPTS/02_setup_environment.sh
printf "\n"

#
# [3] Download sources from Git repositories
#
echo "----------------------------------"
printf "Downloading u-boot and linux-xlnx repositories ...\n"
source $SCRIPTS/03_download_sources.sh
printf "\n"

#
# [4] Build Device Tree
#
echo "----------------------------------"
printf "Building Device Tree ...\n"
source $SCRIPTS/04_build_devicetree.sh
printf "\n"

#
# [5] Build low-level firmware
#
echo "----------------------------------"
printf "Building low-level Firmware ...\n"
source $SCRIPTS/05_build_lowlevel_firmware.sh
printf "\n"

#
# [6] Build U-Boot
#
echo "----------------------------------"
printf "Building U-Boot ...\n"
source $SCRIPTS/06_build_u_boot.sh
printf "\n"

#
# [7] Generate boot image
#
echo "----------------------------------"
printf "Creating boot.bin ...\n"
source $SCRIPTS/07_generate_boot_image.sh
printf "\n"

#
# [8] Build Linux kernel
#
echo "----------------------------------"
printf "Compiling the kernel ...\n"
source $SCRIPTS/08_build_kernel.sh
printf "\n"

#
# [9] Prepare rootfs
#
echo "----------------------------------"
printf "Preparing the rootfs ...\n"
source $SCRIPTS/09_prepare_rootfs.sh
printf "\n"

#
# [10] Set up ARTICo3 system
#
echo "----------------------------------"
printf "Setting up artico3 files ...\n"
source $SCRIPTS/10_set_artico3.sh
printf "\n"

#
# [11] Prepare SD card
#
echo "----------------------------------"
printf "Preparing the SD Card image ...\n"
source $SCRIPTS/11_prepare_sd_card.sh
printf "\n"

#
# [12] Final steps
#
echo "----------------------------------"
printf "ARTICo3/desktop SD card image has been generated successfully.\n\n"
printf "Please execute the following post-installation steps:\n"
printf "* SD card image : $WD/rootfs/desktop_image_zcu102.img\n\n"
printf "  > sudo -H dd if=$WD/rootfs/desktop_image_zcu102.img of=/dev/sdX bs=4M status=progress\n\n"
printf "* Set boot mode to SD card.\n"
printf "* Turn on the board, connect with UART.\n"
printf "* If 'ZynqMP> ' prompt appears type 'boot' followed by 'Enter'.\n"
printf "The Linux prompt '#/ ' will appear.\n"
printf "Log in as Linaro\n\n"
printf "* >login linaro\n\n"
printf "Execute ./desktop_install.sh to make final steps.\n\n"
printf "* source desktop_install.sh\n\n"
printf "After reboot you should see the login screen.\n"
