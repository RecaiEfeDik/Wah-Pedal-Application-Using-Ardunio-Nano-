

#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


void Timer_init();
void OCR_set(uint8_t ocr);


#endif 