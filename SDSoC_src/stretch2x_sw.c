/* -----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)---------------------------
 * -----------------------------------------------------------------------------
 * 	Stretch2x Hardware Accelerator project
 * 		File: - "stretch2x_sw.cpp"
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
#include "stretch2x_sw.h"

// Should be I_VideoBuffer
extern byte *src_buffer;
extern byte *dest_buffer;
extern int dest_pitch;


static inline void WriteLine2x(byte *dest, byte *src)
{
    int x;

    for (x=0; x<SCREENWIDTH; ++x)
    {
        dest[0] = *src;
        dest[1] = *src;
        dest += 2;
        ++src;
    }
}


void I_Stretch2x_SW(int x1, int y1, int x2, int y2)
{
    byte *bufp, *screenp;
    int y;

    // Need to byte-copy from buffer into the screen buffer
    bufp = src_buffer;// + y1 * SCREENWIDTH + x1;
    //bufp = src_buffer;

    screenp = (byte *) dest_buffer;// + y1 * dest_pitch + x1;
    //screenp = (byte *) dest_buffer;

    // For every 5 lines of src_buffer, 12 lines are written to dest_buffer.
    // (200 -> 960)
    for (y=0; y<(SCREENHEIGHT); y += 5)
    {
        // 100% line 0
    	WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 0
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;bufp += SCREENWIDTH;

        // 100% line 1
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 1
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        WriteLine2x(screenp, bufp);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 2
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        WriteLine2x(screenp, bufp);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 3
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        WriteLine2x(screenp, bufp);
        screenp += dest_pitch; bufp += SCREENWIDTH;

        // 100% line 4
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch;

        // 100% line 4
        WriteLine2x(screenp, bufp);
        screenp += dest_pitch; bufp += SCREENWIDTH;
    }

} // I_Stretch4x_SW
