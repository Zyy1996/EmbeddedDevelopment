#ifndef _CHARACTER_HANDLING_H_
#define _CHARACTER_HANDLING_H_
#include "common.h"


extern u8 revData[256];


//����ƥ����ַ���
u8 find_strs(const char *p, u8 location, u8 length, const char * matched_character, u8 *endlocation);

//���ڴ��������
void mem_reset(u8 *p, u8 location, u8 num);

//��16�����ַ���ת��Ϊ10��������
void convert_HexToStr(u8 *pdata, u8 location, u8 number, u8 *pout, u8 start);

 //��16�����ַ�����Ϊ10�������֣�����1��
void convert_strHexToDec(u8 *p, u8 location, u8 number, u8 *pout);

//�ӿ�ʼλ�ã���Ⲣ��ȡָ�������������ַ���
u8 get_strDec(u8 *p, u8 location, u8 length, u8 *pout, u8 num);

//������ת��Ϊ�ַ���
void convert_decToStr(u32 number, u8 *pout, u8 num);


//���ַ���ת��Ϊ����
//��1231��ת��Ϊ����1231
void convert_StrToDec(u8 * pdata, u8 location, u32 *data, u8 num);

#endif