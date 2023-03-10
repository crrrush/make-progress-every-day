
// 矩阵转置
// 链接：https://www.nowcoder.com/questionTerminal/351b3d03e410496ab5a407b7ca3fd841
// 来源：牛客网

// KiKi有一个矩阵，他想知道转置后的矩阵（将矩阵的行列互换得到的新矩阵称为转置矩阵），请编程帮他解答。

// 输入描述:

// 第一行包含两个整数n和m，表示一个矩阵包含n行m列，用空格分隔。 (1≤n≤10,1≤m≤10)

// 从2到n+1行，每行输入m个整数（范围-231~231-1），用空格分隔，共输入n*m个数，表示第一个矩阵中的元素。



// 输出描述:

// 输出m行n列，为矩阵转置后的结果。每个数后面有一个空格。

// 示例1
// 输入

// 2 3
// 1 2 3
// 4 5 6

// 输出

// 1 4 
// 2 5 
// 3 6 

#include<stdio.h>

void verse_matrix(int(*p)[10])
{
    int i = 0, j = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = i; j < 10; j++)
        {
            int tmp = *(*(p + i) + j);
            *(*(p + i) + j) = *(*(p + j) + i);
            *(*(p + j) + i) = tmp;
        }
    }
}


int main()
{
    int arr[10][10] = { 0 };
    int n = 0, m = 0;
    int i = 0, j = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    verse_matrix(arr);

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }



    return 0;
}