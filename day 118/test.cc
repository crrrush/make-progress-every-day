

// 有序序列合并

// 链接：https://www.nowcoder.com/questionTerminal/a9e943b0dab142759807d0cfb6863897
// 来源：牛客网

// 输入两个升序排列的序列，将两个序列合并为一个有序序列并输出。

// 数据范围： 1≤n,m≤1000 1≤n,m≤1000  ， 序列中的值满足 0≤val≤30000 0≤val≤30000 

// 输入描述:

// 输入包含三行，

// 第一行包含两个正整数n, m，用空格分隔。n表示第二行第一个升序序列中数字的个数，m表示第三行第二个升序序列中数字的个数。

// 第二行包含n个整数，用空格分隔。

// 第三行包含m个整数，用空格分隔。



// 输出描述:

// 输出为一行，输出长度为n+m的升序序列，即长度为n的升序序列和长度为m的升序序列中的元素重新进行升序序列排列合并。

// 示例1
// 输入

// 5 6
// 1 3 7 9 22
// 2 8 10 17 33 44

// 输出

// 1 2 3 7 8 9 10 17 22 33 44


#include<stdio.h>


void Init(int* p, int i)
{
    while (i--)
    {
        scanf("%d", p++);
    }
}


void Merge(int* pa, int* pb, int* pc,int a,int b)
{
    while (a--)
    {
        *pc++ = *pa++;
    }
    while (b--)
    {
        *pc++ = *pb++;
    }
}
void Merge_max(int* p, int num)
{
	
	int i = 0, j = 0;
	for (i = 0; i < num; i++)
	{
		for (j = i; j < num; j++)
		{
			
			if (*(p + i) > *(p + j))
			{
				int mid = *(p + i);
				*(p + i) = *(p + j);
				*(p + j) = mid;
			}
		}
	}
}
int main()
{
    int n = 0;
    int m = 0;
    //创建
    scanf("%d%d", &n, &m);

    int a[1000] = { 0 };
    int b[1000] = { 0 };
    int c[2000] = { 0 };

    //初始化
    Init(a, n);
    Init(b, m);

    //合并
    Merge(a, b, c, n, m);

    Merge_max(c, n + m);

    //打印
    for (int i = 0; i < (n + m); i++)
    {
        printf("%d ", c[i]);
    }

    return 0;
}
