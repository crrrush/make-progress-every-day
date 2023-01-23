
// 竞选社长 
// 链接：https://www.nowcoder.com/questionTerminal/45a30e3ef51040ed8a7674984d6d1553
// 来源：牛客网

// 假设你们社团要竞选社长，有两名候选人分别是A和B，社团每名同学必须并且只能投一票，最终得票多的人为社长.

// 输入描述:

// 一行，字符序列，包含A或B，输入以字符0结束。



// 输出描述:

// 一行，一个字符，A或B或E，输出A表示A得票数多，输出B表示B得票数多，输出E表示二人得票数相等。

// 示例1
// 输入

// ABBABBAAB0

// 输出

// B



#include<stdio.h>

int main()
{
    char arr[] = { 0 };
    
    scanf("%s",arr);
    
    int countA = 0;
    int countB = 0;
    
    char * p = arr;
    
    while(*p)
    {
        if(*p =='A')
            countA++;
        if(*p =='B')
            countB++;
        p++;
    }
    
    if(countA > countB)
        printf("A");
    else if(countA < countB)
        printf("B");
    else
        printf("E");
    
    return 0;
}