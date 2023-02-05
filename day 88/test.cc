
// 牛牛的字符矩形
// 链接：https://www.nowcoder.com/questionTerminal/2dbf0151eb71402e968a2a8e59092568
// 来源：牛客网

// 牛牛尝试用键盘读入一个字符，然后在屏幕上显示用这个字符组成的 3*3 的矩形。

// 输入描述:

// 一行读入一个 char 类型的字符。



// 输出描述:

// 输出这个字符组成的 3*3 矩形。

// 示例1
// 输入

// #

// 输出

// ###
// ###
// ###

#include<stdio.h>


int main()
{
    char ch = 0;//开辟空间存放字符数据
    
    ch = getchar();
    
    int i = 0,j = 0;
    for(i = 0;i < 3;i++,printf("\n"))//循环打印
    {
        for(j = 0;j < 3;j++)
        {
            printf("%c",ch);
        }
    }
    
    
    return 0;
}