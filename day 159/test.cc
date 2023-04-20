// 面试题 01.04. 回文排列


// https://leetcode.cn/problems/palindrome-permutation-lcci/description/
// 给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。

// 回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。

// 回文串不一定是字典当中的单词。

 

// 示例1：

// 输入："tactcoa"
// 输出：true（排列有"tacocat"、"atcocta"，等等）



class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count;
        count.resize(128);

        for(int i = 0;i < s.size();++i)
            ++count[s[i]];
        
        int flag = 0;
        for(int i = 0;i < 128;++i)
        {
            if(count[i] % 2)
                ++flag;
        }

        if(flag >= 2)
            return false;
        else
            return true;
    }
};