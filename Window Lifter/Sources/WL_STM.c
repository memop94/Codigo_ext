/*
 *      File        : WL_STM.c
 *      Created on  : Oct 26, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter STM Intialization and Functions
 */

#include "WL_STM.h"
#include "GPIO_State.h"
volatile int j = 0;

void WL_STM_init(void)
{
    STM.CR.B.TEN        = 0x0;
    STM.CR.B.FRZ        = 0x1;
    STM.CR.B.CPS        = 0;         /* Configure Counter Prescaler, Counter Prescaler is 1     */
    
    STM.CH[0].CMP.R     = 0x9C400; /* Compare with 640KHz = 10 msec*/      
    STM.CH[0].CCR.B.CEN = 0x1;       /* System Timer Channel 0: ENABLE                          */
    
    STM.CH[1].CMP.R     = 0x1E84800; /* Compare with 32MHz - 500 msec*/      
    STM.CH[1].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CH[2].CMP.R     = 0x186A000; /* Compare with 25.6MHz - 400 msec*/      
    STM.CH[2].CCR.B.CEN = 0x1;       /* System Timer Channel 1: ENABLE                          */
    
    STM.CR.B.TEN        = 0x1;       /* Enable System Timer Module                              */
}


void WL_CheckValid(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckValid  
	*  Description          :  Check if counter has reached 10msec
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	if (STM.CH[0].CIR.B.CIF)
	{
		LED_TOGGLE(68);
		STM.CH[0].CIR.B.CIF = 1;	/* Clear interrupt flag */
	}
}

void WL_CheckAutoManualUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[1].CIR.B.CIF)
	{
		LED_TOGGLE(69);
		STM.CH[1].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
	}
}

int WL_CheckAutoManualDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_CheckAutoManual
	*  Description          :  Check if the movement will be Auto or Manual
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	int mode = 0;
	
	uint16_t sd;
	
	sd = GPIO_GetState(SW_DOWN);
	while (sd == 1){
		mode = 1;
		if (STM.CH[1].CIR.B.CIF)
		{
			STM.CNT.R = 0; 				/*Reset counter*/
			WL_WinMDw();
			mode = 2;
			sd = 2;
		}
		STM.CH[1].CIR.B.CIF = 1;	/* Clear interrupt flag */
		sd = GPIO_GetState(SW_DOWN);
	}
	  

	return mode;
}

void WL_WinMUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[2].CIR.B.CIF)
	{
		GPIO_SetState(LED_BAR_0 + j, 1);
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		j++;
		if (j > 9){
			j = 9;
		}
	}
}

void WL_WinAUp(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMUp
	*  Description          :  Open the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/
	while(j <= 9){
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + j, 1);
			GPIO_SetState(LED_UP, 1);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			j++;
		}
	}
}

void WL_WinMDw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMDw
	*  Description          :  Close the window manually
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	if (STM.CH[2].CIR.B.CIF)
	{
		GPIO_SetState(LED_DOWN, 1);
		GPIO_SetState(LED_BAR_0 + j, 0);
		STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
		STM.CNT.R = 0; 				/*Reset counter*/
		j--;
		if (j < 0){
			j = 0;
		}
	}
}

void WL_WinADw(void)
{  /* ------------------------------------------------------------------------
	*  Name                 :  WL_WinMDw
	*  Description          :  Close the window automatically
	*  Parameters           :  void 
	*  Return               :  void
	*  -----------------------------------------------------------------------
	*/

	while(j >= 0){
		if (STM.CH[2].CIR.B.CIF)
		{
			GPIO_SetState(LED_BAR_0 + j, 0);
			GPIO_SetState(LED_DOWN, 1);
			STM.CH[2].CIR.B.CIF = 1;	/* Clear interrupt flag */
			STM.CNT.R = 0; 				/*Reset counter*/
			j--;
		}
	}
}
