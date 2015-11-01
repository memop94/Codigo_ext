/*
 *      File        : WL_GPIO.h
 *      Created on  : Oct 20, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter GPIO Intialization
 */

#ifndef WL_GPIO_INIT_H_
#define WL_GPIO_INIT_H_

#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "MPC5606B.h"

/*----- Functions -----*/

void WL_GPIO_Init(void);
void Init_GPIO_En(T_SWORD lsw_ch, T_UWORD luw_state);

#endif /* WL_GPIO_INIT_H_ */
