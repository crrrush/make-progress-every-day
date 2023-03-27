

// 获取字符串长度
// 链接：https://www.nowcoder.com/questionTerminal/9a2d212d23f5436c80607d5e68c6d12a
// 来源：牛客网

// 键盘输入一个字符串，编写代码获取字符串的长度并输出，要求使用字符指针实现。

// 输入描述:

// 键盘输入一个字符串



// 输出描述:

// 输出字符串的长度

// 示例1
// 输入

// helloworld

// 输出

// 10

#include <iostream>
using namespace std;

int my_strlen(char* str)
{
    int len = 0;
    while(*str++)
        len++;
    return len;
}

int main() {

    char str[100] = { 0 };
    cin.getline(str, sizeof(str));

    // write your code here......
    printf("%d\n",my_strlen(str));

    return 0;
}