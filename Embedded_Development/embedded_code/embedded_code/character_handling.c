#include "character_handling.h"

u8 revData[256] = { 0 };

/**********************
����ƥ����ַ�
u8 *p  �洢�ַ�����λ��
u8 location  �洢�ַ�����ʼ��λ��
u8 length   ��Ҫ���ĳ���
u8 * matched_character ��Ҫƥ����ַ���
u8 *endlocation  ƥ���ַ������һ���ַ�
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
���ڴ��������
u8 *p  ��Ҫ��0���ڴ�����
u8 location ��ʼ����
u8 num   ��0�ĸ���
*****************/
void mem_reset(u8 *p,u8 location , u8 num )
{
	u8 i = 0;
	for (i = 0; i < num; i++) p[location+i] = 0;
}

/******************
 ��16�����ַ�����Ϊ10�������֣�����1��
 u8 *p       ���ݶ�ȡ����
 u8 location ���ݿ�ʼ��λ��
 u8 number   ��Ҫ��ȡ�����ָ���
 u8 *pout    �����������
 "123423" ת��Ϊ����18 �� 52 �� 35
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
 ��16�����ַ�����Ϊ10�������֣�����2��
u8 *pdata  ������ݵ�����
u8 location ������ݵ�����Ŀ�ʼλ��
u8 *outdata ������ݵ�λ��
u8 number ��Ҫ��ȡ�����ָ���
u8 start    �洢������ݵĿ�ʼλ��
"01020304"ת��Ϊ����18��52
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
�ӿ�ʼλ�ã���Ⲣ��ȡָ�������������ַ�
u8 *p       ���ݻ������õ��洢λ��
u8 location ���ݻ�������ʼ��λ��
u8 length   ������ݵ����
u8 *pout    ����ȡ�������ݻ����λ��
u8 num     ��Ҫ��ȡ�����ָ���
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
������ת��Ϊ�ַ���
u32 number ��Ҫת��������
u8 *pout   �洢���ݵ�λ��
u8 num     ת�����ַ����ĳ���
1234 ת��Ϊ��1234��
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
���ַ���ת��Ϊ����
u8 * pdata  �洢���ݵ�����
u8 location ��ʼת���Ŀ�ʼλ��
u32 *data   ����ת�������ݵ�����
u8 num      ����ת��������ַ�����
��1231��ת��Ϊ����1231
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
//�����ַ���
void strcopy(u8 *pdata, u8 location, u8 *pout, u8 num)
{
	u8 i = 0;
	for (i = 0; i < num; i++) pout[i] = pdata[location + i];
}
