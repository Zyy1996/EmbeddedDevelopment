#pragma once
#ifndef _CHECKOUT_H_
/****************************************
使用的c文件是checkout.c
作用：
放一些做校验的代码

****************************************/

//crc16校验码代码
void InvertUint8(unsigned char* DesBuf, unsigned char* SrcBuf);
void InvertUint16(unsigned short* DesBuf, unsigned short* SrcBuf);
unsigned short CRC16_MODBUS(unsigned char* puchMsg, unsigned int usDataLen);

//累加前面的字节最后取256的模



#endif





