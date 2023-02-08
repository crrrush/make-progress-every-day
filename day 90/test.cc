

// 牛牛的空格分隔
// 链接：https://www.nowcoder.com/questionTerminal/b2203c4a5c304536a7f577bc885de511
// 来源：牛客网

// 牛牛从键盘读入一个字符，一个整数，一个单精度浮点数，按顺序输出它们，并用空格分隔，浮点数保留 6 位小数。

// 输入描述:

// 读入一个字符，一个整数，一个单精度浮点数用换行符隔开，



// 输出描述:

// 按顺序输出字符、整数、单精度浮点数，用空格分隔，浮点数保留 6 位小数

// 示例1
// 输入

// a
// 1
// 1.23

// 输出

// a 1 1.230000


#include<stdio.h>


int main()
{
    char ch = 0;
    int num1 = 0;
    float num2 = 0.0;
    
    scanf("%c\n%d\n%f\n",&ch,&num1,&num2);
    
    printf("%c %d %.6f\n",ch,num1,num2);
    
    return 0;
}