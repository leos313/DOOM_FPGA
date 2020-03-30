#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/7_generate_boot_images.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Generates the boot.bin file.
#
# TODO:
#
# CHANGELOG:
#
#------------------------------------------------------------------------------

mkdir -p $WD/boot
cd $WD/boot

# Copy files
cp $WD/firmware/fsbl/executable.elf fsbl.elf
cp $WD/firmware/pmufw/executable.elf pmufw.elf
cp $WD/firmware/arm-trusted-firmware/build/zynqmp/release/bl31/bl31.elf bl31.elf
cp $WD/u-boot-xlnx/u-boot.elf u-boot.elf

# Generate boot file
cat > boot.bif << EOF
image : {
    [bootloader, destination_cpu = a53-0]fsbl.elf
    [destination_cpu = pmu]pmufw.elf
    [destination_cpu = a53-0, exception_level = el-3, trustzone]bl31.elf
    [destination_cpu = a53-0, exception_level = el-2]u-boot.elf
}
EOF
bootgen -arch zynqmp -image boot.bif -o boot.bin
