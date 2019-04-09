#ifndef _CHARACTER_HANDLING_H_
#define _CHARACTER_HANDLING_H_
#include "common.h"


extern u8 revData[256];


//发现匹配的字符串
u8 find_strs(const char *p, u8 location, u8 length, const char * matched_character, u8 *endlocation);

//将内存区域归零
void mem_reset(u8 *p, u8 location, u8 num);

//将16进制字符串转换为10进制数字
void convert_HexToStr(u8 *pdata, u8 location, u8 number, u8 *pout, u8 start);

 //将16进制字符串变为10进制数字，迭代1次
void convert_strHexToDec(u8 *p, u8 location, u8 number, u8 *pout);

//从开始位置，检测并获取指定个数的数字字符串
u8 get_strDec(u8 *p, u8 location, u8 length, u8 *pout, u8 num);

//将数字转换为字符串
void convert_decToStr(u32 number, u8 *pout, u8 num);


//将字符串转换为数字
//“1231”转化为数字1231
void convert_StrToDec(u8 * pdata, u8 location, u32 *data, u8 num);

#endif