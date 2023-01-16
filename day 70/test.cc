// 计算平均成绩
// 链接：https://www.nowcoder.com/questionTerminal/30a28eb88c3f4e87be1a5b397ddd6fe2
// 来源：牛客网

// 从键盘输入5个学生的成绩（整数），求他们的平均成绩（浮点数，保留一位小数）。

// 输入描述:

// 一行，连续输入5个整数（范围0~100），用空格分隔。



// 输出描述:

// 一行，输出5个数的平均数（保留一位小数）。

// 示例1
// 输入

// 75 80 43 67 96

// 输出

// 72.2

#include<stdio.h>

int main()
{
    int s1 = 0,s2 = 0,s3 = 0,s4 = 0,s5 = 0;
    float average = 0.0;
    
    scanf("%d %d %d %d %d",&s1,&s2,&s3,&s4,&s5);
    
    average = (s1 + s2 + s3 + s4 + s5)/5.0;
    
    printf("%.1f",average);
    
    return 0;
}