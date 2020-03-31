/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch2x Hardware Accelerator project
 * 		File: - "stretch2x_hw.h"
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
#ifndef STRETCH2_HW_H
#define STRETCH2_HW_H

#include <inttypes.h>

typedef uint8_t byte;


/*------------------------- Constant Definitions ----------------------------*/
/*
 *  Screen resolutions
 */
#define SCREENWIDTH  (640) // Screen width
#define SCREENHEIGHT (400) // Screen height

#define LINES 		(5)

#define INPUT_WIDTH 	(640)
#define INPUT_HEIGHT 	(400)

#define OUTPUT_WIDTH 	(1280)
#define OUTPUT_HEIGHT 	(960)

#define SRC_RANGE 	(INPUT_WIDTH*INPUT_HEIGHT)
#define DEST_RANGE 	(OUTPUT_WIDTH*OUTPUT_HEIGHT)

/*----------------------- Functions prototypes ------------------------------*/
void I_Stretch2x_HW(byte src[SRC_RANGE], byte dest[DEST_RANGE], byte fragments);

#endif // STRETCH2X_HW_H
