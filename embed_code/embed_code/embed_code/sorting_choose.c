#include "sorting.h"

/*****************
选择排序法
T* a ：数组首地址
u16 len ：数字个数
时间复杂度：O(n^2)
******************/
void choose_sort(T* a, u16 len )
{
	u16 i, j;
	T temp;
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
		{		
			if (a[i] > a[i + 1])
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}

/*****************
冒泡排序法
T* a ：数组首地址
u16 len ：数字个数
时间复杂度：O(n^2)
******************/
void bubble_sort(T* a, u16 len)
{
	u16 i, j;
	T temp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
}

/*****************
插入排序法
T* a ：数组首地址
u16 len ：数字个数
时间复杂度：O(n^2)
******************/
void insert_sort(T* a, u16 len)
{
	u16 i, j,t;
	T temp;
	for (i = 1; i < len; i++)
	{
		j = i;
		while (j)
		{
			j--;
			if (j == 0)
			{
				temp = a[i];
				for (t = i; t > 0; t--)
				{
					a[t] = a[t - 1];
				}
				a[0] = temp;
				break;
			}
			if (a[j] < a[i])
			{
				temp = a[i];
				for (t = i; t > j+1; t--)
				{
					a[t] = a[t - 1];
				}
				a[j+1] = temp;
				break;
			}
		}
	}
}


