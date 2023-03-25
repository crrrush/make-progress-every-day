
// 密码检查

// 链接：https://www.nowcoder.com/questionTerminal/f2fbd8f61c564ca0b5feaa63ab42dae5
// 来源：牛客网

// 小明同学最近开发了一个网站，在用户注册账户的时候，需要设置账户的密码，为了加强账户的安全性，小明对密码强度有一定要求：

// 1. 密码只能由大写字母，小写字母，数字构成；

// 2. 密码不能以数字开头；

// 3. 密码中至少出现大写字母，小写字母和数字这三种字符类型中的两种；

// 4. 密码长度至少为8

// 现在小明受到了n个密码，他想请你写程序判断这些密码中哪些是合适的，哪些是不合法的。

// 输入描述:

// 输入一个数n，接下来有n(n≤100)行，每行一个字符串，表示一个密码，输入保证字符串中只出现大写字母，小写字母和数字，字符串长度不超过100。



// 输出描述:

// 输入n行，如果密码合法，输出YES，不合法输出NO

// 示例1
// 输入

// 1
// CdKfIfsiBgohWsydFYlMVRrGUpMALbmygeXdNpTmWkfyiZIKPtiflcgppuR

// 输出

// YES


#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    int n = 0;
    char str[100] = "0";
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        int i = 0;
        int flagn = 0;
        int flagl = 0;
        int flagu = 0;
        int m = strlen(str);
        while(isalnum(str[i]))
        {
            if(isalpha(str[i]))
                flagn = 1;
            if(isupper(str[i]))
                flagu = 1;
            if(islower(str[i]))
                flagl = 1;
            i++;
        }
        if(i < m || m < 8)
        {
            printf("NO\n");
        }
        else if((flagl + flagn + flagu) < 2)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
    
    
    return 0;
}