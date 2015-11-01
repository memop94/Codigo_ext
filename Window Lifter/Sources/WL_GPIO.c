/*
 *      File        : WL_GPIO.h
 *      Created on  : Oct 20, 2015
 *      Authors     : Luis Fernando Alvarez Guerrero, Luis Armando Garcia Valdovinos
 *      Description : Window Lifter GPIO Intialization
 */
#include "WL_GPIO.h"

void Init_GPIO_En(T_SWORD lsw_ch, T_UWORD luw_state)   
{	/* ------------------------------------------------------------------------
     *  Name                 :	Init_GPIO_En
     *  Description          :  Program the drive enable pin
     *  Parameters           :  T_SWORD ch, T_ULONG state
     *  Return               :  void
     *  -----------------------------------------------------------------------
	 * state = 0x0200 -> enable as output                   
	 * state = 0x0100 -> enable as input                    
	 * state = 0x0103 -> enable as input, Pull - up
	 * state = 0x2000 -> enable as APC "Analog Pad Control" or ANP "Analog Port"
	 */
	 
	SIU.PCR[lsw_ch].R = luw_state;				
}

void WL_GPIO_Init(void)
{
	/* ------------------------------------------------------------------------
	 *  Name                 :	WL_GPIO_Init
	 *  Description          :  Program the behavior of the pin
	 *  Parameters           :  
	 *  Return               :  
	 *  -----------------------------------------------------------------------*/
	
	Init_GPIO_En(LED_BAR_0,  0x0200); /* Program the drive enable pin of LED_BAR_0 (PA0) as output       */
	Init_GPIO_En(LED_BAR_1,  0x0200); /* Program the drive enable pin of LED_BAR_1 (PA1) as output       */
	Init_GPIO_En(LED_BAR_2,  0x0200); /* Program the drive enable pin of LED_BAR_2 (PA2) as output       */
	Init_GPIO_En(LED_BAR_3,  0x0200); /* Program the drive enable pin of LED_BAR_3 (PA3) as output       */
	Init_GPIO_En(LED_BAR_4,  0x0200); /* Program the drive enable pin of LED_BAR_4 (PA4) as output       */
	Init_GPIO_En(LED_BAR_5,  0x0200); /* Program the drive enable pin of LED_BAR_5 (PA5) as output       */
	Init_GPIO_En(LED_BAR_6,  0x0200); /* Program the drive enable pin of LED_BAR_6 (PA6) as output       */
	Init_GPIO_En(LED_BAR_7,  0x0200); /* Program the drive enable pin of LED_BAR_7 (PA7) as output       */
	Init_GPIO_En(LED_BAR_8,  0x0200); /* Program the drive enable pin of LED_BAR_8 (PA8) as output       */
	Init_GPIO_En(LED_BAR_9,  0x0200); /* Program the drive enable pin of LED_BAR_9 (PA9) as output       */
	
	Init_GPIO_En(LED_DOWN,   0x0200); /* Program the drive enable pin of LED_DOWN (PA10) as output       */
	Init_GPIO_En(LED_UP,     0x0200); /* Program the drive enable pin of LED_UP (PA11) as output         */
	
	Init_GPIO_En(SW_A_PINCH, 0x0100);  /* Program the drive enable pin of SW_A_PINCH "S1",(PE0) as input */
	Init_GPIO_En(SW_DOWN,    0x0100);  /* Program the drive enable pin of SW_DOWN "S3",(PE3) as input    */
	Init_GPIO_En(SW_UP,      0x0100);  /* Program the drive enable pin of SW_UP "S4",(PE) as input      */
		
	Init_GPIO_En(PE04,  0x0200); /* Program the drive enable pin of LED1 as output       */
	Init_GPIO_En(PE05,  0x0200); /* Program the drive enable pin of LED2 as output       */
	Init_GPIO_En(PE06,  0x0200); /* Program the drive enable pin of LED3 as output       */
	Init_GPIO_En(PE07,  0x0200); /* Program the drive enable pin of LED4 as output       */
}




