#pragma once
#ifndef _SIMULATING_SPI_H_
#define _SIMULATING_SPI_H_

#define _CPOL     1
#define _CPHA     0
#define SCK_IO    //DDRA|=0X01配置时钟io口
#define MOSI_IO   //DDRA|=0X02配置mosiIO口
#define MISO_IO   //DDRA&=0XFB配置misoio口
#define SSEL_IO   //DDRA|=0X08配置片选io口
#define SCK_D(X)  //(X?(PORTA|=0X01):(PORTA&=0XFE))配置时钟高低电平
#define MOSI_D(X) //(X?(PORTA|=0X02):(PORTA&=0XFD))配置mosiIO口高低电平
#define SSEL_D(X) //(X?(PORTA|=0X08):(PORTA&=0XF7))配置片选高低电平
#define MISO_I()  //(PINA&0X04) 读miso输入  

void SPI_Init(void);
unsigned char SPI_Receiver_Dat(void);
void SPI_Send_Dat(unsigned char dat);

#endif
