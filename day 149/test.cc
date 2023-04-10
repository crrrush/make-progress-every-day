
// 自守数

// 链接：https://www.nowcoder.com/questionTerminal/88ddd31618f04514ae3a689e83f3ab8e
// 来源：牛客网

// 自守数是指一个数的平方的尾数等于该数自身的自然数。例如：25^2 = 625，76^2 = 5776，9376^2 = 87909376。请求出n(包括n)以内的自守数的个数

// 数据范围： 1≤n≤10000 1≤n≤10000 




// 输入描述:

// int型整数



// 输出描述:

// n以内自守数的数量。

// 示例1
// 输入

// 6

// 输出

// 4

// 说明

// 有0，1，5，6这四个自守数      

// 示例2
// 输入

// 1

// 输出

// 2

// 说明

// 有0, 1这两个自守数     

#include <iostream>
using namespace std;


int main() {
    int res = 2;

    int n = 0;
    cin >> n;

    for(int i = 2;i <= n;++i)
    {
        int j = 1;
        while(j <= (i * i))
        {
            if((i * i) % j == i)
            {
                ++res;
                break;
            }

            j *= 10;
        }
    }

    cout << res << endl;

    return 0;
}
