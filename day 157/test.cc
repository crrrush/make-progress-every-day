

// 面试题 01.01. 判定字符是否唯一
// https://leetcode.cn/problems/is-unique-lcci/description/

// 实现一个算法，确定一个字符串 s 的所有字符是否全都不同。

// 示例 1：

// 输入: s = "leetcode"
// 输出: false 

// 示例 2：

// 输入: s = "abc"
// 输出: true

// 限制：

//     0 <= len(s) <= 100 
//     s[i]仅包含小写字母
//     如果你不使用额外的数据结构，会很加分。

class Solution {
public:
    bool isUnique(string astr) {
        vector<int> v;
        v.resize(128);

        int i = 0;
        for(i = 0;i < astr.size();++i)
        {
            if(v[astr[i]] == 0)
                ++v[astr[i]];
            else
                return false;
        }
        
        return true;
    }
};