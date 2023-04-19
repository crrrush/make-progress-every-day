

// 面试题 01.02. 判定是否互为字符重排

// https://leetcode.cn/problems/check-permutation-lcci/
// 给定两个由小写字母组成的字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

// 示例 1：

// 输入: s1 = "abc", s2 = "bca"
// 输出: true 

// 示例 2：

// 输入: s1 = "abc", s2 = "bad"
// 输出: false

// 说明：

//     0 <= len(s1) <= 100 
//     0 <= len(s2) <= 100 

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;

        vector<int> count1;
        vector<int> count2;
        count1.resize(26);
        count2.resize(26);

        for(int i = 0;i < s1.length();++i)
        {
            ++count1[s1[i] - 'a'];
            ++count2[s2[i] - 'a'];
        }

        for(int i = 0;i < 26;++i)
        {
            if(count1[i] != count2[i])
                return false;
        }

        return true;
    }
};