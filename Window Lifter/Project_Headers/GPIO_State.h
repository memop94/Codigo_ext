/*
 * GPIO_State.h
 *
 *  Created on: Nov 1, 2015
 *      Author: GuillermoFrancisco
 */

#ifndef GPIO_STATE_H_
#define GPIO_STATE_H_

#include "stdtypedef.h"
#include "MPC5606B.h"

uint8_t GPIO_GetState (uint16_t);
void GPIO_SetState (uint16_t ch, uint8_t value);

#endif /* GPIO_STATE_H_ */
