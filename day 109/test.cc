

// 判断是不是字母
// 链接：https://www.nowcoder.com/questionTerminal/91a588dd4cd244bfa616f17603ec123c
// 来源：牛客网

// KiKi想判断输入的字符是不是字母，请帮他编程实现。

// 输入描述:

// 多组输入，每一行输入一个字符。



// 输出描述:

// 针对每组输入，输出单独占一行，判断输入字符是否为字母，输出内容详见输出样例。

// 示例1
// 输入

// A
// 6

// 输出

// A is an alphabet.
// 6 is not an alphabet.

#include<stdio.h>

int main()
{
    char p = 0;
    
    while((p = getchar()) != EOF)
    {
        getchar();
        if((p >= 65 && p <= 90) || (p >= 97 && p <= 122))
            printf("%c is an alphabet.\n",p);
        else
            printf("%c is not an alphabet.\n",p);
    }
    
    return 0;
}