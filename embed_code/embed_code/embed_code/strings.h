#ifndef _SORT_H_
#include "common.h"
/*****************************************
���ã�
�ַ����Ĵ���
*****************************************/
enum str_err
{
	Error = 0,
	Ok = 1,
	Memory_overflow = 2,//�ڴ����
};

/************
��16�����ַ���תΪ10������
example��
��121314��תΪ18��19��20
u8* pdata   ����16�����ַ������׵�ַ
u16 length  ��Ҫת�����ַ����ĸ���
u8* pout    ������ݵ��׵�ַ
*************/
void hexstrTonum(u8* pdata, u16 length, u8* pout);

/***********
u8* pdata ��Ҫ���Ƶ��׵�ַ
u16 len   ��Ҫ�������ݵĳ���
u8* pout  ���ø������ݵ��׵�ַ
ע�⣺���ܻ�����ڴ���������
************/
void strCpy(u8* pdata, u16 len, u8* pout);

/*************
u8* pdata ��Ҫ�����ڴ�״̬���׵�ַ
u16 len   ��Ҫ�����ڴ�ĸ���
u8 status ���õ��ڴ�״̬
**************/
void memSet(u8* pdata, u16 len, u8 status);

/**************
const u8* pdata ��ȡ�ַ����ĸ���������ĩβ�ġ�\0��
***************/
u16 Getstrnum(const u8* pdata);

/***************
u8* pdata �����ַ������׵�ַ
u16 len  �����ַ����ĳ���
const u8* strMatch ��Ҫƥ����ַ���
u16 *loc ���ƥ���ַ��ĺ���һ���ַ�λ��

****************/
u8 strMatch(u8* pdata, u16 len, const u8* strMatch, u16 *loc);


/*****************
������תΪ�ַ���
u32 data ���������
u8 len  ��Ҫ����ַ����ݵĳ���
u8 *pout �����ַ����ķ��õ�λ��
example��
data 12
len 3
pout����012��
*****************/
void decTostr(u32 data, u8 len, u8 *pout);

#endif 