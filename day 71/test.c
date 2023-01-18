
// 进制A+B 
// 链接：https://www.nowcoder.com/questionTerminal/6187581174ac48278ca3bccf8d534897
// 来源：牛客网

// 输入一个十六进制数a，和一个八进制数b，输出a+b的十进制结果（范围-231~231-1）。

// 输入描述:

// 一行，一个十六进制数a，和一个八进制数b，中间间隔一个空格。



// 输出描述:

// 一行，a+b的十进制结果。

// 示例1
// 输入

// 0x12 05

// 输出

// 23


// 备注:

// 十六进制Hexadecimal一般以0x开头，例如0xFF。八进制Octal，一般以0开头，例如07。


#include<stdio.h>


int main()
{
    int a = 0,b = 0;
    
    scanf("%x %o",&a, &b);
    
    printf("%d",a + b);
    
    return 0;
}