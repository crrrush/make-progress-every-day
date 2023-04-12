
// 挑7
// 链接：https://www.nowcoder.com/questionTerminal/ba241b85371c409ea01ac0aa1a8d957b
// 来源：牛客网

// 输出 1到n之间 的与 7 有关数字的个数。
// 一个数与7有关是指这个数是 7 的倍数，或者是包含 7 的数字（如 17 ，27 ，37 ... 70 ，71 ，72 ，73...）

// 数据范围： 1≤n≤30000 1≤n≤30000 

// 输入描述:

// 一个正整数 n 。( n 不大于 30000 )



// 输出描述:

// 一个整数，表示1到n之间的与7有关的数字个数。

// 示例1
// 输入

// 20

// 输出

// 3

// 说明

// 输入20，1到20之间有关的数字包括7,14,17共3个。 

#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    
    int res = 0;
    for(int i = 7;i <= n;++i)
    {
        if(i % 7 == 0)
            ++res;
        else
        {
            for(int j = i;j > 1;j /= 10)
            {
                if(j % 10 == 7)
                {
                    ++res;
                    break;
                }
            }
        }
    }

    cout << res << endl;

    return 0;   
}
