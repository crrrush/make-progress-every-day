

// 剑指 Offer 05. 替换空格

// https://leetcode.cn/problems/ti-huan-kong-ge-lcof/

// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

// 示例 1：

// 输入：s = "We are happy."
// 输出："We%20are%20happy."

 

// 限制：

// 0 <= s 的长度 <= 10000



class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(const auto& e : s)
        {
            if(e == ' ')
                res += "%20";
            else
                res += e;
        }
        
        return res;
    }
};