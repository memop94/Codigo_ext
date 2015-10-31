#include "MPC5606B.h"
#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "WL_GPIO.h"
#include "WL_SYS_INIT.h"
#include "WL_EIRQ.h"
#include "WL_STM.h"
#include "IntcInterrupts.h"

/* PORT Mapping */

/* PORT mapping for LED Bar Indicator */
/* 1 -> Window Portion is Closed      */
/* 0 -> Window Portion is Open        */
enum E_PORT LED_BAR_0  = PA00;  
enum E_PORT LED_BAR_1  = PA01;
enum E_PORT LED_BAR_2  = PA02;
enum E_PORT LED_BAR_3  = PA03;
enum E_PORT LED_BAR_4  = PA04;
enum E_PORT LED_BAR_5  = PA05;
enum E_PORT LED_BAR_6  = PA06;
enum E_PORT LED_BAR_7  = PA07;
enum E_PORT LED_BAR_8  = PA08;
enum E_PORT LED_BAR_9  = PA09;

/* PORT Mapping for Movement Indicators*/
enum E_PORT LED_DOWN   = PA10; 
enum E_PORT LED_UP     = PA11;

/* PORT Mapping for Movement Switches */
enum E_PORT SW_DOWN    = PE00; /* Development Board Switch S1*/
enum E_PORT SW_UP      = PE01; /* Development Board Switch S2*/

/* PORT Mapping for Anti-Pinch Button */
enum E_PORT SW_A_PINCH = PE02; /* Development Board Switch S3*/

void WL_GPIO_Init(void);

int main(void) {
  volatile int i = 0;
  
  WL_GPIO_Init();
  WL_initModesAndClock();
  WL_EIRQ_Init();
  WL_STM_init();
  
  Init_GPIO_En(68,  0x0200); /* Program the drive enable pin of LED_BAR_0 (PA0) as output       */
  Init_GPIO_En(69,  0x0200); /* Program the drive enable pin of LED_BAR_1 (PA1) as output       */
  
  INTC_InstallINTCInterruptHandler( WL_CheckCounter,30,4); /* vector 30 for STM[0] */
  INTC_InstallINTCInterruptHandler(WL_CheckCounter1,31,3); /* vector 31 for STM[1] */
  
  INTC.CPR.R = 0;
  	  

  /* Loop forever */
  for (;;) {
	  i++;
  }
}

void WL_GPIO_Init(void)
{
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
	  	  	  
	  Init_GPIO_En(SW_DOWN,    0x0100);  /* Program the drive enable pin of SW_DOWN "S1",(PE0) as input    */
	  Init_GPIO_En(SW_UP,      0x0100);  /* Program the drive enable pin of SW_UP "S2",(PE1) as input      */
	  Init_GPIO_En(SW_A_PINCH, 0x0100);  /* Program the drive enable pin of SW_A_PINCH "S3",(PE2) as input */
}


