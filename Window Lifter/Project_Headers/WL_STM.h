/*
 *      File        : WL_STM.h
 *      Created on  : Oct 26, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter STM Intialization and Functions
 */


#ifndef WL_STM_H_
#define WL_STM_H_

#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"
#include "WL_FUNCTIONS.h"


void WL_STM_init    (void);

void WL_CheckValid(void);

void WL_CheckAutoManualUp(void);
int WL_CheckAutoManualDw(void);

void WL_WinMUp(void);
void WL_WinAUp(void);
void WL_WinMDw(void);
void WL_WinADw(void);

#endif /* WL_STM_H_ */
