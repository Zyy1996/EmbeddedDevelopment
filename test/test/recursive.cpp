#include <stdio.h>

int power1(int a, int y)
{
	if (y == 0) return 1;
	else return a * power1(a, y - 1);
}
