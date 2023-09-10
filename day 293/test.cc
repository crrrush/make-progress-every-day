/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-10 14:03:57
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-10 14:04:47
 * @FilePath: \every-little-progress\day 293\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1768. 交替合并字符串
// https://leetcode.cn/problems/merge-strings-alternately/
// 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

// 返回 合并后的字符串 。

 

// 示例 1：

// 输入：word1 = "abc", word2 = "pqr"
// 输出："apbqcr"
// 解释：字符串合并情况如下所示：
// word1：  a   b   c
// word2：    p   q   r
// 合并后：  a p b q c r
// 示例 2：

// 输入：word1 = "ab", word2 = "pqrs"
// 输出："apbqrs"
// 解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
// word1：  a   b 
// word2：    p   q   r   s
// 合并后：  a p b q   r   s
// 示例 3：

// 输入：word1 = "abcd", word2 = "pq"
// 输出："apbqcd"
// 解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
// word1：  a   b   c   d
// word2：    p   q 
// 合并后：  a p b q c   d
 

// 提示：

// 1 <= word1.length, word2.length <= 100
// word1 和 word2 由小写英文字母组成

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        bool order = true;
        auto it1 = word1.begin(), it2 = word2.begin();
        while(it1 != word1.end() && it2 != word2.end())
        {
            if(order)
            {
                ans += *it1;
                ++it1;
                order = false;
            }
            else
            {
                ans += *it2;
                ++it2;
                order = true;
            }
        }
        while(it1 != word1.end())
        {
            ans += *it1;
            ++it1;
        }
        while(it2 != word2.end())
        {
            ans += *it2;
            ++it2;
        }

        return ans;
    }
};