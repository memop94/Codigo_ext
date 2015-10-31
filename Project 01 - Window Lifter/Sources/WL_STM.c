/*
 *      File        : WL_STM.c
 *      Created on  : Oct 26, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter STM Intialization and Functions
 */

#include "WL_STM.h"

void WL_STM_init(void)
{
    STM.CR.B.TEN        = 0x0;
    STM.CR.B.FRZ        = 0x1;
    STM.CR.B.CPS        = 0;         /* Configure Counter Prescaler, Counter Prescaler is 1     */
    
    STM.CH[0].CMP.R     = 0x1E84800; /* Compare with 32MHz - 500 msec*/      
    STM.CH[0].CCR.B.CEN = 0x1;       /* System Timer Channel 0: ENABLE                          */
    
    STM.CH[1].CMP.R     = 0x3D09000; /* Compare with 64MHz - 1 sec*/      
    STM.CH[1].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CR.B.TEN        = 0x1;       /* Enable System Timer Module                              */
}


void WL_CheckCounter(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckCounter  
	*  Description          :  Check if counter value is luw_value
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[0].CIR.B.CIF)
	{
		LED_TOGGLE();
		STM.CH[0].CIR.B.CIF = 1;	/* Clear interrupt flag */
	}
}

void WL_CheckCounter1(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckCounter  
	*  Description          :  Check if counter value is luw_value
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[1].CIR.B.CIF)
	{
		LED_TOGGLE1();
		STM.CH[1].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
	}
}
