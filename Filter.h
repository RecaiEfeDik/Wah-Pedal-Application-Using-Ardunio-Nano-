
#ifndef FILTER_H_
#define FILTER_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h> 


float a_array[8][3];
float b_array[8][3];


float* insert_and_shift(float input, float* x);
float calculate_output(float* x, float* y, uint8_t filter_index);

#endif