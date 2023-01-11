#define _CRT_SECURE_NO_WARNINGS

//计算三角形的周长和面积
//链接：https ://www.nowcoder.com/questionTerminal/109a44d649a142d483314e8a57e2c710
//来源：牛客网
//
//根据给出的三角形3条边a, b, c，计算三角形的周长和面积。
//
//数据范围： 0 < a, b, c≤100000 0 < a, b, c≤100000
//
//	输入描述 :
//
//一行，三角形3条边（能构成三角形），中间用一个空格隔开。
//
//
//
//输出描述:
//
//一行，三角形周长和面积（保留两位小数），中间用一个空格隔开，输出具体格式详见输出样例。
//
//示例1
//输入
//
//3 3 3
//
//输出
//
//circumference = 9.00 area = 3.90


#include<stdio.h>

#include<math.h>
int main()
{
	double a = 0.0, b = 0.0, c = 0.0;

	double circumference = 0.0;
	double area = 0.0;

	//输入
	scanf("%lf %lf %lf", &a, &b, &c);
	//计算
	circumference = a + b + c;
	double p = circumference / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	//输出
	printf("circumference=%.2lf area=%.2lf", circumference, area);

	return 0;
}
