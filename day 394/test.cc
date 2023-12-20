/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-20 13:49:18
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-20 13:49:35
 * @FilePath: \every-little-progress\day 394\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 367. 有效的完全平方数
// https://leetcode.cn/problems/valid-perfect-square/description/
// 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

// 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

// 不能使用任何内置的库函数，如  sqrt 。

 

// 示例 1：

// 输入：num = 16
// 输出：true
// 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
// 示例 2：

// 输入：num = 14
// 输出：false
// 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 

// 提示：

// 1 <= num <= 231 - 1


class Solution {
public:
    bool isPerfectSquare(int num) {
        for(unsigned long long i = 1;true;++i)
        {
            if(i * i == num) return true;
            else if(i * i > num) return false;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         for(int i = 1;true;++i)
//         {
//             int dev = num / i;
//             cout<<dev<<" "<<i<<endl;;
//             if(i * dev == num && i == dev) return true;
//             else if(i > dev) return false;
//         }
//         return false;
//     }
// };