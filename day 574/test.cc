/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-26 19:16:51
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-26 19:17:23
 * @FilePath: \every-little-progress\day 574\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 22. 括号生成
// https://leetcode.cn/problems/generate-parentheses/description/
// 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

// 示例 1：

// 输入：n = 3
// 输出：["((()))","(()())","(())()","()(())","()()()"]
// 示例 2：

// 输入：n = 1
// 输出：["()"]
 

// 提示：

// 1 <= n <= 8


class Solution {
    vector<string> ret;
    string path;
    int st = 0;
    int cnt = 0;

    // 回溯
    void dfs(const int& n)
    {
        // cout<<st<<" ";
        if(cnt == n)
        {
            string tmp = path;
            while(tmp.size() < 2 * n) tmp += ')';
            // cout<<tmp<<"\n";
            return ret.push_back(tmp);
        }

        // 入栈和出栈
        path += '(';
        ++cnt;
        ++st;
        dfs(n);
        --st;
        --cnt;
        path.pop_back();

        if(st > 0)
        {
            path += ')';
            --st;
            dfs(n);
            ++st;
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        dfs(n);
        return ret;
    }
};

