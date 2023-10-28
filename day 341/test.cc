/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-28 11:54:31
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-28 11:54:45
 * @FilePath: \every-little-progress\day 341\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2413. 最小偶倍数
// https://leetcode.cn/problems/smallest-even-multiple/description/
// 给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。
 

// 示例 1：

// 输入：n = 5
// 输出：10
// 解释：5 和 2 的最小公倍数是 10 。
// 示例 2：

// 输入：n = 6
// 输出：6
// 解释：6 和 2 的最小公倍数是 6 。注意数字会是它自身的倍数。
 

// 提示：

// 1 <= n <= 150

class Solution {
public:
    int smallestEvenMultiple(int n) {
        for(int i = 1;true;++i) if((n * i) % 2 == 0) return n * i;
    }
};