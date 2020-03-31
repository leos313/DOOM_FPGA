/* ----------------------------------------------------------------------------
 * ------------------------- Doom TFM (CEI 2017/2018)--------------------------
 * ----------------------------------------------------------------------------
 * 	Stretch4x Accelerator project
 * 		File: - "stretch4x_tb.h"
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
#ifndef STRETCH4X_TB_H
#define STRETCH4X_TB_H


/*----------------------------- Libraries -----------------------------------*/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <string.h>

/*---------------------------- Project headers ------------------------------*/
#include "Stretch4x.h"
#include "stretch4x_sw.h"
#include "doomtype.h"
#include "sds_lib.h"

/*------------------------- Constant Definitions ----------------------------*/
/*
 * Software static arguments, needed in software implementation
 */
#define X1 (0)
#define X2 (320)
#define Y1 (0)
#define Y2 (200)

/*
 * Pitch of destination buffer, ie. screen->pitch
 */
#define PITCH (1280)

/*
 * Number of iterations
 */
#define N_REP (1000)

/*------------------------- Variable Definitions ----------------------------*/
/*
 * Global pointers needed in SW implementation
 */
byte *src_buffer, *dest_buffer;
int dest_pitch;


/*------------------------- Function Prototypes -----------------------------*/


#endif // STRETCH4X_TB_H
