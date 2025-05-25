

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

void UART_init();
void UART_transmit(uint8_t data);
uint8_t UART_recieve();


#endif 