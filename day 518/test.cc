/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-29 23:27:26
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-29 23:29:43
 * @FilePath: \every-little-progress\day 518\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 191. 位1的个数
// https://leetcode.cn/problems/number-of-1-bits/description/
// 编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中 
// 设置位
//  的个数（也被称为汉明重量）。

 

// 示例 1：

// 输入：n = 11
// 输出：3
// 解释：输入的二进制串 1011 中，共有 3 个设置位。
// 示例 2：

// 输入：n = 128
// 输出：1
// 解释：输入的二进制串 10000000 中，共有 1 个设置位。
// 示例 3：

// 输入：n = 2147483645
// 输出：30
// 解释：输入的二进制串 11111111111111111111111111111101 中，共有 30 个设置位。
 

// 提示：

// 1 <= n <= 231 - 1
 

// 进阶：

// 如果多次调用这个函数，你将如何优化你的算法？

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0)
        {
            if(n & 1) ++cnt;
            n >>= 1;
        }
        return cnt;
    }
};