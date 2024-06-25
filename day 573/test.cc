/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-25 22:31:26
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-25 22:32:07
 * @FilePath: \every-little-progress\day 573\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 17. 电话号码的字母组合
// https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
// 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



 

// 示例 1：

// 输入：digits = "23"
// 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 示例 2：

// 输入：digits = ""
// 输出：[]
// 示例 3：

// 输入：digits = "2"
// 输出：["a","b","c"]
 

// 提示：

// 0 <= digits.length <= 4
// digits[i] 是范围 ['2', '9'] 的一个数字。


class Solution {
    static const char* pchar[8];
    vector<string> ret;
    string path;
    
    // 写法更新 回溯
    void dfs(const string& digits, int pos)
    {
        if(pos == digits.size()) return ret.push_back(path);
        for(const char* p = pchar[digits[pos] - '0' - 2];*p != '\0';++p)
        {
            path.push_back(*p);
            dfs(digits, pos + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return ret;
        dfs(digits, 0);
        return ret;
    }
};

const char* Solution::pchar[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};


