/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-22 18:31:31
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-22 18:31:52
 * @FilePath: \every-little-progress\day 277\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1446. 连续字符
// https://leetcode.cn/problems/consecutive-characters/
// 给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

// 请你返回字符串 s 的 能量。

 

// 示例 1：

// 输入：s = "leetcode"
// 输出：2
// 解释：子字符串 "ee" 长度为 2 ，只包含字符 'e' 。
// 示例 2：

// 输入：s = "abbcccddddeeeeedcba"
// 输出：5
// 解释：子字符串 "eeeee" 长度为 5 ，只包含字符 'e' 。
 

// 提示：

// 1 <= s.length <= 500
// s 只包含小写英文字母。


class Solution {
public:
    int maxPower(string s) {
        char st = s.front();
        int tmp = 0;
        int max = 1;
        for(const auto& e : s)
        {
            if(st != e)
            {
                if(tmp > max) max = tmp;
                tmp = 0;
                st = e;
            }
            ++tmp;
        }
        if(tmp > max) max = tmp;

        return max; 
    }
};


// class Solution {
// public:
//     int maxPower(string s) {
//         stack<char> st;
//         int max = 1;
//         for(const auto& e : s)
//         {
//             if(!st.empty() && st.top() != e)
//             {
//                 if(st.size() > max) max = st.size();
//                 stack<char> tmp;
//                 st.swap(tmp);
//             }
//             st.push(e);
//         }
//         if(st.size() > max) max = st.size();
//         return max; 
//     }
// };

// class Solution {
// public:
//     int maxPower(string s) {
//         stack<char> st;
//         int max = 1;
//         st.push(s[0]);
//         for(int i = 1;i < s.length();++i)
//         {
//             if(!st.empty() && st.top() != s[i])
//             {
//                 if(st.size() > max) max = st.size();
//                 stack<char> tmp;
//                 st.swap(tmp);
//             }
//             st.push(s[i]);
//         }
//         if(st.size() > max) max = st.size();
        
//         return max; 
//     }
// };