
// 有序序列判断

// 链接：https://www.nowcoder.com/questionTerminal/22e87f8a8d764a6582710f38d1b40c6e
// 来源：牛客网

// 输入一个整数序列，判断是否是有序序列，有序，指序列中的整数从小到大排序或者从大到小排序(相同元素也视为有序)。

// 数据范围： 3≤n≤50 3≤n≤50  序列中的值都满足 1≤val≤100 1≤val≤100 

// 输入描述:

// 第一行输入一个整数N(3≤N≤50)。
// 第二行输入N个整数，用空格分隔N个整数。



// 输出描述:

// 输出为一行，如果序列有序输出sorted，否则输出unsorted。

// 示例1
// 输入

// 5
// 1 6 9 22 30

// 输出

// sorted

// 示例2
// 输入

// 5
// 3 4 7 2 10

// 输出

// unsorted

// 示例3
// 输入

// 5
// 1 1 1 1 1

// 输出

// sorted


#include<stdio.h>

int judge_sort(int* p, int x)
{
	int i = 0;
	if (*(p + i) <= *(p + i + 1))
	{
		for (i = 1; i < x - 1; i++)
		{
			if (*(p + i) > *(p + i + 1))
			{
				return 0;
			}
		}
	}
	else
	{
		for (i = 1; i < x - 1; i++)
		{
			if (*(p + i) < *(p + i + 1))
			{
				return 0;
			}
		}
	}
	return 1;
}


int main()
{
	int arr[50] = { 0 };
	int n = 0;

	scanf("%d", &n);
    
    
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	if (judge_sort(arr, n))
		printf("sorted\n");
	else
		printf("unsorted\n");


	return 0;
}