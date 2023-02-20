

// 温度转换
// 链接：https://www.nowcoder.com/questionTerminal/ba83647087b7447783fa2384da6b3d44
// 来源：牛客网

// 输入一个浮点数f, 表示华氏温度, 输出对应的摄氏温度c , c=5/9*(f-32)

// 输入描述:

// 输入一个浮点数f(1 <= f<= 100000)



// 输出描述:

// 输出浮点数,保留3位小数

// 示例1
// 输入

// 100

// 输出

// 37.778

#include<stdio.h>

int main()
{
    
    double f = 0.0;
    
    
    
    scanf("%lf",&f);
    
    double c = (5.0 / 9.0) *(f - 32.0);
    
    printf("%.3lf",c);
    
    return 0;
}
