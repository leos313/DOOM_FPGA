# README

In this repository, the scripts, patches and files to create a complete Linux-based OS for the evaluation board zcu102 by Xilinx are collected.
The structure of the folder:
```
.
├── desktop_image_zcu102.sh
├── patches
│   ├── devicetree
│   ├── kernel
│   ├── mali
│   └── pmu
├── README.md
└── scripts
    ├── 10_set_artico3.sh
    ├── 11_prepare_sd_card.sh
    ├── 1_check_dependencies.sh
    ├── 2_setup_environment.sh
    ├── 3_download_sources.sh
    ├── 4_build_devicetree.sh
    ├── 5_build_lowlevel_firmware.sh
    ├── 6_build_u_boot.sh
    ├── 7_generate_boot_image.sh
    ├── 8_build_kernel.sh
    └── 9_prepare_rootfs.sh

```
To build the system, just run the main script 'desktop_image_zcu102.sh'. At the end of the whole process, an SD image is ready to be burned on an empty SD card.
