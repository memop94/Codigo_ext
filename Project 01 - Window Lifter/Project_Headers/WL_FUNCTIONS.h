/*
 *      File        : WL_FUNCTIONS.h
 *      Created on  : Oct 21, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter Main Functions
 */

#ifndef WL_FUNCTIONS_H_
#define WL_FUNCTIONS_H_

#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "MPC5606B.h"

void LED_ON (T_SWORD lsw_Channel);
void LED_OFF(T_SWORD lsw_Channel);

void LED_TOGGLE(void);
void LED_TOGGLE1(void);

#endif /* WL_FUNCTIONS_H_ */
