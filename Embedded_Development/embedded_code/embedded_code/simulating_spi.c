#include "simulating_spi.h"


//void delay()
//{
//	unsigned char m, n;
//	for (n = 0; n < 5; n++);
//	for (m = 0; m < 100; m++);
//}
/************************************************
		端口方向配置  与输出初始化
************************************************/
void SPI_Init(void)
{
	SCK_IO;
	MOSI_IO;
	MISO_IO;
	SSEL_IO;
	SSEL_D(1);
	MOSI_D(1);
#if _CPOL==0
	SCK_D(0);
#else
	SCK_D(1);
#endif
}

/**********************************************
模式零           写数据
***********************************************/
#if _CPOL==0&&_CPHA==0          //MODE   0  0   
void SPI_Send_Dat(unsigned char dat)
{
	unsigned char n;
	for (n = 0; n < 8; n++)
	{
		SCK_D(0);
		if (dat & 0x80)
			MOSI_D(1);
		else
			MOSI_D(0);
		dat <<= 1;
		SCK_D(1);
	}
	SCK_D(0);
}

/*********************************************
模式零         读数据
*********************************************/
unsigned char SPI_Receiver_Dat(void)
{
	unsigned char n, dat, bit_t;

	for (n = 0; n < 8; n++)
	{
		SCK_D(0);
		dat <<= 1;
		if (MISO_I())
			dat |= 0x01;
		else
			dat &= 0xfe;
		SCK_D(1);
	}
	SCK_D(0);
	return dat;
}
#endif


/**********************************************
模式二           写数据
***********************************************/
#if _CPOL==1&&_CPHA==0           //MODE   1  0
void SPI_Send_Dat(unsigned char dat)
{
	unsigned char n;
	for (n = 0; n < 8; n++)
	{
		SCK_D(1);
		if (dat & 0x80)MOSI_D(1);
		else MOSI_D(0);
		dat <<= 1;
		SCK_D(0);
	}
	SCK_D(1);
}
/*********************************************
模式二          读数据
*********************************************/
unsigned char SPI_Receiver_Dat(void)
{
	unsigned char n, dat, bit_t;
	for (n = 0; n < 8; n++)
	{
		SCK_D(1);
		dat <<= 1;
		if (MISO_I())dat |= 0x01;
		else dat &= 0xfe;
		SCK_D(0);
	}
	SCK_D(1);
	return dat;
}

#endif


/*********************************************
模式一        写数据
*********************************************/
#if _CPOL==0&&_CPHA==1           //MODE  0  1
void SPI_Send_Dat(unsigned char dat)
{
	unsigned char n;
	SCK_D(0);
	for (n = 0; n < 8; n++)
	{
		SCK_D(1);
		if (dat & 0x80)MOSI_D(1);
		else MOSI_D(0);
		dat <<= 1;
		SCK_D(0);
	}
}
/*********************************************
模式一       读数据
*********************************************/
unsigned char SPI_Receiver_Dat(void)
{
	unsigned char n, dat, bit_t;
	for (n = 0; n < 8; n++)
	{
		SCK_D(1);
		dat <<= 1;
		if (MISO_I())dat |= 0x01;
		else dat &= 0xfe;
		SCK_D(0);
	}
	SCK_D(0);
	return dat;
}
#endif


/*********************************************
模式三        写数据
*********************************************/
#if _CPOL==1&&_CPHA==1            //MODE  1  1
void SPI_Send_Dat(unsigned char dat)
{
	unsigned char n;

	SCK_D(1);
	for (n = 0; n < 8; n++)
	{
		SCK_D(0);
		if (dat & 0x80)
			MOSI_D(1);
		else
			MOSI_D(0);
		dat <<= 1;
		SCK_D(1);
	}
}
/************************************
模式三          读数据
************************************/
unsigned char SPI_Receiver_Dat(void)
{
	unsigned char n, dat, bit_t;
	SCK_D(0);
	for (n = 0; n < 8; n++)
	{
		SCK_D(0);
		dat <<= 1;
		if (MISO_I())
			dat |= 0x01;
		else
			dat &= 0xfe;
		SCK_D(1);
	}
	SCK_D(1);
	return dat;
}
#endif
