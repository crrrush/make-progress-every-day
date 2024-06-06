

// 227. 基本计算器 II
// https://leetcode.cn/problems/basic-calculator-ii/description/
// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

// 整数除法仅保留整数部分。

// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内。

// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

 

// 示例 1：

// 输入：s = "3+2*2"
// 输出：7
// 示例 2：

// 输入：s = " 3/2 "
// 输出：1
// 示例 3：

// 输入：s = " 3+5 / 2 "
// 输出：5
 

// 提示：

// 1 <= s.length <= 3 * 105
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
// s 表示一个 有效表达式
// 表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
// 题目数据保证答案是一个 32-bit 整数


class Solution {
public:
    // 简化
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        char lastch = 0;
        for(const auto& e : s)
        {
            if(e == ' ') continue;

            if(e >= '0' && e <= '9')
            {
                num *= 10;
                num += e - '0';
            }
            else
            {
                if(lastch == '*')
                {
                    num *= st.top();
                    st.pop();
                }
                else if(lastch == '/')
                {
                    num = st.top() / num;
                    st.pop();
                }
                else if(lastch == '-')
                {
                    num = -num;
                }
                
                st.push(num);
                num = 0;
                lastch = e;
            }
        }
        
        if(lastch == '*')
        {
            num *= st.top();
            st.pop();
        }
        else if(lastch == '/')
        {
            num = st.top() / num;
            st.pop();
        }
        else if(lastch == '-')
        {
            num = -num;
        }

        while(!st.empty())
        {
            num += st.top();
            st.pop();
        }

        return num;
    }
};

// class Solution {
// public:
//     int calculate(string s) {
//         stack<int> sti;
//         stack<char> stc;
//         unordered_map<char, function<int(const int&, const int&)> > hashFunc = 
//         {
//             {'*', [](const int& x, const int& y){return x * y;}},
//             {'+', [](const int& x, const int& y){return x + y;}},
//             {'-', [](const int& x, const int& y){return x - y;}},
//             {'/', [](const int& x, const int& y){return x / y;}}
//         };

//         int num = 0;
//         for(const auto& e : s)
//         {
//             if(e == ' ') continue;

//             if(e >= '0' && e <= '9')
//             {
//                 num *= 10;
//                 num += e - '0';
//             }
//             else
//             {
//                 if(!stc.empty() && (stc.top() == '*' || stc.top() == '/'))
//                 {
//                     num = hashFunc[stc.top()](sti.top(), num);
//                     stc.pop();
//                     sti.pop();
//                 }
//                 if(!stc.empty() && stc.top() == '-')
//                 {
//                     stc.top() = '+';
//                     sti.push(-num);
//                 }
//                 else
//                     sti.push(num);

//                 // cout<<num<<" ";
//                 // cout<<e<<" ";
//                 num = 0;
//                 stc.push(e);
//             }
//         }

//         // if(!stc.empty() && (stc.top() == '*' || stc.top() == '/'))
//         // {
//         //     num = hashFunc[stc.top()](sti.top(), num);
//         //     stc.pop();
//         //     sti.pop();
//         // }

//         while(!sti.empty() && !stc.empty())
//         {
//             num = hashFunc[stc.top()](sti.top(), num);
//             sti.pop();
//             stc.pop();
//         }

//         return num;
//     }
// };


