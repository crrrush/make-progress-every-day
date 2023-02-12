
// 统计成绩
// 链接：https://www.nowcoder.com/questionTerminal/cad8d946adf64ab3b17a555d68dc0bba
// 来源：牛客网

// 输入n科成绩（浮点数表示），统计其中的最高分，最低分以及平均分。

// 数据范围：1≤n≤100 1≤n≤100  ， 成绩使用百分制且不可能出现负数

// 输入描述:

// 两行，

// 第1行，正整数n（1≤n≤100）

// 第2行，n科成绩（范围0.0~100.0），用空格分隔。



// 输出描述:

// 输出一行，三个浮点数，分别表示，最高分，最低分以及平均分（小数点后保留2位），用空格分隔。

// 示例1
// 输入

// 5
// 99.5 100.0 22.0 60.0 88.5

// 输出

// 100.00 22.00 74.00

#include<stdio.h>

int main()
{
    int n = 0;
    float arr[100] = { 0 };
    float sum = 0, min = 1000, max = 0;
    float* p = arr;

    scanf("%d", &n);
    int i = n - 1;
    while (i + 1)
    {
        scanf("%f", &arr[i--]);
    }

    for (i = n - 1; i + 1; i--)
    {
        if (max < *(p + i))
            max = *(p + i);
        if (min > *(p + i))
            min = *(p + i);
        sum += *(p + i);
    }


    printf("%.2f %.2f %.2f\n", max, min, sum / n);

    return 0;
}