#ifndef _SORT_H_
#include "common.h"
/*****************************************
作用：
字符串的处理
*****************************************/
enum str_err
{
	Error = 0,
	Ok = 1,
	Memory_overflow = 2,//内存溢出
};

/************
将16进制字符串转为10进制数
example：
“121314”转为18，19，20
u8* pdata   输入16进制字符串的首地址
u16 length  需要转换的字符串的个数
u8* pout    输出数据的首地址
*************/
void hexstrTonum(u8* pdata, u16 length, u8* pout);

/***********
u8* pdata 需要复制的首地址
u16 len   需要复制数据的长度
u8* pout  放置复制数据的首地址
注意：可能会出现内存溢出的情况
************/
void strCpy(u8* pdata, u16 len, u8* pout);

/*************
u8* pdata 需要设置内存状态的首地址
u16 len   需要设置内存的个数
u8 status 设置的内存状态
**************/
void memSet(u8* pdata, u16 len, u8 status);

/**************
const u8* pdata 获取字符串的个数，不带末尾的‘\0’
***************/
u16 Getstrnum(const u8* pdata);

/***************
u8* pdata 输入字符串的首地址
u16 len  输入字符串的长度
const u8* strMatch 需要匹配的字符串
u16 *loc 输出匹配字符的后面一个字符位置

****************/
u8 strMatch(u8* pdata, u16 len, const u8* strMatch, u16 *loc);


/*****************
将数据转为字符串
u32 data 输入的数据
u8 len  需要输出字符数据的长度
u8 *pout 数据字符串的放置的位置
example：
data 12
len 3
pout：“012”
*****************/
void decTostr(u32 data, u8 len, u8 *pout);

#endif 