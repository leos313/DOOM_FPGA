/* File: /home/leonardo/Documents/DOOM/doom_hardware_v02/Debug/_sds/p0/.cf_work/portinfo.c */
#include "cf_lib.h"
#include "cf_request.h"
#include "sds_lib.h"
#include "sds_trace.h"
#include "portinfo.h"
#include "stdio.h"  // for printf
#include "xlnk_core_cf.h"
#include "accel_info.h"
#include "axi_dma_sg_dm.h"
#include "axi_lite_dm.h"
#include "sysport_info.h"

sysport_info_t _sds_sysport_p0_ps_e_S_AXI_HP0_FPD = {
  .name = "ps_e_S_AXI_HP0_FPD",
  .id = 1,
  .address_space = 0,
  .cmd_type = sysport_commands_type_non_coherent,
};

sysport_info_t _sds_sysport_p0_ps_e_S_AXI_HP1_FPD = {
  .name = "ps_e_S_AXI_HP1_FPD",
  .id = 2,
  .address_space = 0,
  .cmd_type = sysport_commands_type_non_coherent,
};

sysport_info_t _sds_sysport_p0_ps_e_S_AXI_HP2_FPD = {
  .name = "ps_e_S_AXI_HP2_FPD",
  .id = 3,
  .address_space = 0,
  .cmd_type = sysport_commands_type_non_coherent,
};

sysport_info_t _sds_sysport_p0_ps_e_S_AXI_HP3_FPD = {
  .name = "ps_e_S_AXI_HP3_FPD",
  .id = 4,
  .address_space = 0,
  .cmd_type = sysport_commands_type_non_coherent,
};

accel_info_t _sds__p0_Stretch4x8 = {
  .device_id = 0,
  .phys_base_addr = 0xa0070000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x8",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x7 = {
  .device_id = 1,
  .phys_base_addr = 0xa0060000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x7",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x6 = {
  .device_id = 2,
  .phys_base_addr = 0xa0050000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x6",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x5 = {
  .device_id = 3,
  .phys_base_addr = 0xa0040000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x5",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x4 = {
  .device_id = 4,
  .phys_base_addr = 0xa0030000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x4",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x3 = {
  .device_id = 5,
  .phys_base_addr = 0xa0020000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x3",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x2 = {
  .device_id = 6,
  .phys_base_addr = 0xa0010000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x2",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

accel_info_t _sds__p0_Stretch4x1 = {
  .device_id = 7,
  .phys_base_addr = 0xa0000000,
  .addr_range = 0x10000,
  .func_name = "Stretch4x1",
  .ip_type = "axis_acc_adapter",
  .irq = 0,
};

axi_dma_sg_info_t _p0_dm_0 = {
  .name = "dm_0",
  .phys_base_addr = 0xa0080000,
  .addr_range = 0x10000,
  .seq_num = 0,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_0:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = 89,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP3_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_0:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = 90,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP3_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_1 = {
  .name = "dm_1",
  .phys_base_addr = 0xa0090000,
  .addr_range = 0x10000,
  .seq_num = 1,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_1:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = 91,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP2_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_1:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = 92,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP2_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_2 = {
  .name = "dm_2",
  .phys_base_addr = 0xa00a0000,
  .addr_range = 0x10000,
  .seq_num = 2,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_2:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = 93,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP1_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_2:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = 94,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP1_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_3 = {
  .name = "dm_3",
  .phys_base_addr = 0xa00b0000,
  .addr_range = 0x10000,
  .seq_num = 3,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_3:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = 95,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP0_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_3:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = 96,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP0_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_4 = {
  .name = "dm_4",
  .phys_base_addr = 0xa00c0000,
  .addr_range = 0x10000,
  .seq_num = 4,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_4:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = -1,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP3_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_4:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = -1,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP3_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_5 = {
  .name = "dm_5",
  .phys_base_addr = 0xa00d0000,
  .addr_range = 0x10000,
  .seq_num = 5,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_5:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = -1,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP2_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_5:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = -1,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP2_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_6 = {
  .name = "dm_6",
  .phys_base_addr = 0xa00e0000,
  .addr_range = 0x10000,
  .seq_num = 6,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_6:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = -1,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP1_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_6:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = -1,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP1_FPD,
  .chan_data[1].data_width = 64,
};

axi_dma_sg_info_t _p0_dm_7 = {
  .name = "dm_7",
  .phys_base_addr = 0xa00f0000,
  .addr_range = 0x10000,
  .seq_num = 7,
  .chan_data[0].valid = 1,
  .chan_data[0].name = "dm_7:0",
  .chan_data[0].dir = XLNK_DMA_TO_DEV,
  .chan_data[0].irq = -1,
  .chan_data[0].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP0_FPD,
  .chan_data[0].data_width = 64,
  .chan_data[1].valid = 1,
  .chan_data[1].name = "dm_7:1",
  .chan_data[1].dir = XLNK_DMA_FROM_DEV,
  .chan_data[1].irq = -1,
  .chan_data[1].data_sysport = &_sds_sysport_p0_ps_e_S_AXI_HP0_FPD,
  .chan_data[1].data_width = 64,
};

int _p0_swinst_Stretch4x8_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x8_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0070000,
  .data_reg_offset = _p0_swinst_Stretch4x8_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x8,
};

int _p0_swinst_Stretch4x8_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x8_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0070000,
  .data_reg_offset = _p0_swinst_Stretch4x8_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x8,
};

int _p0_swinst_Stretch4x8_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x8_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0070000,
  .data_reg_offset = _p0_swinst_Stretch4x8_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x8,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x8_srcFrame_info = {
  .dma_info = &_p0_dm_0,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x8_videoFrame_info = {
  .dma_info = &_p0_dm_7,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x7_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x7_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0060000,
  .data_reg_offset = _p0_swinst_Stretch4x7_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x7,
};

int _p0_swinst_Stretch4x7_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x7_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0060000,
  .data_reg_offset = _p0_swinst_Stretch4x7_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x7,
};

int _p0_swinst_Stretch4x7_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x7_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0060000,
  .data_reg_offset = _p0_swinst_Stretch4x7_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x7,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x7_srcFrame_info = {
  .dma_info = &_p0_dm_1,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x7_videoFrame_info = {
  .dma_info = &_p0_dm_6,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x6_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x6_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0050000,
  .data_reg_offset = _p0_swinst_Stretch4x6_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x6,
};

int _p0_swinst_Stretch4x6_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x6_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0050000,
  .data_reg_offset = _p0_swinst_Stretch4x6_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x6,
};

int _p0_swinst_Stretch4x6_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x6_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0050000,
  .data_reg_offset = _p0_swinst_Stretch4x6_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x6,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x6_srcFrame_info = {
  .dma_info = &_p0_dm_2,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x6_videoFrame_info = {
  .dma_info = &_p0_dm_5,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x5_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x5_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0040000,
  .data_reg_offset = _p0_swinst_Stretch4x5_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x5,
};

int _p0_swinst_Stretch4x5_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x5_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0040000,
  .data_reg_offset = _p0_swinst_Stretch4x5_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x5,
};

int _p0_swinst_Stretch4x5_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x5_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0040000,
  .data_reg_offset = _p0_swinst_Stretch4x5_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x5,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x5_srcFrame_info = {
  .dma_info = &_p0_dm_3,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x5_videoFrame_info = {
  .dma_info = &_p0_dm_4,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x4_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x4_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0030000,
  .data_reg_offset = _p0_swinst_Stretch4x4_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x4,
};

int _p0_swinst_Stretch4x4_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x4_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0030000,
  .data_reg_offset = _p0_swinst_Stretch4x4_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x4,
};

int _p0_swinst_Stretch4x4_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x4_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0030000,
  .data_reg_offset = _p0_swinst_Stretch4x4_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x4,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x4_srcFrame_info = {
  .dma_info = &_p0_dm_4,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x4_videoFrame_info = {
  .dma_info = &_p0_dm_3,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x3_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x3_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0020000,
  .data_reg_offset = _p0_swinst_Stretch4x3_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x3,
};

int _p0_swinst_Stretch4x3_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x3_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0020000,
  .data_reg_offset = _p0_swinst_Stretch4x3_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x3,
};

int _p0_swinst_Stretch4x3_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x3_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0020000,
  .data_reg_offset = _p0_swinst_Stretch4x3_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x3,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x3_srcFrame_info = {
  .dma_info = &_p0_dm_5,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x3_videoFrame_info = {
  .dma_info = &_p0_dm_2,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x2_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x2_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0010000,
  .data_reg_offset = _p0_swinst_Stretch4x2_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x2,
};

int _p0_swinst_Stretch4x2_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x2_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0010000,
  .data_reg_offset = _p0_swinst_Stretch4x2_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x2,
};

int _p0_swinst_Stretch4x2_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x2_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0010000,
  .data_reg_offset = _p0_swinst_Stretch4x2_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x2,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x2_srcFrame_info = {
  .dma_info = &_p0_dm_6,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x2_videoFrame_info = {
  .dma_info = &_p0_dm_1,
  .dma_channel = 1,
  .port_id = 0,
};

int _p0_swinst_Stretch4x1_cmd_Stretch4x_sg_list[] = {0x8};

axi_lite_info_t _p0_swinst_Stretch4x1_cmd_Stretch4x_info = {
  .phys_base_addr = 0xa0000000,
  .data_reg_offset = _p0_swinst_Stretch4x1_cmd_Stretch4x_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x0,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_SG |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NOCHECK) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_NOCHECK),
  .acc_info = &_sds__p0_Stretch4x1,
};

int _p0_swinst_Stretch4x1_hSizeInputSlice_sg_list[] = {0xc};

axi_lite_info_t _p0_swinst_Stretch4x1_hSizeInputSlice_info = {
  .phys_base_addr = 0xa0000000,
  .data_reg_offset = _p0_swinst_Stretch4x1_hSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x40c,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x1,
};

int _p0_swinst_Stretch4x1_wSizeInputSlice_sg_list[] = {0x10};

axi_lite_info_t _p0_swinst_Stretch4x1_wSizeInputSlice_info = {
  .phys_base_addr = 0xa0000000,
  .data_reg_offset = _p0_swinst_Stretch4x1_wSizeInputSlice_sg_list,
  .data_reg_sg_size = 1,
  .write_status_reg_offset = 0x410,
  .read_status_reg_offset = 0x0,
  .config = XLNK_AXI_LITE_KEYHOLE |
    XLNK_AXI_LITE_STAT_REG_READ(XLNK_AXI_LITE_STAT_REG_NONE) |
    XLNK_AXI_LITE_STAT_REG_WRITE(XLNK_AXI_LITE_STAT_REG_QUEUING),
  .acc_info = &_sds__p0_Stretch4x1,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x1_srcFrame_info = {
  .dma_info = &_p0_dm_7,
  .dma_channel = 0,
  .port_id = 0,
};

axi_dma_sg_transaction_info_t _p0_swinst_Stretch4x1_videoFrame_info = {
  .dma_info = &_p0_dm_0,
  .dma_channel = 1,
  .port_id = 0,
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x8 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x8_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x8_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x8_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x8_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x8_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x7 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x7_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x7_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x7_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x7_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x7_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x6 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x6_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x6_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x6_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x6_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x6_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x5 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x5_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x5_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x5_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x5_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x5_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x4 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x4_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x4_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x4_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x4_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x4_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x3 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x3_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x3_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x3_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x3_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x3_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x2 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x2_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x2_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x2_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x2_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x2_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x1 = {
  .cmd_Stretch4x = { .base = { .channel_info = &_p0_swinst_Stretch4x1_cmd_Stretch4x_info}, 
    .send_i = &axi_lite_send },
  .hSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x1_hSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .wSizeInputSlice = { .base = { .channel_info = &_p0_swinst_Stretch4x1_wSizeInputSlice_info}, 
    .send_i = &axi_lite_send },
  .srcFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x1_srcFrame_info}, 
    .send_i = &axi_dma_sg_send_i },
  .videoFrame = { .base = { .channel_info = &_p0_swinst_Stretch4x1_videoFrame_info}, 
    .receive_ref_i = 0,
    .receive_i = &axi_dma_sg_recv_i },
};

extern void pfm_hook_init();
extern void pfm_hook_shutdown();
void _p0_cf_framework_open(int first)
{
  int xlnk_init_done;
  cf_context_init();
  xlnkCounterMap(1199988000);
  xlnk_init_done = cf_xlnk_open(first);
  if (!xlnk_init_done) {
    pfm_hook_init();
    cf_xlnk_init(first);
  } else if (xlnk_init_done < 0) {
    fprintf(stderr, "ERROR: unable to open xlnk\n");
    exit(-1);
  }
  cf_get_current_context();
  sysport_open(&_sds_sysport_p0_ps_e_S_AXI_HP0_FPD);
  sysport_open(&_sds_sysport_p0_ps_e_S_AXI_HP1_FPD);
  sysport_open(&_sds_sysport_p0_ps_e_S_AXI_HP2_FPD);
  sysport_open(&_sds_sysport_p0_ps_e_S_AXI_HP3_FPD);
  axi_dma_sg_open(&_p0_dm_0);
  axi_dma_sg_open(&_p0_dm_1);
  axi_dma_sg_open(&_p0_dm_2);
  axi_dma_sg_open(&_p0_dm_3);
  axi_dma_sg_open(&_p0_dm_4);
  axi_dma_sg_open(&_p0_dm_5);
  axi_dma_sg_open(&_p0_dm_6);
  axi_dma_sg_open(&_p0_dm_7);
  axi_lite_open(&_p0_swinst_Stretch4x8_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x8_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x8_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x7_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x7_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x7_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x6_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x6_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x6_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x5_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x5_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x5_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x4_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x4_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x4_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x3_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x3_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x3_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x2_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x2_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x2_wSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x1_cmd_Stretch4x_info);
  axi_lite_open(&_p0_swinst_Stretch4x1_hSizeInputSlice_info);
  axi_lite_open(&_p0_swinst_Stretch4x1_wSizeInputSlice_info);
  _sds__p0_Stretch4x8.arg_dm_id[0] = _p0_swinst_Stretch4x8_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x8.arg_dm_id[1] = _p0_swinst_Stretch4x8_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x8.arg_dm_id[2] = _p0_swinst_Stretch4x8_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x8.arg_dm_id[3] = _p0_swinst_Stretch4x8_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x8_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x8.arg_dm_id[4] = _p0_swinst_Stretch4x8_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x8_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x8.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x8);
  _sds__p0_Stretch4x7.arg_dm_id[0] = _p0_swinst_Stretch4x7_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x7.arg_dm_id[1] = _p0_swinst_Stretch4x7_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x7.arg_dm_id[2] = _p0_swinst_Stretch4x7_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x7.arg_dm_id[3] = _p0_swinst_Stretch4x7_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x7_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x7.arg_dm_id[4] = _p0_swinst_Stretch4x7_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x7_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x7.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x7);
  _sds__p0_Stretch4x6.arg_dm_id[0] = _p0_swinst_Stretch4x6_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x6.arg_dm_id[1] = _p0_swinst_Stretch4x6_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x6.arg_dm_id[2] = _p0_swinst_Stretch4x6_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x6.arg_dm_id[3] = _p0_swinst_Stretch4x6_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x6_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x6.arg_dm_id[4] = _p0_swinst_Stretch4x6_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x6_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x6.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x6);
  _sds__p0_Stretch4x5.arg_dm_id[0] = _p0_swinst_Stretch4x5_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x5.arg_dm_id[1] = _p0_swinst_Stretch4x5_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x5.arg_dm_id[2] = _p0_swinst_Stretch4x5_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x5.arg_dm_id[3] = _p0_swinst_Stretch4x5_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x5_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x5.arg_dm_id[4] = _p0_swinst_Stretch4x5_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x5_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x5.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x5);
  _sds__p0_Stretch4x4.arg_dm_id[0] = _p0_swinst_Stretch4x4_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x4.arg_dm_id[1] = _p0_swinst_Stretch4x4_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x4.arg_dm_id[2] = _p0_swinst_Stretch4x4_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x4.arg_dm_id[3] = _p0_swinst_Stretch4x4_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x4_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x4.arg_dm_id[4] = _p0_swinst_Stretch4x4_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x4_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x4.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x4);
  _sds__p0_Stretch4x3.arg_dm_id[0] = _p0_swinst_Stretch4x3_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x3.arg_dm_id[1] = _p0_swinst_Stretch4x3_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x3.arg_dm_id[2] = _p0_swinst_Stretch4x3_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x3.arg_dm_id[3] = _p0_swinst_Stretch4x3_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x3_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x3.arg_dm_id[4] = _p0_swinst_Stretch4x3_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x3_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x3.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x3);
  _sds__p0_Stretch4x2.arg_dm_id[0] = _p0_swinst_Stretch4x2_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x2.arg_dm_id[1] = _p0_swinst_Stretch4x2_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x2.arg_dm_id[2] = _p0_swinst_Stretch4x2_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x2.arg_dm_id[3] = _p0_swinst_Stretch4x2_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x2_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x2.arg_dm_id[4] = _p0_swinst_Stretch4x2_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x2_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x2.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x2);
  _sds__p0_Stretch4x1.arg_dm_id[0] = _p0_swinst_Stretch4x1_cmd_Stretch4x_info.dm_id;
  _sds__p0_Stretch4x1.arg_dm_id[1] = _p0_swinst_Stretch4x1_hSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x1.arg_dm_id[2] = _p0_swinst_Stretch4x1_wSizeInputSlice_info.dm_id;
  _sds__p0_Stretch4x1.arg_dm_id[3] = _p0_swinst_Stretch4x1_srcFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x1_srcFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x1.arg_dm_id[4] = _p0_swinst_Stretch4x1_videoFrame_info.dma_info->chan_data[_p0_swinst_Stretch4x1_videoFrame_info.dma_channel].dm_id;
  _sds__p0_Stretch4x1.arg_dm_id_count = 5;
  accel_open(&_sds__p0_Stretch4x1);
}

void _p0_cf_framework_close(int last)
{
  accel_close(&_sds__p0_Stretch4x8);
  accel_close(&_sds__p0_Stretch4x7);
  accel_close(&_sds__p0_Stretch4x6);
  accel_close(&_sds__p0_Stretch4x5);
  accel_close(&_sds__p0_Stretch4x4);
  accel_close(&_sds__p0_Stretch4x3);
  accel_close(&_sds__p0_Stretch4x2);
  accel_close(&_sds__p0_Stretch4x1);
  axi_dma_sg_close(&_p0_dm_0);
  axi_dma_sg_close(&_p0_dm_1);
  axi_dma_sg_close(&_p0_dm_2);
  axi_dma_sg_close(&_p0_dm_3);
  axi_dma_sg_close(&_p0_dm_4);
  axi_dma_sg_close(&_p0_dm_5);
  axi_dma_sg_close(&_p0_dm_6);
  axi_dma_sg_close(&_p0_dm_7);
  axi_lite_close(&_p0_swinst_Stretch4x8_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x8_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x8_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x7_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x7_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x7_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x6_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x6_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x6_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x5_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x5_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x5_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x4_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x4_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x4_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x3_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x3_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x3_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x2_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x2_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x2_wSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x1_cmd_Stretch4x_info);
  axi_lite_close(&_p0_swinst_Stretch4x1_hSizeInputSlice_info);
  axi_lite_close(&_p0_swinst_Stretch4x1_wSizeInputSlice_info);
  sysport_close(&_sds_sysport_p0_ps_e_S_AXI_HP0_FPD);
  sysport_close(&_sds_sysport_p0_ps_e_S_AXI_HP1_FPD);
  sysport_close(&_sds_sysport_p0_ps_e_S_AXI_HP2_FPD);
  sysport_close(&_sds_sysport_p0_ps_e_S_AXI_HP3_FPD);
  pfm_hook_shutdown();
  xlnkClose(last, NULL);
}

#define TOTAL_PARTITIONS 1
int current_partition_num = 0;
struct {
  void (*open)(int);
  void (*close)(int);
}

_ptable[TOTAL_PARTITIONS]  = {
    {.open = &_p0_cf_framework_open, .close= &_p0_cf_framework_close}, 
};

void switch_to_next_partition(int partition_num)
{
#ifdef __linux__
  if (current_partition_num != partition_num) {
    _ptable[current_partition_num].close(0);
    char buf[128];
    sprintf(buf, "cat /mnt/_sds/_p%d_.bin > /dev/xdevcfg", partition_num);
    system(buf);
    _ptable[partition_num].open(0);
    current_partition_num = partition_num;
  }
#endif
}

void init_first_partition() __attribute__ ((constructor));
void close_last_partition() __attribute__ ((destructor));
void init_first_partition()
{
    current_partition_num = 0;
    _ptable[current_partition_num].open(1);

    sds_trace_setup();
}


void close_last_partition()
{
#ifdef PERF_EST
    apf_perf_estimation_exit();
#endif
    sds_trace_cleanup();
    _ptable[current_partition_num].close(1);
    current_partition_num = 0;
}

