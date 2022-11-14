#define _CRT_SECURE_NO_WARNINGS


//
//HJ31 单词倒排    牛客网
//
//对字符串中的所有单词进行倒排。
//
//说明：
//
//1、构成单词的字符只有26个大写或小写英文字母；
//
//2、非构成单词的字符均视为单词间隔符；
//
//3、要求倒排后的单词间隔符以一个空格表示；如果原字符串中相邻单词间有多个间隔符时，倒排转换后也只允许出现一个空格间隔符；
//4、每个单词最长20个字母；
//
//数据范围：字符串长度满足 1≤n≤10000 1 \le n \le 10000 \ 1≤n≤10000
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

