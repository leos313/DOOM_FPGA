/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch2x hardware Accelerator project
 * 		File: - "stretch2x_sw.h"
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
#ifndef STRETCH2_SW_H
#define STRETCH2_SW_H


#include <inttypes.h>

/*----------------------------- Type Definitions ----------------------------*/
typedef uint8_t byte;


/*------------------------- Constant Definitions ----------------------------*/
#define SCREENWIDTH  (640)
#define SCREENHEIGHT (400)


/*----------------------- Functions prototypes ------------------------------*/
void I_Stretch2x_SW(int x1, int y1, int x2, int y2);


#endif // STRETCH2X_SW_H
