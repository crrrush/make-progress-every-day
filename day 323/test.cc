/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-10 21:05:49
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-10 21:07:15
 * @FilePath: \every-little-progress\day 323\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1513. 仅含 1 的子串数
// https://leetcode.cn/problems/number-of-substrings-with-only-1s/description/
// 给你一个二进制字符串 s（仅由 '0' 和 '1' 组成的字符串）。

// 返回所有字符都为 1 的子字符串的数目。

// 由于答案可能很大，请你将它对 10^9 + 7 取模后返回。

 

// 示例 1：

// 输入：s = "0110111"
// 输出：9
// 解释：共有 9 个子字符串仅由 '1' 组成
// "1" -> 5 次
// "11" -> 3 次
// "111" -> 1 次
// 示例 2：

// 输入：s = "101"
// 输出：2
// 解释：子字符串 "1" 在 s 中共出现 2 次
// 示例 3：

// 输入：s = "111111"
// 输出：21
// 解释：每个子字符串都仅由 '1' 组成
// 示例 4：

// 输入：s = "000"
// 输出：0
 

// 提示：

// s[i] == '0' 或 s[i] == '1'
// 1 <= s.length <= 10^5

class Solution {
public:
    int comb(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += n--;
            sum %= 0x3B9ACA07;
        }
        return sum;
    }

    int numSub(string s) {
        int onelen = 0;
        int cnt = 0;
        for(const auto& e : s)
        {
            if(e == '1')
                ++onelen;
            else
            {
                // 计算这个子串能所有组合
                cnt += comb(onelen);
                onelen = 0;
            }
        }
        if(onelen)
        {
            // 计算这个子串能所有组合
            cnt += comb(onelen);
            cnt %= 0x2540BE407;
            onelen = 0;
        }

        return cnt;
    }
};