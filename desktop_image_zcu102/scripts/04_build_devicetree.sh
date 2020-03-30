#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/4_build_devicetree.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Creates the vivado project and create the first system.dtb file, compatible
#	with device-tree overlays.
#
# TODO:
#
# CHANGELOG:
#  [03-10-2018] Update to Vivado v2018.1:
#    - Board file version changed to 3.2 (xilinx.com:zcu102:part0:3.2)
#    - Device 'xczu9eg-ffvb1156-2-i' changed to 'xczu9eg-ffvb1156-2-e'
#
#  [14-11-2018] SDSoC driver added.
# 
#------------------------------------------------------------------------------

# Create working directory for device tree development
mkdir -p $WD/devicetree

# Download latest Device Tree Compiler (dtc), required to work with
# device tree overlays, and build it.
cd $WD/devicetree
git clone https://git.kernel.org/pub/scm/utils/dtc/dtc.git
cd $WD/devicetree/dtc
git checkout -b wb "$GITTAG_DTC"
make -j"$(nproc)"

# Download Xilinx device tree repository
cd $WD/devicetree
git clone https://github.com/Xilinx/device-tree-xlnx
cd $WD/devicetree/device-tree-xlnx

git checkout -b wb $GITTAG_LINUX

# Create directory to build device tree for zcu102 board
mkdir $WD/devicetree/zcu102
cd $WD/devicetree/zcu102

# Create required files
cat > create_hdf.tcl << EOF
set cur_dir [pwd]

# Create Vivado project
create_project -force zcu102_dt \$cur_dir/zcu102_dt -part xczu9eg-ffvb1156-2-e
set proj_name [current_project]
set proj_dir [get_property directory [current_project]]
set_property "target_language" "VHDL" \$proj_name
set_property board_part xilinx.com:zcu102:part0:3.2 [current_project]

# Create block diagram
create_bd_design "design_1"
update_compile_order -fileset sources_1

# Add processing system for Zynq US+ Board
create_bd_cell -type ip -vlnv xilinx.com:ip:zynq_ultra_ps_e:3.2 zynq_ultra_ps_e_0
apply_bd_automation -rule xilinx.com:bd_rule:zynq_ultra_ps_e -config {apply_board_preset "1"}  [get_bd_cells zynq_ultra_ps_e_0]

# Make sure required AXI ports are active
set_property -dict [list CONFIG.PSU__USE__M_AXI_GP0 {1}  \
                         CONFIG.PSU__USE__M_AXI_GP1 {1}  \
                         CONFIG.PSU__USE__M_AXI_GP2 {1}] \
                         [get_bd_cells zynq_ultra_ps_e_0]

# Add interrupt port
set_property -dict [list CONFIG.PSU__USE__IRQ0 {1}] [get_bd_cells zynq_ultra_ps_e_0]

# Set Frequencies
set_property -dict [list CONFIG.PSU__FPGA_PL0_ENABLE {1} CONFIG.PSU__CRL_APB__PL0_REF_CTRL__FREQMHZ {100}] [get_bd_cells zynq_ultra_ps_e_0]

# Connect clocks
connect_bd_net [get_bd_pins zynq_ultra_ps_e_0/pl_clk0] \
               [get_bd_pins zynq_ultra_ps_e_0/maxihpm0_fpd_aclk] \
               [get_bd_pins zynq_ultra_ps_e_0/maxihpm1_fpd_aclk] \
               [get_bd_pins zynq_ultra_ps_e_0/maxihpm0_lpd_aclk]

# Update layout of block design
regenerate_bd_layout

# Create wrapper file
make_wrapper -files [get_files \$proj_dir/\$proj_name.srcs/sources_1/bd/design_1/design_1.bd] -top
add_files -norecurse \$proj_dir/\$proj_name.srcs/sources_1/bd/design_1/hdl/design_1_wrapper.vhd
update_compile_order -fileset sources_1
update_compile_order -fileset sim_1
set_property top design_1_wrapper [current_fileset]
save_bd_design

# Generate output products
generate_target all [get_files  *.bd]

# Write hardware definition and close project
write_hwdef -force -file "\$cur_dir/zcu102.hdf"
close_project
EOF

cat > create_devicetree.tcl << EOF
open_hw_design zcu102.hdf
set_repo_path ../device-tree-xlnx
create_sw_design device-tree -os device_tree -proc psu_cortexa53_0
set_property CONFIG.periph_type_overrides "{BOARD zcu102-rev1.0}" [get_os]
generate_target -dir dts
EOF

# Generate device tree from a simple vivado project
vivado -mode batch -source create_hdf.tcl
hsi -mode batch -source create_devicetree.tcl

# Edit Device Tree
cd $WD/devicetree/zcu102/dts/

# Add interrupt controller to PL node
sed -i '/compatible = "simple-bus";/a \\t\tinterrupt-parent = <&gic>;' pl.dtsi

# Enable DMA usage via DMA Proxy
sed -i '/fpd_dma_chan1/a \\t\t\t#dma-cells = <1>;' zynqmp.dtsi

# Modify bootargs
BOOTARGS="bootargs = \"console=ttyPS0,115200 rootdelay=3 root=/dev/mmcblk0p2 rw earlyprintk uio_pdrv_genirq.of_id=generic-uio earlycon clk_ignore_unused\";"
sed -i "s|.*bootargs.*|\t\t$BOOTARGS|" system-top.dts

# Patch to correct dual lane DP
# wget https://www.xilinx.com/Attachment/0001-Fix-for-gtr_sel0-polarity-correct-for-dual-lane-DP.patch
patch $WD/devicetree/device-tree-xlnx/device_tree/data/kernel_dtsi/2017.1/BOARD/zcu102-revb.dtsi $PATCHES_DIR/devicetree/0001-Fix-for-gtr_sel0-polarity-correct-for-dual-lane-DP.patch

# Add SDSoC driver
# Create the .dtsi file
cat > sdsoc-driver.dtsi << EOF
/{
 xlnk {
 compatible = "xlnx,xlnk-1.0";
 };
};
EOF

# Modify system-top.dts to include the .dtsi
sed -i '/"pl.dtsi"/a /include/ "sdsoc-driver.dtsi"' $WD/devicetree/zcu102/dts/system-top.dts  

# Patch the pcw.dtsi file to correct the display-port 
patch $WD/devicetree/zcu102/dts/pcw.dtsi $PATCHES_DIR/devicetree/0002-fix-display-port.patch


# Generate device tree blob (adding symbols, that is the reason for
# using the last version of dtc)
cd $WD/devicetree/zcu102/dts
dtc -I dts -O dtb -@ -o system.dtb system-top.dts
