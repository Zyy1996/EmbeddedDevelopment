#include "strings.h"
#include "sorting.h"
#include "test.h"
#include "checkout.h"
#include <stdio.h>

u8* p = "6801aaaaaaaaaaaaaa80000003010203336116";
u8 buf[128] = { 0 };

//u8* e;
int main(void)
{
	u32 da = 121;
	u16 data = 0;
	decTostr(da, 5, buf);
	printf("%s\r\n", buf);
	decTostr(12, 5, buf);
	printf("%s\r\n", buf);
	decTostr(34, 5, buf);
	printf("%s\r\n", buf);
	getchar();
	return 1;
}

