

// 字符逆序
// 链接：https://www.nowcoder.com/questionTerminal/cc57022cb4194697ac30bcb566aeb47b
// 来源：牛客网

// 将一个字符串str的内容颠倒过来，并输出。

// 数据范围：1≤len(str)≤10000 1≤len(str)≤10000 

// 输入描述:

// 输入一个字符串，可以有空格



// 输出描述:

// 输出逆序的字符串

// 示例1
// 输入

// I am a student

// 输出

// tneduts a ma I

// 示例2
// 输入

// nowcoder

// 输出

// redocwon


#include<stdio.h>

void reverse(char* string)

{
    char* start = string;
    while (*(string + 1) != '\0')
        string++;
    while (string > start)
    {
        char change = *string;
        *string = *(string - 1);
        *(string - 1) = change;
        string--;
    }
    if (*(start + 1) != '\0')
    {
        reverse(start + 1);
    }
}

int main()
{
    char str[10000]="";
    char *p=str;
    
    //while((*p++ = getchar()) != '\n')
    //     ;
    
    //*(p - 1) = '\0';
    
    gets(str);
    
    reverse(str);
    
    printf("%s\n",str);
    
    return 0;
}