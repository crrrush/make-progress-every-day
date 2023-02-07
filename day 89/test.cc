


// 实现四舍五入
// 将浮点数转换为整数类型，要求四舍五入。

// 输入描述:

// 随机输入的浮点数



// 输出描述:

// 四舍五入之后的整数

// 示例1
// 输入

// 14.99

// 输出

// 15

#include<stdio.h>

int main()
{

    float num1 = 0.0;

    scanf("%f", &num1);

    float num2 = 0.0;

    if (num1 >= 0)
    {
        while (num1 >= 1)
        {
            num2++;
            num1--;
        }

        if (num1 > 0.4)
        {
            num1 = 1.0;
        }
        else
        {
            num1 = 0.0;
        }

        printf("%.0f\n", num1 + num2);
    }
    else
    {
        while (num1 <= -1)
        {
            num2--;
            num1++;
        }

        if (num1 < -0.4)
        {
            num1 = -1.0;
        }
        else
        {
            num1 = 0.0;
        }

        printf("%.0f\n", num1 + num2);
    }

    return 0;
}