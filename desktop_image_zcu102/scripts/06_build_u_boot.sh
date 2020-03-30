#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/6_build_u_boot.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Compiles and generates the u-boot.
#
# TODO:
#
# CHANGELOG:
#   [04-10-2018] Update to Vivado v2018.1:
#     - defconfig file changed to xilinx_zynqmp_zcu102_rev1_0_defconfig
#     - Default bootargs are deleted from defconfig file. 
#
#------------------------------------------------------------------------------

cd $WD/u-boot-xlnx
git checkout -b wb "$GITTAG_LINUX"

# Remove default bootargs (in some defconfigs, BOOTARGS is in the *_defconfig file)
sed -i '/.*BOOTARGS.*/d' $WD/u-boot-xlnx/configs/xilinx_zynqmp_zcu102_rev1_0_defconfig

make -j $(nproc) xilinx_zynqmp_zcu102_rev1_0_defconfig ;# xilinx_zynqmp_zcu102_rev1_0_defconfig for version >= xilinx-v2018.1

sed -i 's|"sdboot=.*|"sdboot=mmc dev \$sdbootdev \&\& mmcinfo \&\& run uenvboot;" \\|' $WD/u-boot-xlnx/include/configs/xilinx_zynqmp.h

cd $WD/u-boot-xlnx
make -j $(nproc)
