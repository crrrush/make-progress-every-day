

// 最高分与最低分之差
// 链接：https://www.nowcoder.com/questionTerminal/e0e4f81dcd55408a8973f8033bbeb1d2
// 来源：牛客网

// 输入n个成绩，换行输出n个成绩中最高分数和最低分数的差。

// 输入描述:

// 两行，第一行为n，表示n个成绩，不会大于10000。

// 第二行为n个成绩（整数表示，范围0~100），以空格隔开。



// 输出描述:

// 一行，输出n个成绩中最高分数和最低分数的差。

// 示例1
// 输入

// 10
// 98 100 99 97 95 99 98 97 96 100

// 输出

// 5

#include<stdio.h>


int main()
{
    int arr[10000];
    int n = 0;
    int i = 0;
    
     scanf("%d", &n);
    
    int max = 0;
    int min = 100;
    
    for(i = 0;i < n;i++)
    {
        scanf("%d ",&arr[i]);
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    
    printf("%d\n",max - min);
    
    
    return 0;
}