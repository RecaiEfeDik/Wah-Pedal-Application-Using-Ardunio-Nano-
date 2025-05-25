

#include "UART.h"

void UART_init()
{

	UBRR0H = 0x00; // (ver2: high/low-byte assignment)
	UBRR0L = 0x67; // 9600 bps baud rate
	UCSR0C &= ~((1<<UMSEL00)|(1<<UMSEL01)); // Async
	UCSR0C &= ~((1<<UPM00)|(1<<UPM01)); // No parity
	UCSR0C &= ~(1<<USBS0); // 1 stop bit
	UCSR0C |= (1<<UCSZ00)|(1<<UCSZ01); // 8-bit data frame
	UCSR0B &= ~(1<<UCSZ02);
	UCSR0A &= ~(1<<U2X0); // No 2X
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0); // Enable Tx & Rx
	
}

void UART_transmit(uint8_t data)
{
	while(~UCSR0A & (1<<UDRE0)); // Wait until UDR empty
	UDR0 = data; // Transmit data
}

uint8_t UART_recieve()
{
	uint8_t data;
	while(~UCSR0A & (1<<RXC0)); // Wait until receive data
	data = UDR0; // Receive data
	return data;
}
