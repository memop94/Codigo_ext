/*
 * GPIO_State.c
 *
 *  Created on: Nov 1, 2015
 *      Author: GuillermoFrancisco
 */
#include "GPIO_State.h"



uint8_t GPIO_GetState (uint16_t ch)
{
    uint8_t result;

    result = (uint8_t)SIU.GPDI[ch].B.PDI;

    return(result);
}

void GPIO_SetState (uint16_t ch, uint8_t value)
{
    SIU.GPDO[ch].B.PDO = value;
}

