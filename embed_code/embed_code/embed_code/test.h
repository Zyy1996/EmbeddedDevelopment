#pragma once
#ifndef _TEST_H_
#include "common.h"
/*************************
测试头文件
**************************/


//位域使用模板
typedef union bc95
{
	u8 data;
	struct bc95{
		u8 a0 : 1;
		u8 a1 : 1;
		u8 a2 : 1;
		u8 a3 : 1;
		u8 a4 : 1;
		u8 a5 : 1;
		u8 a6 : 1;
		u8 a7 : 1;
	}bc95_bit;
}bc95_t;

#endif
