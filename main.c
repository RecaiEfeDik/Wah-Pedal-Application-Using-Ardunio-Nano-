
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>

#include "UART.h"
#include "ADC.h"
#include "Filter.h"
#include "Timer.h"

int main(void)
{
	
	UART_init();
	SPI_init();
	ADC_init();
	Timer_init();
	
	float* x_array = (float*)malloc(sizeof(float) * 3); //input array tan�mlama
	float* y_array = (float*)malloc(sizeof(float) * 3); // output array tan�mlama

	for (uint8_t i=0; i<3; i++)
	{
		x_array[i] = 0.0f; //ba�lang�� de�eri olarak s�f�r atan�r
		y_array[i] = 0.0f;	//ba�lang�� de�eri olarak s�f�r atan�r
	}

	while (1)
	{
		uint8_t filter_index = ADC_read(); // filtre se�imi i�in gerekecek indeks de�eri internal adc kullan�larak okunur
		
		int data = ExternalADC_read(); // ham ses verisi elde edilir
		float volts = data/1023.0f * 3.30f; // ham ses verisi volta d�n��t�r�l�r
		
		x_array = insert_and_shift(volts, x_array); // volt de�eri atan�r ve array kayd�r�l�r
		uint8_t y_n = calculate_output(x_array, y_array, filter_index); // ��k�� de�eri hesaplan�r
		y_array = insert_and_shift(y_n, y_array); //��k�� de�eri ��k�� arrayine atan�r
		
		int output_raw = ((int)(y_n / 3.30f) * 1023); // voltaj de�eri d��ar� s�r�lmek i�in uygun formata getirilir 
		
		uint16_t output_ocr = 0;
		
		if (output_raw > 1023)
			output_ocr = 0xFFFF;
		else
			output_ocr = (uint16_t)(output_raw);
		
		OCR_set(output_ocr); // Timer1 pwm duty cycle'� uygun datayla buzzera s�r�lmek i�in de�i�tiriliyor
		
		_delay_ms(5);
		
	}

}
