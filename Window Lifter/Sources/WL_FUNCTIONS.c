/*
 *      File        : WL_FUNCTIONS.c
 *      Created on  : Oct 21, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter Main Functions
 */
#include "WL_FUNCTIONS.h"

void LED_ON(T_SWORD lsw_Channel)
{	/* ------------------------------------------------------------------------
	 *  Name                 :	LED_ON
	 *  Description          :  Set channel's (lsw_CHANNEL) GPDO to 1 (ON)
	 *  Parameters           :  T_SWORD lsw_Channel
	 *  Return               :  void
	 *  -----------------------------------------------------------------------
	 */
	SIU.GPDO[lsw_Channel].B.PDO = 1;
}

void LED_OFF(T_SWORD lsw_Channel)
{	/* ------------------------------------------------------------------------
     *  Name                 :	LED_OFF
     *  Description          :  Set channel's (lsw_CHANNEL) GPDO to 0 (OFF)
     *  Parameters           :  T_SWORD lsw_Channel
     *  Return               :  void
     *  -----------------------------------------------------------------------
     */
	SIU.GPDO[lsw_Channel].B.PDO = 0;
}

void LED_TOGGLE(uint16_t ch)
{
		SIU.GPDO[ch].B.PDO ^= 1;
}
