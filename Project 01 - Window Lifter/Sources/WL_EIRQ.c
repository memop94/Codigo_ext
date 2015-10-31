/*
 *      File        : WL_EIRQ.h
 *      Created on  : Oct 22, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter EIRQ Intialization and functions
 */
#include "WL_EIRQ.h"

void WL_EIRQ_Init(void)
{ 	/* ------------------------------------------------------------------------
 	 *  Name                 :	EIRQ_Init
 	 *  Description          :  Initialize External Interruptions
 	 *  Parameters           :  void
 	 *  Return               :  void
 	 *  -----------------------------------------------------------------------
 	 */
		SIU.PCR[66].R      = 0x0100;	/* Pin PE[2]- EIRQ21 configured as GPIO   */
		SIU.IFEER.B.IFEE21 = 1;	        /* Enable falling edge event on EIRQ21    */
		SIU.IRER.B.IRE21   = 1;		    /* Enable interrupt Results EIRQ21        */
}

void External_Int_isr(void)
{   /* ------------------------------------------------------------------------
 	 *  Name                 :	External_Int_isr
 	 *  Description          :  Check for external interruption and execute
 	 *  Parameters           :  void
 	 *  Return               :  void
 	 *  -----------------------------------------------------------------------
 	 *  IRQ_0 -> From EIRQ0  to EIRQ7  -> Interrupt Vector 41
 	 *  IRQ_1 -> From EIRQ8  to EIRQ15 -> Interrupt Vector 42
 	 *  IRQ_2 -> From EIRQ16 to EIRQ23 -> Interrupt Vector 43
 	 */
	
		if(SIU.ISR.B.EIF21 == 1)  /* There's single interrupt vector for 8 IRQs. Test if interrupt comes from IRQ2: */
		{			
    	/*TODO: add Anti Pinch function*/
    	SIU.ISR.B.EIF21 = 1;	  /* Clear interrupt flag */
		}
		else
		{
			/* Do Nothing */
		}

}
