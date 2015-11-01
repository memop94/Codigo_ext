/*
 *      File        : WL_EIRQ.h
 *      Created on  : Oct 22, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter EIRQ Intialization and functions
 */

#ifndef WL_EIRQ_H_
#define WL_EIRQ_H_

#include "MPC5606B.h"
#include "stdtypedef.h"
#include "IntcInterrupts.h"

void WL_EIRQ_Init(void);
void External_Int_isr(void);

#endif /* WL_EIRQ_H_ */
