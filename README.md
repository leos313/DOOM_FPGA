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

Some more details can be found in the Master Thesis of David Lima using [this link](https://github.com/Limiloiko/TFM_DOOM).

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
 
## Run the Game (on the OS of the Zynq Ultrascale+)

Let's do that in two steps: 
 * first we run the game with no hardware accelerators
 * then we provide hardware accelerators and how to run it on the created system.

### Doom with NO Hardware Accelerator

If you want to just play the game, copy the script `.../download_and_compile_DOOM/DOOM_download_compile.sh` on the board and run it:

```
$ source DOOM_download_compile.sh
```

You can also perform the steps manually.

The steps that must be done in order to execute the following. However, in order to profile the application, it is necessary to add an extra CFLAG to the makefiles due to the default configuration of the GCC compiler in the platform. These steps are:

  1. Download the source code of the Crispy-DOOM from its official repository, and the shareware version of the game content.
 
  2. Install the dependencies. They are the same as de chocolate-doom source port, which is in the Debian official repositories, so we can ask the apt-get command to install them.
  
  3. Generate the configuration files using the `autoreconf` command.
  
  4. Generate the makefiles executing the configuration files generated above. If the profiling is going to be executed, first the -pg flag have to be added to to the CFLAGS environmental variable used by the gcc compiler. This will instrument the code so that gprof, which is a performance analysis tool for Unix applications, will report detailed information about the execution of the game. In addition, if it is going to be executed in the ZCU102 platform, the -no-pie flag must be added too. This is due to the default configuration of the platform gcc compiler, which generates pie shared object binaries, although they run as a normal executable would.
  
  5. Compile the source code with the `make` command. This will generate the executable file of the game inside the `src/` directory.
  
  6. Execute the game giving the WAD file path as an argument, which is the file that contains the shareware version of the game. It is recommended to run first the setup executable to select the resolution of the window and other optional features.
  
The following bash script performs the steps described above:

```
#!/bin/sh

# Install dependencies
sudo -H apt-get install build-essential automake
sudo -H apt-get build-dep chocolate-doom

# Clone repo
git clone https://github.com/fabiangreffrath/crispy-doom.git
cd crispy-doom

# Checkout version
git checkout -b wb crispy-doom-3.0

# Generate configuration files
autoreconf -fiv

# Export environmental variables
export CFLAGS='-pg -no-pie'

# Generate makefiles
./configure

# Compile with maximum cores
make -j$(nproc)

# Downloads the .WAD and executes the game (ID Doom archive)
wget http://50.38.134.5/be_wads/doom1.wad
./src/crispy-doom-setup -iwad src/doom1.wad
```
  
You can perform manually the steps or, instead, run the script.
  
 
### Profiling DOOM (optional)

Once the game is executed and closed correctly, a new file called `gmon.out` is generated in the directory of the executable. This file is created during the execution of the game and includes information about the functions used by the game. This file could be read by the `gprof` tool which will display a flat profile.

The result will look like this(*):

![ ](https://github.com/leos313/DOOM_FPGA/blob/master/images/performace_no_hardware.png  "SW Performance")

**(*)PLEASE NOTE: depending on the DOOM version choosen, you may have different results. With Vanilla DOOM and Chocolate-DOOM, we have obtained different results. The same function in one case uses 38% of the CPU time and, in the other, the 68% of the CPU time. However, this is the function which is worth to be accelerated!!**
 
### Doom WITH Hardware Accelerator
 
To run the DOOM with hardware accelerators, we need to use the user-space drivers of SDSoC to send/receive data to/from the FPGA. The kernel-space drivers were already enabled when creating the system (The hack comes from the Xilinx’s documentation: “SDSoC Environment Platform Development Guide UG1146 (v2017.4) January 26, 2018” and was adapted for our purpose. In the document, it is used with Petalinux. However, the use of Petalinux is avoided in this work; it consists of creating a new node in the device tree that will compile and add the kernel module needed by the SDSoC user-space driver).

 1. Create the hardware bitstream:
 
 Open `Vivado SDSoC 2018.1` (or `Vivado SDSoC 2017.1`)  and import the files located in the folder `.../SDSoC_src` of this repository. Following any SDSoC tutorial, chose the target platform (in our case, the ZCU102). Chose the frequency (higher = faster while with a lower frequency, you may use less energy; see the ARC2020 paper for this analysis). The SDSoC will, so, perform the hardware synthesis and will create an SD image for you to test the TestBanch code we have also provided.
 
You can find the complete instruction for creating the hardware accelerators and the APIs to mange them with the file in `SDSoC_scr > README_SDSOC.md`. Use this [link](https://github.com/leos313/DOOM_FPGA/blob/master/SDSoC_src/README_SDSOC.md). **Please note: if you want to use different number of accelerators or a different working frequency (as we did for the ARC2020), you are free of doing it. If you want to test other solutions, you are also welcome! Let us know your improvements!!**

2. Now that you have the bitstream, you need to use them within the DOOM. The created bitstream is in the folder `project_sdsoc > sd_card > _sds > _p0_.bin`. There is just one bitstream with all the accelerators in the same floorplan.  

#### Re-compiling the game including HW accelerators

Now that the hardware function is checked in a Linux environment, the next step is to implement it in the Crispy-DOOM source code. To do this, another SDSoC utility is used, which is the creation of a C library that includes the software stub functions. Thanks to this, other applications can be compiled using these hardware
modules. Of course, while the bitstream is loaded in the FPGA.
In order to compile the Crispy-DOOM with the hardware functions, the following files must be added to the game source repository:

* The shared library file, which includes the stub function and its dependencies, such as the information of the hardware addresses.

The file are located in `project_sdsoc > Debug > _sds > swstub` and are `cf_stub.c`, `cf_stub.h`, `portinfo.c`, `portinfo.h`, `Stretch4x.cpp`, and the static library file `.a` (`libxlnk_stub.a` and `libdoom_hardware_v00.a`). **Please note that your names can be a bit different, depending on the project name you has used).**
 
 **...still under construction**
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 