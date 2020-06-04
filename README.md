# Accelerating a Classic 3D Video Game (The DOOM) on Heterogeneous Reconfigurable MPSoCs

**The repo containing the game with HW accelerator on the FPGA can be found [here](https://github.com/leos313/crispy-doom).**

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

**The new version of DOOM (included HW accelerators bitstream) and all the instruction to compile and run it can be found [here](https://github.com/leos313/crispy-doom).**

# WAD file

In order to download the WAD file, we have used the new link [here](https://www.pc-freak.net/blog/doom-1-doom-2-doom-3-game-wad-files-for-download-playing-doom-on-debian-linux-via-freedoom-open-source-doom-engine/). Among all the version, the *doom1.wad* is the working file for us. The old link is not working anymore.

**Authors:**

Leonardo Suriano

David Lima
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 