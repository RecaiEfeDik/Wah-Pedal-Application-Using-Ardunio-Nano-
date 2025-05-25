

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


//lcs ve hcs fonksiyonu CS deðerini SPI.c dýþýnda deðiþtirebilmek için tanýmlanmýþtýr.


void lcs();//CS deðerini low'a çekmek için fonksiyon
void hcs();//CS deðerini high'a çekmek için fonksiyon
void SPI_init();
uint8_t SPI_transfer(uint8_t data);
uint8_t SPI_recieve();

#endif