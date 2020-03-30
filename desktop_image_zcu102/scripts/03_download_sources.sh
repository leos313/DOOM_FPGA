#/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/3_download_sources.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Download u-boot and linux kernel repos
#
# TODO:
#
# CHANGELOG:
#
#------------------------------------------------------------------------------

# Download repos in the working directory
git clone https://github.com/Xilinx/u-boot-xlnx.git
git clone https://github.com/xilinx/linux-xlnx
