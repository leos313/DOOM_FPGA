#ifndef _SDS_PORTINFO_H
#define _SDS_PORTINFO_H
/* File: /home/leonardo/Documents/DOOM/doom_hardware_v02/Debug/_sds/p0/.cf_work/portinfo.h */
#ifdef __cplusplus
extern "C" {
#endif

struct _p0_swblk_Stretch4x {
  cf_port_send_t cmd_Stretch4x;
  cf_port_send_t hSizeInputSlice;
  cf_port_send_t wSizeInputSlice;
  cf_port_send_t srcFrame;
  cf_port_receive_t videoFrame;
};

extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x8;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x7;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x6;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x5;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x4;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x3;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x2;
extern struct _p0_swblk_Stretch4x _p0_swinst_Stretch4x1;
void _p0_cf_framework_open(int);
void _p0_cf_framework_close(int);

#ifdef __cplusplus
};
#endif
#ifdef __cplusplus
extern "C" {
#endif
void switch_to_next_partition(int);
void init_first_partition();
void close_last_partition();
#ifdef __cplusplus
};
#endif /* extern "C" */
#endif /* _SDS_PORTINFO_H_ */
