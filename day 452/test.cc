/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-19 18:13:37
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-19 18:14:10
 * @FilePath: \every-little-progress\day 452\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 884. 两句话中的不常见单词
// https://leetcode.cn/problems/uncommon-words-from-two-sentences/description/
// 句子 是一串由空格分隔的单词。每个 单词 仅由小写字母组成。

// 如果某个单词在其中一个句子中恰好出现一次，在另一个句子中却 没有出现 ，那么这个单词就是 不常见的 。

// 给你两个 句子 s1 和 s2 ，返回所有 不常用单词 的列表。返回列表中单词可以按 任意顺序 组织。

 

// 示例 1：

// 输入：s1 = "this apple is sweet", s2 = "this apple is sour"
// 输出：["sweet","sour"]
// 示例 2：

// 输入：s1 = "apple apple", s2 = "banana"
// 输出：["banana"]
 

// 提示：

// 1 <= s1.length, s2.length <= 200
// s1 和 s2 由小写英文字母和空格组成
// s1 和 s2 都不含前导或尾随空格
// s1 和 s2 中的所有单词间均由单个空格分隔


class Solution {
    void split(vector<string>& vs, string& s)
    {
        auto left = s.begin();
        auto right = s.begin();
        while(right != s.end())
        {
            if(*right == ' ')
            {
                vs.push_back(string(left, right));
                ++right;
                left = right;
            }
            
            ++right;
        }
        vs.push_back(string(left, right));
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> words1, words2, res;
        split(words1, s1);
        split(words2, s2);

        unordered_map<string, int> hash1;
        unordered_map<string, int> hash2;
        for(const auto& e : words1) ++hash1[e];
        for(const auto& e : words2) ++hash2[e];

        for(const auto& [x, y] : hash1) if(hash2.find(x) == hash2.end() && y == 1) res.push_back(string(x));
        for(const auto& [x, y] : hash2) if(hash1.find(x) == hash1.end() && y == 1) res.push_back(string(x));

        return res;
    }
};