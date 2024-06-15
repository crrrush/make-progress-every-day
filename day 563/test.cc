/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-15 17:21:49
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-15 17:22:14
 * @FilePath: \every-little-progress\day 563\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 50. Pow(x, n)
// https://leetcode.cn/problems/powx-n/description/
// 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

 

// 示例 1：

// 输入：x = 2.00000, n = 10
// 输出：1024.00000
// 示例 2：

// 输入：x = 2.10000, n = 3
// 输出：9.26100
// 示例 3：

// 输入：x = 2.00000, n = -2
// 输出：0.25000
// 解释：2-2 = 1/22 = 1/4 = 0.25
 

// 提示：

// -100.0 < x < 100.0
// -231 <= n <= 231-1
// n 是一个整数
// 要么 x 不为零，要么 n > 0 。
// -104 <= xn <= 104


class Solution {
    double _myPow(double x, long long n)
    {
        if(0 == n) return 1.0;
        double tmp = _myPow(x, n / 2);
        return n % 2 == 0 ? tmp * tmp : tmp * tmp * x;
    }
public:
    // 快速幂
    double myPow(double x, int n) {
        if(n < 0) 
        {
            // long long num = -(long long)n;
            return 1 / _myPow(x, -(long long)n);
        }

        return _myPow(x, n);
    }
};

