

#include "ADC.h"


int ExternalADC_read(void) {
	lcs(); // cs low yap 
	
	// D2D1D0 kanal seçim bitleri
	
	SPI_transfer(0x06);//Start bit + single ended + D2

	uint8_t exadch = SPI_transfer(0x00); // D1 + D0 ve veri alma

	uint8_t exadcl   = SPI_transfer(0x00);// Sadece veri alma

	hcs();// cs high yap

	
	return ((int)(exadch & 0x0F) << 8) | (int)exadcl;
}

void ADC_init()
{
	DDRC = 0x00;
	// ADC SETTINGS
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADPS2); // F_adc = 125kHz
	ADMUX &= ~(1<<REFS1);
	ADMUX |= (1<<REFS0); // Vref = Vcc
	ADMUX |= (1<<ADLAR); // Adjust left
	ADCSRA |= (1<<ADEN); // ADC enable
	ADMUX &= 0xF0; // Reset MUX
	ADMUX |= (1<<MUX0); // Selected channel ADC1
	ADCSRA |= (1<<ADSC); // First conversion
	_delay_ms(100);
}

uint8_t ADC_read()
{
	uint8_t adch = 0;
	uint8_t data = 0;
	ADCSRA = (1<<ADSC);
	while(~ADCSRA & (1<<ADIF));
	adch = ADCH;
	data = adch >> 5;
	return data;
	
}