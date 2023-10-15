/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-15 19:20:46
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-15 19:21:11
 * @FilePath: \every-little-progress\day 328\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 762. 二进制表示中质数个计算置位
// https://leetcode.cn/problems/prime-number-of-set-bits-in-binary-representation/description/
// 给你两个整数 left 和 right ，在闭区间 [left, right] 范围内，统计并返回 计算置位位数为质数 的整数个数。

// 计算置位位数 就是二进制表示中 1 的个数。

// 例如， 21 的二进制表示 10101 有 3 个计算置位。
 

// 示例 1：

// 输入：left = 6, right = 10
// 输出：4
// 解释：
// 6 -> 110 (2 个计算置位，2 是质数)
// 7 -> 111 (3 个计算置位，3 是质数)
// 9 -> 1001 (2 个计算置位，2 是质数)
// 10-> 1010 (2 个计算置位，2 是质数)
// 共计 4 个计算置位为质数的数字。
// 示例 2：

// 输入：left = 10, right = 15
// 输出：5
// 解释：
// 10 -> 1010 (2 个计算置位, 2 是质数)
// 11 -> 1011 (3 个计算置位, 3 是质数)
// 12 -> 1100 (2 个计算置位, 2 是质数)
// 13 -> 1101 (3 个计算置位, 3 是质数)
// 14 -> 1110 (3 个计算置位, 3 是质数)
// 15 -> 1111 (4 个计算置位, 4 不是质数)
// 共计 5 个计算置位为质数的数字。
 

// 提示：

// 1 <= left <= right <= 106
// 0 <= right - left <= 104


class Solution {
public:
    int countOne(const int& val)
    {
        int cnt = 0;
        for(int i = 0;i < 32;++i) if(val & (1 << i)) ++cnt;
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        static vector<int> sv;
        if(sv.empty())
        {
            sv.resize(33, 0);
            sv[2]  = 1;
            sv[3]  = 1;
            sv[5]  = 1;
            sv[7]  = 1;
            sv[11]  = 1;
            sv[13]  = 1;
            sv[17]  = 1;
            sv[19]  = 1;
            sv[23]  = 1;
            sv[29]  = 1;
            sv[31]  = 1;
        }

        int cnt = 0;
        while(left <= right) if(sv[countOne(left++)]) ++cnt;

        return cnt;
    }
};