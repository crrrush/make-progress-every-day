/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-01 13:32:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-01 13:34:12
 * @FilePath: \every-little-progress\day 345\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2269. 找到一个数字的 K 美丽值
// https://leetcode.cn/problems/find-the-k-beauty-of-a-number/
// 一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：

// 子字符串长度为 k 。
// 子字符串能整除 num 。
// 给你整数 num 和 k ，请你返回 num 的 k 美丽值。

// 注意：

// 允许有 前缀 0 。
// 0 不能整除任何值。
// 一个 子字符串 是一个字符串里的连续一段字符序列。

 

// 示例 1：

// 输入：num = 240, k = 2
// 输出：2
// 解释：以下是 num 里长度为 k 的子字符串：
// - "240" 中的 "24" ：24 能整除 240 。
// - "240" 中的 "40" ：40 能整除 240 。
// 所以，k 美丽值为 2 。
// 示例 2：

// 输入：num = 430043, k = 2
// 输出：2
// 解释：以下是 num 里长度为 k 的子字符串：
// - "430043" 中的 "43" ：43 能整除 430043 。
// - "430043" 中的 "30" ：30 不能整除 430043 。
// - "430043" 中的 "00" ：0 不能整除 430043 。
// - "430043" 中的 "04" ：4 不能整除 430043 。
// - "430043" 中的 "43" ：43 能整除 430043 。
// 所以，k 美丽值为 2 。
 

// 提示：

// 1 <= num <= 109
// 1 <= k <= num.length （将 num 视为字符串）


class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string n = to_string(num);
        auto it = n.begin();
        int cnt = 0;
        while(it + k - 1 != n.end())
        {
            string tmp(it, it + k);
            int tmpn = stoi(tmp);
            if(tmpn != 0 && num % tmpn == 0) ++cnt;
            ++it;
        }

        return cnt;
    }
};