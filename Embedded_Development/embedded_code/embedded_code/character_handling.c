#include "character_handling.h"

u8 revData[256] = { 0 };

/**********************
发现匹配的字符
u8 *p  存储字符串的位置
u8 location  存储字符串开始的位置
u8 length   需要检测的长度
u8 * matched_character 需要匹配的字符串
u8 *endlocation  匹配字符后面的一个字符
**********************/
u8 find_strs(const char *p, u8 location, u8 length, const char * matched_character, u8 *endlocation)
{
	u8 i = 0;
	u8 j = 0;
	for (i = 0; i < length; i++)
	{
		for (j = 0; matched_character[j] != '\0'; j++)
		{
			if (p[location + +i + j] != matched_character[j]) 	break;
		}
		if (matched_character[j] == '\0')
		{
			if (endlocation != NULL) *endlocation = location + i + j;
			return 1;
		}
	}
	return 0;
}

/*****************
将内存区域归零
u8 *p  需要置0的内存区域
u8 location 开始区域
u8 num   置0的个数
*****************/
void mem_reset(u8 *p,u8 location , u8 num )
{
	u8 i = 0;
	for (i = 0; i < num; i++) p[location+i] = 0;
}

/******************
 将16进制字符串变为10进制数字，迭代1次
 u8 *p       数据读取区域
 u8 location 数据开始的位置
 u8 number   需要获取的数字个数
 u8 *pout    数据输出区域
 "123423" 转换为数字18 ， 52 ， 35
*******************/
void convert_strHexToDec(u8 *p, u8 location, u8 number ,u8 *pout)
{
	u8 i = 0;
	u8 H = 0;
	u8 L = 0;
	for (i = 0; i < number*2; i += 2)
	{
		if (p[i] >= '0'&&p[i] <= '9') H = p[i] - '0';
		else if(p[i] >= 'A'&&p[i] <= 'F') H = p[i] - 'A' + 10;
		else H = p[i] - 'a' + 10;
		if (p[i+1] >= '0'&&p[i+1] <= '9') L = p[i+1] - '0';
		else if (p[i+1] >= 'A'&&p[i+1] <= 'F') L = p[i+1] - 'A' + 10;
		else L = p[i+1] - 'a' + 10;
		pout[i/2] = 16 * H + L;
	}
}

/**********************************
 将16进制字符串变为10进制数字，迭代2次
u8 *pdata  检测数据的区域
u8 location 检测数据的区域的开始位置
u8 *outdata 输出数据的位置
u8 number 需要获取的数字个数
u8 start    存储输出数据的开始位置
"01020304"转换为数字18和52
**********************************/
void convert_HexToStr(u8 *pdata, u8 location, u8 number, u8 *pout, u8 start)
{
	u8 i = 0;
	u8 H = 0;
	u8 L = 0;
	for (i = 0; i < number * 2; i += 4)
	{
		switch (pdata[location + i])
		{
		case '3':
			H = pdata[location + i + 1] - '0';
			break;
		case '4':
		case '6':
			H = pdata[location + i + 1] - '0' + 9;
			break;
		}
		switch (pdata[location + i + 2])
		{
		case '3':
			L = pdata[location + i + 3] - '0';
			break;
		case '4':
		case '6':
			L = pdata[location + i + 3] - '0' + 9;
			break;
		}
		pout[start + i / 4] = H * 16 + L;
	}
}

/*******************
从开始位置，检测并获取指定个数的数字字符
u8 *p       数据缓冲区得到存储位置
u8 location 数据缓冲区开始的位置
u8 length   检测数据的深度
u8 *pout    将读取到的数据缓存的位置
u8 num     需要读取的数字个数
********************/
u8 get_strDec(u8 *p, u8 location,u8 length,u8 *pout, u8 num)
{
	u8 i = 0;
	u8 j = 0;
	while (i<=length)
	{
		for (j = 0; j < num; j++)
		{
			if (p[location + i + j] > '9' || p[location + i + j] < '0') break;
		}
		if (j == num)
		{
			for (j = 0; j < num; j++) pout[j] = p[location + i + j];
			return 1;
		}
		i++;
	}
	return 0;
}

/*********************
将数字转换为字符串
u32 number 需要转换的数据
u8 *pout   存储数据的位置
u8 num     转换后字符串的长度
1234 转换为“1234”
**********************/
void convert_decToStr(u32 number, u8 *pout, u8 num)
{
	u8 i = 0;
	for (i = 0; i < num; i++)
	{
		if(number!=0) pout[num - 1 - i] = number % 10 + '0';
		else          pout[num - 1 - i] = ' ';
		number = number / 10;
	}
	pout[num] = '\0';
}

/***************
将字符串转换为数字
u8 * pdata  存储数据的区域
u8 location 开始转换的开始位置
u32 *data   导出转换后数据的区域
u8 num      可以转换的最大字符个数
“1231”转化为数字1231
****************/
void convert_StrToDec(u8 * pdata , u8 location, u32 *data, u8 num)
{
	u8 i = 0;
	u32 number = 0;
	if (num != 0)
	{
		for (i = 0; i < num; i++)
		{
			if (pdata[i+ location] <= '9'&&pdata[i+ location] >= '0')
			{
				number = number * 10;
				number +=  pdata[location+i]-'0';
			}
			else
			{
				*data = number;
				break;
			}
		}
		*data = number;
	}
}
//复制字符串
void strcopy(u8 *pdata, u8 location, u8 *pout, u8 num)
{
	u8 i = 0;
	for (i = 0; i < num; i++) pout[i] = pdata[location + i];
}
