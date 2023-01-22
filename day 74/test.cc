
// 争夺前五名
// 链接：https://www.nowcoder.com/questionTerminal/cd052308a1c44a88ad00255f312c3e14
// 来源：牛客网

// 期中考试开始了，大家都想取得好成绩，争夺前五名。从键盘输入 n 个学生成绩，输出每组排在前五高的成绩。

// 数据范围： 5≤n≤50 5≤n≤50  ，成绩采取百分制并不会出现负数

// 输入描述:

// 两行，第一行输入一个整数，表示n个学生（>=5），第二行输入n个学生成绩（整数表示，范围0~100），用空格分隔。



// 输出描述:

// 一行，输出成绩最高的前五个，用空格分隔。

// 示例1
// 输入

// 6
// 99 45 78 67 72 88

// 输出

// 99 88 78 72 67

// 示例2
// 输入

// 5
// 10 20 30 40 50

// 输出

// 50 40 30 20 10


#include<stdio.h>


void Rank(int a[], int flag)
{
    int i = 0, j = 0;
    for (i = 0; i <= flag; i++)
    {
        for (j = 0; j <= flag; j++)
        {
            if (a[i] > a[j])
            {
                int mid = a[i];
                a[i] = a[j];
                a[j] = mid;
            }

        }


    }
}

int main()
{
    int arr[50] = { 0 };
    int n = 0;
    int i = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    

    Rank(arr, n - 1);


    for (i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}