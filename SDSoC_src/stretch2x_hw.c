/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch2x Hardware Accelerator project
 * 		File: - "stretch2x_hw.cpp"
 *
 * ----------------------------------------------------------------------------
 * Author:  David Lima (davidlimaastor@gmail.com)
 *
 *
 * TODO:
 *
 * CHANGELOG:
 *
 *---------------------------------------------------------------------------*/
#include "stretch2x_hw.h"


#pragma SDS data copy(src[0:(SRC_RANGE/fragments)], dest[0:(DEST_RANGE/fragments)])
#pragma SDS data access_pattern(src:SEQUENTIAL, dest:SEQUENTIAL)
/*---------------------------------------------------------------------------*/
void I_Stretch2x_HW(byte src[SRC_RANGE], byte dest[DEST_RANGE], byte fragments)
{
    int y, x, z;

    byte temp_value;

    // byte line_buffer[LINES][SCREENWIDTH];
    byte line_buffer[SCREENWIDTH];
#pragma HLS ARRAY_PARTITION variable=line_buffer block factor=2 dim=1

    /* For every 5 lines of src_buffer, 12 lines are written to dest_buffer */
    // (200 -> 960)
    for_height:for (y=0; y<(SCREENHEIGHT/fragments); y += 5)
    {
        /* Store the data in line 0 */
        src_line0:for (x=0; x<SCREENWIDTH; x++)
        {
#pragma HLS UNROLL factor=2
            line_buffer[x] = *src;
            src++;
        }

        /* Write 5 times the line */
        line_0: for (z=0; z<3; z++)
	    {
	        write_line0:for (x=0; x<SCREENWIDTH; x++)
	        {
	        	temp_value = line_buffer[x];
				*dest = temp_value;
				dest++;
				*dest = temp_value;
				dest++;
	        }
	    } // line_0


        /* Store the data in line 1 */
        src_line1:for (x=0; x<SCREENWIDTH; x++)
        {
#pragma HLS UNROLL factor=2			
            line_buffer[x] = *src;
            src++;
        }

        /* Write 5 times line 1 */
        line_1:for (z=0; z<3; z++)
        {
        	write_line1:for (x=0; x<SCREENWIDTH; x++)
	        {
            	temp_value = line_buffer[x];
				*dest = temp_value;
				dest++;
				*dest = temp_value;
				dest++;
	        }
        } // line 1


        /* Store the data in line 2 */
        src_line2:for (x=0; x<SCREENWIDTH; x++)
	    {
            line_buffer[x] = *src;
            src++;
	    }

        /* Write 5 times line 2 */
	    line_2:for (z=0; z<2; z++)
	    {
	        write_line2:for (x=0; x<SCREENWIDTH; x++)
	        {
            	temp_value = line_buffer[x];
				*dest = temp_value;
				dest++;
				*dest = temp_value;
				dest++;
	        }
	    } // line 2


        /* Store the data in line 3 */
	    src_line3:for (x=0; x<SCREENWIDTH; x++)
	    {
#pragma HLS UNROLL factor=2			
            line_buffer[x] = *src;
            src++;
	    }

        /* Write 5 times line 3 */
	    line_3:for (z=0; z<2; z++)
	    {
	        write_line3:for (x=0; x<SCREENWIDTH; x++)
            {
            	temp_value = line_buffer[x];
				*dest = temp_value;
				dest++;
				*dest = temp_value;
				dest++;
	        }
	    } // line_3


        /* Store the data in line 4 */
	    src_line4:for (x=0; x<SCREENWIDTH; x++)
	    {
#pragma HLS UNROLL factor=2						
            line_buffer[x] = *src;
            src++;
	    } // store_line_4

        /* Write 4 times line 4 */
        line_4:for (z=0; z<2; z++)
	    {
        	write_line4:for (x=0; x<SCREENWIDTH; x++)
	        {
            	temp_value = line_buffer[x];
				*dest = temp_value;
				dest++;
				*dest = temp_value;
				dest++;
	        }

         } // line_4

    } // loop_height
}

#include "cf_stub.h"
void _p0_I_Stretch2x_HW8_async_8(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW8_async_8(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW8_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW8.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW8_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW8_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW8.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_0);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW8.fragments), &fragments, 1, &_p0_request_2);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW8.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW8_async_8_num_dest, &_p0_request_1);


  cf_request_handle_t req_array[3] = {_p0_request_0, _p0_request_1, _p0_request_2};
  sds_insert_req( 8, req_array, 3);
}
void _p0_I_Stretch2x_HW7_async_7(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW7_async_7(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW7_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW7.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW7_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW7_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW7.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_3);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW7.fragments), &fragments, 1, &_p0_request_5);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW7.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW7_async_7_num_dest, &_p0_request_4);


  cf_request_handle_t req_array[3] = {_p0_request_3, _p0_request_4, _p0_request_5};
  sds_insert_req( 7, req_array, 3);
}
void _p0_I_Stretch2x_HW6_async_6(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW6_async_6(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW6_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW6.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW6_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW6_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW6.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_6);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW6.fragments), &fragments, 1, &_p0_request_8);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW6.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW6_async_6_num_dest, &_p0_request_7);


  cf_request_handle_t req_array[3] = {_p0_request_6, _p0_request_7, _p0_request_8};
  sds_insert_req( 6, req_array, 3);
}
void _p0_I_Stretch2x_HW5_async_5(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW5_async_5(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW5_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW5.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW5_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW5_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW5.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_9);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW5.fragments), &fragments, 1, &_p0_request_11);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW5.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW5_async_5_num_dest, &_p0_request_10);


  cf_request_handle_t req_array[3] = {_p0_request_9, _p0_request_10, _p0_request_11};
  sds_insert_req( 5, req_array, 3);
}
void _p0_I_Stretch2x_HW4_async_4(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW4_async_4(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW4_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW4.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW4_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW4_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW4.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_12);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW4.fragments), &fragments, 1, &_p0_request_14);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW4.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW4_async_4_num_dest, &_p0_request_13);


  cf_request_handle_t req_array[3] = {_p0_request_12, _p0_request_13, _p0_request_14};
  sds_insert_req( 4, req_array, 3);
}
void _p0_I_Stretch2x_HW3_async_3(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW3_async_3(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW3_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW3.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW3_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW3_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW3.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_15);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW3.fragments), &fragments, 1, &_p0_request_17);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW3.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW3_async_3_num_dest, &_p0_request_16);


  cf_request_handle_t req_array[3] = {_p0_request_15, _p0_request_16, _p0_request_17};
  sds_insert_req( 3, req_array, 3);
}
void _p0_I_Stretch2x_HW2_async_2(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW2_async_2(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW2_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW2.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW2_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW2_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW2.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_18);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW2.fragments), &fragments, 1, &_p0_request_20);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW2.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW2_async_2_num_dest, &_p0_request_19);


  cf_request_handle_t req_array[3] = {_p0_request_18, _p0_request_19, _p0_request_20};
  sds_insert_req( 2, req_array, 3);
}
void _p0_I_Stretch2x_HW1_async_1(byte src[256000], byte dest[1228800], byte fragments);
void _p0_I_Stretch2x_HW1_async_1(byte src[256000], byte dest[1228800], byte fragments)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_I_Stretch2x_HW1_cmd;
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW1.cmd_I_Stretch2x_HW), start_seq, 1 * sizeof(int), &_p0_swinst_I_Stretch2x_HW1_cmd);
  cf_wait(_p0_swinst_I_Stretch2x_HW1_cmd);


#ifdef SDS_DEBUG
  if (((((640)*(400))/fragments)) * 1 != 256000*1)
    printf("src of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
  if (((((1280)*(960))/fragments)) * 1 != 1228800*1)
    printf("dest of function I_Stretch2x_HW transfer size is different from declared size, system may hang!\n");
#endif

  cf_send_i(&(_p0_swinst_I_Stretch2x_HW1.src), src, ((((640)*(400))/fragments)) * 1, &_p0_request_21);
  cf_send_i(&(_p0_swinst_I_Stretch2x_HW1.fragments), &fragments, 1, &_p0_request_23);

  cf_receive_i(&(_p0_swinst_I_Stretch2x_HW1.dest), dest, ((((1280)*(960))/fragments)) * 1, &_p0_I_Stretch2x_HW1_async_1_num_dest, &_p0_request_22);


  cf_request_handle_t req_array[3] = {_p0_request_21, _p0_request_22, _p0_request_23};
  sds_insert_req( 1, req_array, 3);
}



