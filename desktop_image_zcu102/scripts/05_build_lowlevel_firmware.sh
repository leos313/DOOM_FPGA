#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/5_build_lowlevel_firmware.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Generates the fsbl.elf, bl31.elf and the pmufw.elf files.
#
# TODO:
#
# CHANGELOG:
#   [22-10-2018]: xilfpga_pcap drivers changed:
#	  - Added two patch files to bugfix a problem in the pmu, drivers changed 
#	  to v2.0.
#
#------------------------------------------------------------------------------

# Create directory to low-firmware development
mkdir -p $WD/firmware
cd $WD/firmware

#
# Build ARM Trusted Firmware
#
# NOTE: repo version xilinx-v2018.1 is used (it is compatible) because
#       it is the first release in which PL configuration from Linux is
#       done properly [1] (in previous releases, it was a non-blocking
#       process that led to runtime errors due to wrong PL programming and
#       race conditions).
#
# PL programming from Linux steps:
#
#     1. echo $flags > /sys/class/fpga_manager/fpga0/flags
#        echo $firmware > /sys/class/fpga_manager/fpga0/firmware
#
#        This procedure does not follow conventional FPGA Manager framework,
#        since it uses custom files named _flags_ and _firmware_ instead
#        of relying on Device Tree Overlays. See [2] for more info.
#
#     2. Linux (xilinx-v2017.2) @ ARM Cortex A53
#        | fpga_mgr_firmware_load()       drivers/fpga/fpga-mgr.c
#        | fpga_mgr_buf_load()            drivers/fpga/fpga-mgr.c
#        | zynqmp_fpga_ops_write()        drivers/fpga/zynqmp-fpga.c
#        | zynqmp_pm_fpga_load()          drivers/soc/xilinx/zynqmp/pm.c
#        | invoke_pm_fn()                 drivers/soc/xilinx/zynqmp/pm.c
#        | do_fw_call()                   drivers/soc/xilinx/zynqmp/pm.c
#        | do_fw_call_smc()               drivers/soc/xilinx/zynqmp/pm.c
#        | arm_smccc_smc()                arch/arm64/kernel/smccc-call.S
#
#     3. ARM Trusted Firmware (xilinx-v2018.1) @ ARM Cortex A53
#        | pm_smc_handler()               plat/xilinx/zynqmp/pm_service/pm_svc_main.c
#        | pm_fpga_load()                 plat/xilinx/zynqmp/pm_service/pm_api_sys.c
#        | pm_ipi_send_sync()             plat/xilinx/zynqmp/pm_service/pm_ipi.c
#        | pm_ipi_send_common()           plat/xilinx/zynqmp/pm_service/pm_ipi.c
#        | ipi_mb_notify()                plat/xilinx/zynqmp/pm_service/pm_ipi.c
#
#     4. Zynq MP PMU Firmware (xilinx-v2017.1) @ PMU MicroBlaze
#        | PmProcessApiCall ()            <embeddedsw>/lib/sw_apps/zynqmp_pmufw/src/pm_core.c
#        | PmFpgaLoad ()                  <embeddedsw>/lib/sw_apps/zynqmp_pmufw/src/pm_core.c
#        | XFpga_PL_BitSream_Load ()      <embeddedsw>/lib/sw_services/xilfpga/src/xilfpga_pcap.c
#
# [1] https://github.com/Xilinx/arm-trusted-firmware/commit/c055151bfd7641f9a748de2ecd50ff968ff07176#diff-84707f287ea5d2f11d613b22d81b5534
# [2] Documentation/devicetree/bindings/fpga/fpga-region.txt
#
git clone https://github.com/Xilinx/arm-trusted-firmware.git
cd $WD/firmware/arm-trusted-firmware
git checkout -b wb "$GITTAG_LINUX"

make -j $(nproc) PLAT=zynqmp RESET_TO_BL31=1

# Create ZynqMP FSBL + PMU Firmware projects
cd $WD/firmware
cp $WD/devicetree/zcu102/zcu102.hdf $WD/firmware
cat > create_firmware.tcl << EOF
set hwdsgn [open_hw_design zcu102.hdf]
generate_app -hw \$hwdsgn -os standalone -proc psu_cortexa53_0 -app zynqmp_fsbl -sw fsbl -dir fsbl
generate_app -hw \$hwdsgn -os standalone -proc psu_pmu_0 -app zynqmp_pmufw -sw pmufw -dir pmufw
EOF
hsi -mode batch -source create_firmware.tcl

# Modify BSPs to support DPR
#
# Patch xilxfpga_pcap v4.0 to be compatible with v2.0.
patch $WD/firmware/pmufw/zynqmp_pmufw_bsp/psu_pmu_0/libsrc/xilfpga_*/src/xilfpga_pcap.c $PATCHES_DIR/pmu/0001-xilfpga-pcap-c_v4_0-to-be-compatible-with-v2_0.patch
patch $WD/firmware/pmufw/zynqmp_pmufw_bsp/psu_pmu_0/libsrc/xilfpga_*/src/xilfpga_pcap.h $PATCHES_DIR/pmu/0002-xilfpga-pcap-h_v4_0-to-be-compatible-with-v2_0.patch

# Build ZynqMP FSBL + PMU Firmware
cd $WD/firmware/fsbl
make
cd $WD/firmware/pmufw
make
