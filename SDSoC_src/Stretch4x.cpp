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
