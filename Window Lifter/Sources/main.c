#include "MPC5606B.h"
#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "WL_GPIO.h"
#include "WL_SYS_INIT.h"
#include "WL_EIRQ.h"
#include "WL_STM.h"
#include "IntcInterrupts.h"
#include "GPIO_State.h"
#include "external_interrupts.h"


int main(void) {
	
	volatile int i = 0;
	volatile int k = 0;
	
	uint16_t su;
	uint16_t sd;
	
	WL_initModesAndClock();
	WL_EIRQ_Init();
	WL_STM_init();
	WL_GPIO_Init();
	init_ext_ints();
	
	asm(" wrteei 1");

   
/*	INTC_InstallINTCInterruptHandler( WL_CheckValid,30,1); /* vector 30 for STM[0] */
	INTC_InstallINTCInterruptHandler(WL_A_Pinch,EIRQ_2,1); /* vector 32 for STM[2] */
	INTC.CPR.R = 0;
  	  

  /* Loop forever */
  for (;;) {
	  
	  sd = GPIO_GetState(SW_DOWN);
	  while (sd == 1){
		  WL_WinADw();
		  sd = GPIO_GetState(SW_DOWN);
	  }
	  
	  su = GPIO_GetState(SW_UP);
	  while (su == 1){
		  WL_WinAUp();
		  su = GPIO_GetState(SW_UP);
	  }
	  
	  GPIO_SetState(LED_DOWN, 0);
	  GPIO_SetState(LED_UP, 0);
	  
	  i++;
  }
}


