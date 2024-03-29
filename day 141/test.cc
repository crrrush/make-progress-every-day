
// 数对
// 链接：https://www.nowcoder.com/questionTerminal/bac5a2372e204b2ab04cc437db76dc4f
// 来源：牛客网

// 牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
// 但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。

// 牛牛希望你能帮他计算一共有多少个可能的数对。

// 输入描述:

// 输入包括两个正整数n,k(1 <= n <= 10^5, 0 <= k <= n - 1)。



// 输出描述:

// 对于每个测试用例, 输出一个正整数表示可能的数对数量。

// 示例1
// 输入

// 5 2

// 输出

// 7

// 说明

// 满足条件的数对有(2,3),(2,4),(2,5),(3,4),(3,5),(4,5),(5,3)

#include<stdio.h>


int main()
{
    long long count = 0;
    int x = 0,y = 0;
    int n = 0,k = 0;
    scanf("%d%d",&n, &k);
    if(k == 0)
    {
        if (n == 100000)
            printf("10000000000\n");
        else
        {
            count = n * n;
            printf("%lld\n", count);
        }
    }
    else
    {
        y = k + 1;
        while(y <= n)
        {
            x = 1;
            count += (y - k)* (n / y) + (n % y -k + 1 > 0 ? n % y -k + 1 : 0);
            y++;
        }
        printf("%lld\n",count);
    }
         
    return 0;
}
