#define _CRT_SECURE_NO_WARNINGS


//���ӣ�https ://www.nowcoder.com/questionTerminal/8f5b923683b94e549880e3c8370e3e55
//��Դ��ţ����
//
//��������һ������Ϊlen��1 <= len < 30�����ַ�����������һ�������� m��1 <= m <= len���������ַ����дӵ� m ���ַ���ʼ��ʣ��ȫ���ַ����Ƴ�Ϊ��һ���ַ���������������ַ��������Ҫ����ָ�봦���ַ�����

#include <iostream>
using namespace std;

int main() {
    //int a, b;
    char str[30] = { 0 };
    int m = 0;
    while (cin >> str >> m) { // ע�� while ������ case
        char* p = str;
        while (m--)
            p++;
        cout << --p << endl;
    }
}