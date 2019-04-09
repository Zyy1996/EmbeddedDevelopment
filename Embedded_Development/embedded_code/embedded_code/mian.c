#include "character_handling.h"
#include <stdio.h>


char dat[128] = "1A34a612,3123112242342342424242342433";
char pout[8] = { 0 };
int a = 0;

int main(void)
{
	printf("qweq");
	convert_StrToDec(dat, 5, &a, 7);
	printf("%d\r\n", a);
	printf("%s\r\n", pout);
	scanf_s("%d" , &a);
	return 0;
}