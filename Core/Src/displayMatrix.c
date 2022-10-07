/*
 * displayMatrix.c
 *
 *  Created on: Oct 7, 2022
 *      Author: minhl
 */

#include "displayMatrix.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer [8] = {0x18 , 0x3C , 0x66 , 0x66 , 0x7E , 0x7E , 0x66 , 0x66 };

void displayMatrix(int8_t index) {
	for (int i=0; i<8; i++) {
		HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin << i, (matrix_buffer[index]>>i)&0x1);
	}
}

void updateLEDMatrix(int index) {
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM1_Pin | ENM2_Pin |
											  ENM3_Pin | ENM4_Pin |
											  ENM5_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 1;
			break;
		case 1:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM2_Pin |
											  ENM3_Pin | ENM4_Pin |
											  ENM5_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 2;
			break;
		case 2:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM2_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM3_Pin | ENM4_Pin |
											  ENM5_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 3;
			break;
		case 3:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM3_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM2_Pin | ENM4_Pin |
											  ENM5_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 4;
			break;
		case 4:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM4_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM2_Pin | ENM3_Pin |
											  ENM5_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 5;
			break;
		case 5:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM5_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM2_Pin | ENM3_Pin |
											  ENM4_Pin | ENM6_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 6;
			break;
		case 6:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM6_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM2_Pin | ENM3_Pin |
											  ENM4_Pin | ENM5_Pin |
											  ENM7_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 7;
			break;
		case 7:
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM7_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(ENM0_GPIO_Port, ENM0_Pin | ENM1_Pin |
											  ENM2_Pin | ENM3_Pin |
											  ENM4_Pin | ENM5_Pin |
											  ENM6_Pin, GPIO_PIN_RESET);
			displayMatrix(index);
			index_led_matrix = 0;
			break;
		default:
			break;
	}
}
