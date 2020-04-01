/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch4x Accelerator
 * 		File: - "stretch4x_hw.cpp"
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

#include "Stretch4x.h"

#pragma SDS data access_pattern(srcFrame:SEQUENTIAL, videoFrame:SEQUENTIAL)
#pragma SDS data copy(srcFrame[0:(hSizeInputSlice*wSizeInputSlice)], videoFrame[0:(hSizeInputSlice*wSizeInputSlice*4*4.8)])
// void I_Stretch4x_HW(byte src[64000], byte dest[1228800], byte fragments)
void Stretch4x(int hSizeInputSlice, int wSizeInputSlice, IN *srcFrame, OUT *videoFrame)
{

    int y, x, z;                       // Loop variables
    byte temp_value; 				   // To store the temporal value
    byte line_buffer[320]; // To store all the line

    /* For every 5 lines of srcFrame, 24 lines are written to video */
    // (200 -> 960)
    for_height:for (y=0; y<(hSizeInputSlice); y += 5)
    {
        /* Store the data in line 0 */
        src_line0:for (x=0; x<wSizeInputSlice; x++)
        {
#pragma HLS UNROLL factor=2
            line_buffer[x] = *srcFrame;
            srcFrame++;
        }

        /* Write 5 times the line */
        line_0: for (z=0; z<5; z++)
	    {
	        write_line0:for (x=0; x<wSizeInputSlice; x++)
	        {
	        	temp_value = line_buffer[x];
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
	        }
	    } // line_0


        /* Store the data in line 1 */
        srcFrame_line1:for (x=0; x<wSizeInputSlice; x++)
        {
#pragma HLS UNROLL factor=2
        	line_buffer[x] = *srcFrame;
            srcFrame++;
        }

        /* Write 5 times line 1 */
        line_1:for (z=0; z<5; z++)
        {
        	write_line1:for (x=0; x<wSizeInputSlice; x++)
	        {
            	temp_value = line_buffer[x];
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
	        }
        } // line 1


        /* Store the data in line 2 */
        srcFrame_line2:for (x=0; x<wSizeInputSlice; x++)
	    {
#pragma HLS UNROLL factor=2
        	line_buffer[x] = *srcFrame;
            srcFrame++;
	    }

        /* Write 5 times line 2 */
	    line_2:for (z=0; z<5; z++)
	    {
	        write_line2:for (x=0; x<wSizeInputSlice; x++)
	        {
            	temp_value = line_buffer[x];
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
	        }
	    } // line 2


        /* Store the data in line 3 */
	    srcFrame_line3:for (x=0; x<wSizeInputSlice; x++)
	    {
#pragma HLS UNROLL factor=2
	    	line_buffer[x] = *srcFrame;
            srcFrame++;
	    }

        /* Write 5 times line 3 */
	    line_3:for (z=0; z<5; z++)
	    {
	        write_line3:for (x=0; x<wSizeInputSlice; x++)
            {
            	temp_value = line_buffer[x];
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
	        }
	    } // line_3


        /* Store the data in line 4 */
	    srcFrame_line4:for (x=0; x<wSizeInputSlice; x++)
	    {
#pragma HLS UNROLL factor=2
	    	line_buffer[x] = *srcFrame;
            srcFrame++;
	    } // store_line_4

        /* Write 4 times line 4 */
        line_4:for (z=0; z<4; z++)
	    {
        	write_line4:for (x=0; x<wSizeInputSlice; x++)
	        {
            	temp_value = line_buffer[x];
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
				*videoFrame = temp_value;
				videoFrame++;
	        }

         } // line_4

    } // loop_height

}

#include "cf_stub.h"
void _p0_Stretch4x8_async_8(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x8_async_8(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x8_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x8.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x8_cmd);
  cf_wait(_p0_swinst_Stretch4x8_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x8.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_0);
  cf_send_i(&(_p0_swinst_Stretch4x8.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_1);
  cf_send_i(&(_p0_swinst_Stretch4x8.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_2);

  cf_receive_i(&(_p0_swinst_Stretch4x8.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x8_async_8_num_videoFrame, &_p0_request_3);


  cf_request_handle_t req_array[4] = {_p0_request_0, _p0_request_1, _p0_request_2, _p0_request_3};
  sds_insert_req( 8, req_array, 4);
}
void _p0_Stretch4x7_async_7(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x7_async_7(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x7_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x7.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x7_cmd);
  cf_wait(_p0_swinst_Stretch4x7_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x7.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_4);
  cf_send_i(&(_p0_swinst_Stretch4x7.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_5);
  cf_send_i(&(_p0_swinst_Stretch4x7.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_6);

  cf_receive_i(&(_p0_swinst_Stretch4x7.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x7_async_7_num_videoFrame, &_p0_request_7);


  cf_request_handle_t req_array[4] = {_p0_request_4, _p0_request_5, _p0_request_6, _p0_request_7};
  sds_insert_req( 7, req_array, 4);
}
void _p0_Stretch4x6_async_6(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x6_async_6(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x6_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x6.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x6_cmd);
  cf_wait(_p0_swinst_Stretch4x6_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x6.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_8);
  cf_send_i(&(_p0_swinst_Stretch4x6.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_9);
  cf_send_i(&(_p0_swinst_Stretch4x6.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_10);

  cf_receive_i(&(_p0_swinst_Stretch4x6.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x6_async_6_num_videoFrame, &_p0_request_11);


  cf_request_handle_t req_array[4] = {_p0_request_8, _p0_request_9, _p0_request_10, _p0_request_11};
  sds_insert_req( 6, req_array, 4);
}
void _p0_Stretch4x5_async_5(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x5_async_5(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x5_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x5.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x5_cmd);
  cf_wait(_p0_swinst_Stretch4x5_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x5.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_12);
  cf_send_i(&(_p0_swinst_Stretch4x5.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_13);
  cf_send_i(&(_p0_swinst_Stretch4x5.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_14);

  cf_receive_i(&(_p0_swinst_Stretch4x5.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x5_async_5_num_videoFrame, &_p0_request_15);


  cf_request_handle_t req_array[4] = {_p0_request_12, _p0_request_13, _p0_request_14, _p0_request_15};
  sds_insert_req( 5, req_array, 4);
}
void _p0_Stretch4x4_async_4(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x4_async_4(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x4_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x4.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x4_cmd);
  cf_wait(_p0_swinst_Stretch4x4_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x4.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_16);
  cf_send_i(&(_p0_swinst_Stretch4x4.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_17);
  cf_send_i(&(_p0_swinst_Stretch4x4.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_18);

  cf_receive_i(&(_p0_swinst_Stretch4x4.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x4_async_4_num_videoFrame, &_p0_request_19);


  cf_request_handle_t req_array[4] = {_p0_request_16, _p0_request_17, _p0_request_18, _p0_request_19};
  sds_insert_req( 4, req_array, 4);
}
void _p0_Stretch4x3_async_3(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x3_async_3(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x3_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x3.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x3_cmd);
  cf_wait(_p0_swinst_Stretch4x3_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x3.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_20);
  cf_send_i(&(_p0_swinst_Stretch4x3.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_21);
  cf_send_i(&(_p0_swinst_Stretch4x3.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_22);

  cf_receive_i(&(_p0_swinst_Stretch4x3.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x3_async_3_num_videoFrame, &_p0_request_23);


  cf_request_handle_t req_array[4] = {_p0_request_20, _p0_request_21, _p0_request_22, _p0_request_23};
  sds_insert_req( 3, req_array, 4);
}
void _p0_Stretch4x2_async_2(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x2_async_2(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x2_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x2.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x2_cmd);
  cf_wait(_p0_swinst_Stretch4x2_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x2.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_24);
  cf_send_i(&(_p0_swinst_Stretch4x2.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_25);
  cf_send_i(&(_p0_swinst_Stretch4x2.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_26);

  cf_receive_i(&(_p0_swinst_Stretch4x2.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x2_async_2_num_videoFrame, &_p0_request_27);


  cf_request_handle_t req_array[4] = {_p0_request_24, _p0_request_25, _p0_request_26, _p0_request_27};
  sds_insert_req( 2, req_array, 4);
}
void _p0_Stretch4x1_async_1(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame);
void _p0_Stretch4x1_async_1(int hSizeInputSlice, int wSizeInputSlice, IN * srcFrame, OUT * videoFrame)
{
  switch_to_next_partition(0);
  int start_seq[1];
  start_seq[0] = 0;
  cf_request_handle_t _p0_swinst_Stretch4x1_cmd;
  cf_send_i(&(_p0_swinst_Stretch4x1.cmd_Stretch4x), start_seq, 1 * sizeof(int), &_p0_swinst_Stretch4x1_cmd);
  cf_wait(_p0_swinst_Stretch4x1_cmd);

  cf_send_i(&(_p0_swinst_Stretch4x1.hSizeInputSlice), &hSizeInputSlice, 4, &_p0_request_28);
  cf_send_i(&(_p0_swinst_Stretch4x1.wSizeInputSlice), &wSizeInputSlice, 4, &_p0_request_29);
  cf_send_i(&(_p0_swinst_Stretch4x1.srcFrame), srcFrame, ((hSizeInputSlice*wSizeInputSlice)) * 1, &_p0_request_30);

  cf_receive_i(&(_p0_swinst_Stretch4x1.videoFrame), videoFrame, ((hSizeInputSlice*wSizeInputSlice*4*4.8)) * 1, &_p0_Stretch4x1_async_1_num_videoFrame, &_p0_request_31);


  cf_request_handle_t req_array[4] = {_p0_request_28, _p0_request_29, _p0_request_30, _p0_request_31};
  sds_insert_req( 1, req_array, 4);
}


