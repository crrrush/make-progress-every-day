
// 数列 

// 链接：https://www.nowcoder.com/questionTerminal/1843c3b052984e3f98c68935ea3c0d79
// 来源：牛客网

// 某种特殊的数列a1, a2, a3, ...的定义如下：a1 = 1, a2 = 2, ... , an = 2 * an − 1 + an - 2 (n > 2)。

// 给出任意一个正整数k，求该数列的第k项模以32767的结果是多少？

// 输入描述:

// 第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。



// 输出描述:

// n行，每行输出对应一个输入。输出应是一个非负整数。

// 示例1
// 输入

// 2
// 1
// 8

// 输出

// 1
// 408


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<long long> a;
    a.push_back(1);
    a.push_back(2);

    while(n--)
    {
        int k = 0;
        cin >> k;
        while(k > a.size())
            a.push_back(((a[a.size() - 2] + 2 * a[a.size() - 1]) % 32767));
        
        cout << a[k - 1] << endl;
    }

    return 0;
}