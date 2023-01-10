#define _CRT_SECURE_NO_WARNINGS

//总成绩和平均分计算
//链接：https ://www.nowcoder.com/questionTerminal/0fa5132c156b434da4347ad051c4be22
//来源：牛客网
//
//依次输入一个学生的3科成绩，在屏幕上输出该学生的总成绩以及平均成绩。
//
//输入描述 :
//
//一行，3科成绩，成绩之间用一个空格隔开。
//
//
//
//输出描述:
//
//一行，总成绩和平均成绩（小数点后保留两位），用一个空格隔开。
//
//示例1
//输入
//
//79.5 80.0 98.0
//
//输出
//
//257.50 85.83



#include<stdio.h>

int main()
{

    float C = 0, M = 0, E = 0;
    scanf("%f%f%f", &C, &M, &E);

    float average = (C + M + E) / 3;

    printf("%.2f %.2f", C + M + E, average);


    return 0;
}