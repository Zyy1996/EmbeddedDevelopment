#include "strings.h"

void hexstrTonum(u8* pdata, u16 length, u8* pout)
{
	u16 i = 0;
	u8 h = 0;
	u8 l = 0;
	for (i = 0; i < length; i = i + 2)
	{
		if (pdata[i] <= '9' && pdata[i] >= '0') h = pdata[i] - '0';
		else if (pdata[i] <= 'F' && pdata[i] >= 'A') h = pdata[i] - 'A' + 10;
		else h = pdata[i] - 'a' + 10;
		if (pdata[i + 1] <= '9' && pdata[i + 1] >= '0') l = pdata[i + 1] - '0';
		else if (pdata[i + 1] <= 'F' && pdata[i + 1] >= 'A') l = pdata[i + 1] - 'A' + 10;
		else l = pdata[i + 1] - 'a' + 10;
		pout[i / 2] = h * 16 + l;
	}
}

void decTostr(u32 data,u8 len,u8 *pout)
{
	u8 i = 0;
	for (i = 0; i < len; i++)
	{
		if (data == 0)
		{
			if(i!=0) pout[len - 1 - i] = ' ';
			else  pout[len - 1 - i] = '0';
		}			
		else pout[len - 1 - i] = data % 10+'0';		
		data = data / 10;		
	}
	pout[len] = '\0';
}

void strCpy(u8* pdata,u16 len, u8* pout)
{
	u16 i = 0;
	for (i = 0; i < len; i++)
	{
		pout[i] = pdata[i];
	}
}

void memSet(u8* pdata, u16 len, u8 status)
{
	u16 i = 0;
	for (i = 0; i < len; i++)
	{
		pdata[i] = status;
	}
}

u16 Getstrnum(const u8* pdata)
{
	u16 i = 0;
	for (i = 0; pdata[i] != '\0'; i++);
	return i;
}

u8 strMatch(u8* pdata, u16 len, const u8* strMatch , u16 *loc)
{
	u16 length = Getstrnum(strMatch);
	u16 i = 0;
	u16 j = 0;
	if (len < length) return Error;
	for (i = 0; i <= len - length; i++)
	{
		for (j = 0; j < length; j++)
		{
			if (pdata[i + j] != strMatch[j]) break;
		}
		if (j == length)
		{
			*loc = i + j;
			return Ok;
		}
	}
	return Error;
}


