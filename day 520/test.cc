/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-01 23:21:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-01 23:23:15
 * @FilePath: \every-little-progress\day 520\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 461. 汉明距离
// https://leetcode.cn/problems/hamming-distance/description/
// 两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

// 给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

 

// 示例 1：

// 输入：x = 1, y = 4
// 输出：2
// 解释：
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// 上面的箭头指出了对应二进制位不同的位置。
// 示例 2：

// 输入：x = 3, y = 1
// 输出：1
 

// 提示：

// 0 <= x, y <= 231 - 1


class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        while(x || y)
        {
            if((x % 2) ^ (y % 2)) ++cnt;
            x >>= 1;
            y >>= 1;
        }
        return cnt;
    }
};

