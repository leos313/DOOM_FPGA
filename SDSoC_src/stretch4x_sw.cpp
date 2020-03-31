/* -----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)---------------------------
 * -----------------------------------------------------------------------------
 * 	Stretch4x Accelerator project
 * 		File: - "stretch4x_sw.cpp"
 *
 * -----------------------------------------------------------------------------
 * Author:  David Lima (davidlimaastor@gmail.com)
 *
 *
 * TODO:
 *
 * CHANGELOG:
 *
 *----------------------------------------------------------------------------*/
#include "stretch4x_sw.h"
#include <iostream>

// Should be I_VideoBuffer
extern byte *src_buffer;
extern byte *dest_buffer;
extern int dest_pitch;

/*---------------------------------------------------------------------------*/
/*-
* Copy the line four times from source to destination.
*
* @param	*dest, pointer to destination buffer.
*
* @param    *src, pointer to source buffer.
*
* @note		Took from chocolate-doom v2.3 source (i_scale.c)
*
*----------------------------------------------------------------------------*/
static inline void WriteLine4x(byte *dest, byte *src)
{
    int x;

    for (x=0; x<SCREENWIDTH; ++x)
    {
        dest[0] = *src;
        dest[1] = *src;
        dest[2] = *src;
        dest[3] = *src;
        dest += 4;
        ++src;
    }

} // WriteLine4x


/*---------------------------------------------------------------------------*/
/*-
* Software implementation of the stretch4x function. It uses pointers to memory
* buffer where are stored the input and output data.
*
* @param	x1, x2, y1, y2, static arguments related with the screen points.
* 			When the full screen is enabled, x1=0, x2=320, y1=0, y2=200.

* @note		Took from chocolate-doom v2.3 source (i_scale.c)
*
*----------------------------------------------------------------------------*/
boolean I_Stretch4x_SW(int x1, int y1, int x2, int y2)
{
    byte *bufp, *screenp;
    int y;

    /* Need to byte-copy from buffer into the screen buffer */
    bufp = src_buffer + y1 * SCREENWIDTH + x1;

    screenp = (byte *) dest_buffer + y1 * dest_pitch + x1;

    /* For every 5 lines of src_buffer, 24 lines are written to dest_buffer. */
    // (200 -> 960)
    for (y=0; y<SCREENHEIGHT; y += 5)
    {
        // 100% line 0
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 0
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 0
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 0
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 90% line 0, 20% line 1
        WriteLine4x(screenp, bufp);
        //WriteBlendedLine4x(screenp, bufp + SCREENWIDTH, bufp);
        //  , stretch_tables[0]);
        screenp += dest_pitch;
        bufp += SCREENWIDTH;

        // 100% line 1
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 1
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 1
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 1
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 60% line 1, 40% line 2
        WriteLine4x(screenp, bufp);
        //WriteBlendedLine4x(screenp, bufp + SCREENWIDTH, bufp);
        //, stretch_tables[1]);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 2
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 2
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 2
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 2
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 40% line 2, 60% line 3
        WriteLine4x(screenp, bufp);
        //WriteBlendedLine4x(screenp, bufp, bufp + SCREENWIDTH);
        //, stretch_tables[1]);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 3
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 3
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 3
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 3
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 20% line 3, 80% line 4
        WriteLine4x(screenp, bufp);
        //WriteBlendedLine4x(screenp, bufp, bufp + SCREENWIDTH);
        //, stretch_tables[0]);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 4
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 4
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 4
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 4
        WriteLine4x(screenp, bufp);
        screenp += dest_pitch; bufp += SCREENWIDTH;
    }

    return true;

} // I_Stretch4x_SW
