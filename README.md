# Accelerating a Classic 3D Video Game (The DOOM) on Heterogeneous Reconfigurable MPSoCs

## Introduction



This repository contains all the instructions and the scripts necessary to run the 3D Video Game DOOM on a platform where an FPGA will accelerate the execution of some portion of the compiled code.

There are two main steps:

 1. to create a complete Linux-based system running on a Zynq UltraScale+ MPSoC ZCU102 Evaluation Kit (see the platform details [here](https://www.xilinx.com/products/boards-and-kits/ek-u1-zcu102-g.html)).
 
 2. to run the DOOM on the created system and accelerating it by using Hardware Accelerators on the Programmable Logic of the FPGA.

You are free to replicate the work, modify and adapt the scripts to run the DOOM upon other platforms. 

Cite the work with the following reference: 

```
@inproceedings{surianolima2020doom,
  title={Accelerating a Classic 3D Video Game on Heterogeneous Reconfigurable MPSoCs},
  author={Suriano, Leonardo and Lima, David and de la Torre, Eduardo},
  booktitle={International Symposium on Applied Reconfigurable Computing},
  pages={136--150},
  year={2020},
  organization={Springer}
}

```

For the original published paper, use the following [link](https://link.springer.com/chapter/10.1007/978-3-030-44534-8_11).

## What do You Need?

 1. a Linux-based OS (we tested everything on Xubuntu 16.04, 18.04, and Mint).
 2. an internet connection.
 3. a Vivado version 2018.1.
 4. a ZCU102 evaluation kit (you can use other platforms by modifying the script to create the system). 

## Create the System

The scripts to create the system were inspired by Yocto recipes, Petalinux recipes, and [ARTICo³ scripts](https://github.com/des-cei/artico3).

### Instruction to Create the System

 1. Run the script from within the folder `desktop_image_zcu102`
 
```
$ source desktop_image_zcu102.sh 

```
 2. If there are some dependency problems, install the missing packet (using `apt`, for example).
 3. Set the right path pointing to the Vivado installation folder (the default is `\opt`; if you use the standard installation of Vivado, leave it with the default choice)
 4. choose Vivado version `2018.1`. If you use other Vivado version, you may need to modify the script.
 5. use an empty, just-created folder for storing the created files to be copied on an SD-card.
 6. follow the instruction of the script.