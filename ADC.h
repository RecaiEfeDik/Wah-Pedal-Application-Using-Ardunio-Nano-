

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "SPI.h"

int ExternalADC_read();
void ADC_init();
uint8_t ADC_read();

#endif 