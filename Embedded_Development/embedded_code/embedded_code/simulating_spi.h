#pragma once
#ifndef _SIMULATING_SPI_H_
#define _SIMULATING_SPI_H_

#define _CPOL     1
#define _CPHA     0
#define SCK_IO    //DDRA|=0X01����ʱ��io��
#define MOSI_IO   //DDRA|=0X02����mosiIO��
#define MISO_IO   //DDRA&=0XFB����misoio��
#define SSEL_IO   //DDRA|=0X08����Ƭѡio��
#define SCK_D(X)  //(X?(PORTA|=0X01):(PORTA&=0XFE))����ʱ�Ӹߵ͵�ƽ
#define MOSI_D(X) //(X?(PORTA|=0X02):(PORTA&=0XFD))����mosiIO�ڸߵ͵�ƽ
#define SSEL_D(X) //(X?(PORTA|=0X08):(PORTA&=0XF7))����Ƭѡ�ߵ͵�ƽ
#define MISO_I()  //(PINA&0X04) ��miso����  

void SPI_Init(void);
unsigned char SPI_Receiver_Dat(void);
void SPI_Send_Dat(unsigned char dat);

#endif
