#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/2_setup_environment.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Set working paths and all required environmental variables, such as 
#   ARCH and CROSS_COMPILE.
#
# TODO:
#
# CHANGELOG:
#   [22-10-2018]: PATCHES_DIR environment variable added.
#
#------------------------------------------------------------------------------

# Save patches directory
PATCHES_DIR="$PWD/patches"

# Xilinx tools installation directory
printf "Type yout Xilinx installation directory:\n"
printf "/opt is the default:"
while true; do
    read -e -p "> " -i "/opt" XILINX_ROOT
    if [[ $XILINX_ROOT = "" ]]; then
        continue
    fi
    if [[ ! -e "$XILINX_ROOT" ]]; then
        printf "$XILINX_ROOT was not found, please select an existing directory.\n"
        continue
    else
        break
    fi
done

# Create working directory
printf "Type path for the working directory:\n"
while true; do
    read -e -p "> " WD
    if [[ $WD = "" ]]; then
	continue
   fi
    WD=${WD/#\~/$HOME} # make tilde work
    if [ -d "$WD" ]; then # true if dir exists
	if find "$WD" -mindepth 1 -print -quit | grep -q .; then # true if dir not empty
	    printf "The directory $(pwd)/$WD is not empty, please choose different name:\n"
	else # true if dir exists and emtpy
	    break
	fi;
    else # true if dir does not exist
	mkdir -p $WD
	break
    fi
done
WD=$( cd $WD ; pwd -P ) # change to absolute path
cd $WD

# Get cross-compiler toolchain
printf "Type in your Xilinx Vivado tool version.\n"
printf "2018.1 is the only compatible\n"
while true; do
    read -e -p "> " -i "2018.1" XILINX_VERSION
    if [[ $XILINX_VERSION = "" ]]; then
        continue
    fi
    XILINX_VERSION=${XILINX_VERSION/#\~/$HOME} # make tilde work
    if [[ ! -e "$XILINX_ROOT/Xilinx/Vivado/$XILINX_VERSION" ]]; then
        printf "$XILINX_ROOT/Xilinx/Vivado/$XILINX_VERSION was not found. Change XILINX_ROOT value to match your installation directory and run script again.\n"
        exit 1
    else
        break
    fi
done

# Export environment variables
export ARCH="arm64"
export CROSS_COMPILE="$XILINX_ROOT/Xilinx/SDK/$XILINX_VERSION/gnu/aarch64/lin/aarch64-linux/bin/aarch64-linux-gnu-"
export KDIR="$WD/linux-xlnx"
export PATH="$WD/devicetree/dtc:$PATH"
export PATH="$WD/u-boot-digilent/tools:$PATH"


# Source Xilinx tools script (add Xilinx tools to the path)
source "$XILINX_ROOT/Xilinx/Vivado/$XILINX_VERSION/settings64.sh"
