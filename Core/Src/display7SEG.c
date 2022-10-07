/*
 * display7SEG.c
 *
 *  Created on: Oct 7, 2022
 *      Author: minhl
 */

#include "display7SEG.h"

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1,2,3,4};

uint8_t segmentArray[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6F}; //From 0 to 9
void display7SEG(int8_t counter) {
	if (counter<0 || counter>9) return;
	for (int i=0; i<7; i++) {
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0 << i, !((segmentArray[counter]>>i)&0x1));
	}
}

void update7SEG(int index) {
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, EN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN1_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			index_led = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, EN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN2_Pin | EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			index_led = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, EN2_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN3_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			index_led = 3;
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, EN3_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin, GPIO_PIN_SET);
			display7SEG(led_buffer[index]);
			index_led = 0;
			break;
		default:
			break;
	}
}
