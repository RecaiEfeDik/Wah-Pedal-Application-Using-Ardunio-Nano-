

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

// SPI PINS
#define MOSI 3
#define MISO 4
#define SCK 5
#define CS 2


//lcs ve hcs fonksiyonu CS de�erini SPI.c d���nda de�i�tirebilmek i�in tan�mlanm��t�r.


void lcs();//CS de�erini low'a �ekmek i�in fonksiyon
void hcs();//CS de�erini high'a �ekmek i�in fonksiyon
void SPI_init();
uint8_t SPI_transfer(uint8_t data);
uint8_t SPI_recieve();

#endif