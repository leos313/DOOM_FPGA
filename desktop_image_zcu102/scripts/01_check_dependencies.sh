#!/bin/bash
# -----------------------------------------------------------------------------
# ------------------------- Doom TFM (CEI 2017/2018)---------------------------
# -----------------------------------------------------------------------------
# 	Desktop image zcu102 project
# 		File: - "scripts/1_check_dependencies.sh"
#
# -----------------------------------------------------------------------------
# Authors: David Lima       (davidlimaastor@gmail.com)
#          Leonardo Suriano (leonardo.suriano@upm.es)
#
# Description:
#   Check that all required libraries are available.
#
#
# TODO:
#
# CHANGELOG:
#
#------------------------------------------------------------------------------


# Functions to check availability of required applications and libraries
function pre_check {
    var=$3
    if command -v "$2" > /dev/null 2>&1; then
        printf "[OK]    $1\n"
    else
        printf "[ERROR] $1 (ubuntu pkg: $4)\n"
        eval $var=false
    fi
}

function pre_check_lib {
    var=$3
    ldconfig -p | grep "$2" > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        printf "[OK]    $1\n"
    else
        printf "[ERROR] $1 (ubuntu pkg: $4)\n"
        eval $var=false
    fi
}

# General dependencies
pre_check "Git" "git" ALLCHECK "git"
pre_check "Sed" "sed" ALLCHECK ""
pre_check "Make" "make" ALLCHECK "build-essential"
pre_check "Diff" "diff" ALLCHECK "diff"
pre_check "Tar" "tar" ALLCHECK "tar"

# Device Tree Compiler (dtc) dependencies
pre_check "Flex" "flex" ALLCHECK "flex"
pre_check "Bison" "bison" ALLCHECK "bison"

if [ "$ALLCHECK" = false ]; then
    printf "Dependencies not met. Install missing packages and try again.\n"
    exit 1
fi

# Exit if [ $? -ne 0 ] from now on (i.e. if any error occurs while
# executing one of the commands in the script.)
set -e
