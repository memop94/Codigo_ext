#include "MPC5606B.h"
#include "driver_channel_MPC5606B.h"
#include "stdtypedef.h"
#include "WL_GPIO.h"
#include "WL_SYS_INIT.h"
#include "WL_EIRQ.h"
#include "WL_STM.h"
#include "IntcInterrupts.h"
#include "GPIO_State.h"

int main(void) {
  volatile int i = 0;
  volatile int k = 0;
  int dw;

  uint16_t su;
  uint16_t sd;
  
  WL_initModesAndClock();
  WL_EIRQ_Init();
  WL_STM_init();
  WL_GPIO_Init();
   
  //INTC_InstallINTCInterruptHandler( WL_CheckValid,30,1); /* vector 30 for STM[0] */
  //INTC_InstallINTCInterruptHandler(WL_CheckAutoManual,31,2); /* vector 31 for STM[1] */
  
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


