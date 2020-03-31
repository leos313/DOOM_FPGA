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
