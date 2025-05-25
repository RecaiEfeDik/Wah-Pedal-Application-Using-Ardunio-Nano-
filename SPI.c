

#include "SPI.h"

void SPI_init() {
	
	DDRB |= (1<<MOSI)|(1<<SCK)|(1<<CS);
	DDRB &= ~(1 << MISO);
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
	PORTB |= (1<<CS);	
	_delay_ms(500);
}

void lcs(){PORTB &= ~(1<<CS);}
void hcs(){PORTB |= (1<<CS);}

// in SPI.h or SPI.c:
uint8_t SPI_transfer(uint8_t data) {
	SPDR = data;                    // start transfer
	while (!(SPSR & (1 << SPIF)));  // wait until complete
	return SPDR;                    // reading SPDR clears SPIF
}
