

#include "Timer.h"

void Timer_init()
{
	DDRB |= (1<<DDB1);
	TCCR1B |= (1<<WGM12) | (1<<WGM11);
	TCCR1A |= (1<<WGM10);
	TCCR1A |= (1<<COM1A1);
	TCCR1B |= (1<<CS10);
	 
}
void OCR_set(uint8_t ocr)
{
	OCR1A = ocr;
}