/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch4x Accelerator project
 * 		File: - "stretch4x_hw.h"
 *
 * ----------------------------------------------------------------------------
 * Author:  David Lima (davidlimaastor@gmail.com)
 *
 *
 * TODO: Check .cpp file to see TODOs
 *
 * CHANGELOG:
 *
 *---------------------------------------------------------------------------*/
#ifndef STRETCH4_HW_H
#define STRETCH4_HW_H

#include "doomtype.h"

/*------------------------- Constant Definitions ----------------------------*/
/*
 *  Screen resolutions
 */
// #define SCREENWIDTH  (320) // Screen width
// #define SCREENHEIGHT (200) // Screen height
// #define w_out        (1280)// Output width
// #define h_out        (960) // output height
// #define LINES		 (5)   // lines written
typedef byte IN;
typedef byte OUT;


/*----------------------- Functions prototypes ------------------------------*/
void Stretch4x(int hSizeInputSlice, int wSizeInputSlice, IN *srcFrame, OUT *videoFrame);


#endif // STRETCH4X_HW_H
