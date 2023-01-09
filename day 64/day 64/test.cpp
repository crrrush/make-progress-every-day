#define _CRT_SECURE_NO_WARNINGS


//时间转换
//链接：https://www.nowcoder.com/questionTerminal/c4ae7bcac7f9491b8be82ee516a94899
//来源：牛客网
//
//给定秒数 seconds ，把秒转化成小时、分钟和秒。
//
//数据范围： 0 < seconds < 100000000 0 < seconds < 100000000
//
//	输入描述 :
//
//	一行，包括一个整数，即给定的秒数。
//
//
//
//输出描述:
//
//一行，包含三个整数，依次为输入整数对应的小时数、分钟数和秒数（可能为零），中间用一个空格隔开。
//
//示例1
//输入
//
//3661
//
//输出
//
//1 1 1

#include<stdio.h>

int main()//给定秒数 seconds ，把秒转化成小时、分钟和秒。 
{
	int sec = 0;

	scanf("%d", &sec);

	if (sec >= 3600)
	{
		printf("%d ", sec / 3603);
		sec %= 3600;
	}
	else
		printf("%d ", 0);


	if (sec >= 60)
	{
		printf("%d ", sec / 60);
		sec %= 60;
	}
	else
		printf("0 ");

	printf("%d", sec);

	return 0;
}