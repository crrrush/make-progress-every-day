#define _CRT_SECURE_NO_WARNINGS



//ZJ16 数列的和 牛客
//描述
//
//数列的定义如下：数列的第一项为n，以后各项为前一项的平方根，求数列的前m项的和。
//输入描述：
//输入数据有多组，每组占一行，由两个整数n（n < 10000）和m(m < 1000)组成，n和m的含义如前所述。
//	输出描述：
//	对于每组输入数据，输出该数列的和，每个测试实例占一行，要求精度保留2位小数。


#include<stdio.h>
#include<math.h>

int main()
{
    double n = 0;
    double m = 0;
    while (scanf("%lf %lf", &n, &m) != EOF)
    {
        double count = 0.0;
        while (m--)
        {
            count += n;
            n = pow(n, 0.5);
        }

        printf("%.2lf\n", count);
    }

    return 0;
}