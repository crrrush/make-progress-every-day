#define _CRT_SECURE_NO_WARNINGS


//
//HJ31 ���ʵ���    ţ����
//
//���ַ����е����е��ʽ��е��š�
//
//˵����
//
//1�����ɵ��ʵ��ַ�ֻ��26����д��СдӢ����ĸ��
//
//2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
//
//3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ��������ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
//4��ÿ�������20����ĸ��
//
//���ݷ�Χ���ַ����������� 1��n��10000 1 \le n \le 10000 \ 1��n��10000
//



#include<stdio.h>

void reverse_str(char* sta, char* end)
{
    while (sta < end)
    {
        char tmp = *sta;
        *sta = *end;
        *end = tmp;
        sta++;
        end--;
    }
}

int main()
{
    char str[10000] = "0";
    gets(str);

    char* p = str;
    while (*p)
        p++;
    reverse_str(str, --p);
    p = str;
    while (*p)
    {
        char* sta = p;
        while ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z'))
            p++;
        char* end = p - 1;
        reverse_str(sta, end);
        *p = ' ';
        p++;
    }

    printf("%s\n", str);

    return 0;
}

