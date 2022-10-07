/*
 * display7SEG.h
 *
 *  Created on: Oct 7, 2022
 *      Author: minhl
 */

#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_

#include "main.h"

extern int index_led;

void display7SEG(int8_t counter);
void update7SEG(int index);

#endif /* INC_DISPLAY7SEG_H_ */
