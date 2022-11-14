#define _CRT_SECURE_NO_WARNINGS


//链接：https ://www.nowcoder.com/questionTerminal/8f5b923683b94e549880e3c8370e3e55
//来源：牛客网
//
//键盘输入一个长度为len（1 <= len < 30）的字符串，再输入一个正整数 m（1 <= m <= len），将此字符串中从第 m 个字符开始的剩余全部字符复制成为另一个字符串，并将这个新字符串输出。要求用指针处理字符串。

#include <iostream>
using namespace std;

int main() {
    //int a, b;
    char str[30] = { 0 };
    int m = 0;
    while (cin >> str >> m) { // 注意 while 处理多个 case
        char* p = str;
        while (m--)
            p++;
        cout << --p << endl;
    }
}