/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-29 09:53:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-29 09:54:18
 * @FilePath: \every-little-progress\day 577\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 784. 字母大小写全排列
// https://leetcode.cn/problems/letter-case-permutation/description/
// 给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。

// 返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。

 

// 示例 1：

// 输入：s = "a1b2"
// 输出：["a1b2", "a1B2", "A1b2", "A1B2"]
// 示例 2:

// 输入: s = "3z4"
// 输出: ["3z4","3Z4"]
 

// 提示:

// 1 <= s.length <= 12
// s 由小写英文字母、大写英文字母和数字组成


class Solution {
    vector<string> ret;
    // string path;

    void dfs(string& s, int pos)
    {
        while(pos < s.size() && 0 == isalpha(s[pos])) ++pos;
        if(pos >= s.size()) return ret.push_back(s);

        dfs(s, pos + 1);
        
        if(islower(s[pos]))
        {
            s[pos] = toupper(s[pos]);
            dfs(s, pos + 1);
            s[pos] = tolower(s[pos]);
        }
        else
        {
            s[pos] = tolower(s[pos]);
            dfs(s, pos + 1);
            s[pos] = toupper(s[pos]);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ret;
    }
};


