
// 尼科彻斯定理
// 链接：https://www.nowcoder.com/questionTerminal/dbace3a5b3c4480e86ee3277f3fe1e85
// 来源：牛客网

// 验证尼科彻斯定理，即：任何一个整数m的立方都可以写成m个连续奇数之和。

// 例如：

// 1^3=1

// 2^3=3+5

// 3^3=7+9+11

// 4^3=13+15+17+19
// 输入一个正整数m（m≤100），将m的立方写成m个连续奇数之和的形式输出。
// 数据范围：1≤m≤100 1≤m≤100 
// 进阶：时间复杂度：O(m) O(m) ，空间复杂度：O(1) O(1) 



// 输入描述:

// 输入一个int整数



// 输出描述:

// 输出分解后的string

// 示例1
// 输入

// 6

// 输出

// 31+33+35+37+39+41


#include<stdio.h>


int main()
{
    int m = 0;
    
    scanf("%d",&m);
    
    //遍历查找
    int i = 0;
    for(i = 1;i < m*m*m;i += 2)
    {
        if(m*m*m == m*i + m*m - m)
        {
            for( int j = 0;j < m;j++)
            {
                printf("%d",i + 2*j);
                if(j < m - 1)
                    printf("+");
            }
        }
    }
    
    
    
    return 0;
}

