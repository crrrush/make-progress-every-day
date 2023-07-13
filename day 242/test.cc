

// 1047. 删除字符串中的所有相邻重复项
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 S 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

// 示例：

// 输入："abbaca"
// 输出："ca"
// 解释：
// 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

 

// 提示：

//     1 <= S.length <= 20000
//     S 仅由小写英文字母组成。



class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for(const auto& e : s)
        {
            if(st.empty())
            {
                st += e;
            }
            else
            {
                if(st.back() == e) st.pop_back();
                else               st += e;
            }
        }

        return st;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         vector<char> st;
//         for(const auto& e : s)
//         {
//             if(st.empty())
//             {
//                 st.push_back(e);
//             }
//             else
//             {
//                 if(st.back() == e) st.pop_back();
//                 else               st.push_back(e);
//             }
//         }

//         return string(st.begin(), st.end());
//     }
// };

// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char> st;
//         for(const auto& e : s)
//         {
//             if(st.empty())
//             {
//                 st.push(e);
//             }
//             else
//             {
//                 if(st.top() == e) st.pop();
//                 else              st.push(e);
//             }
//         }

//         string res;
//         while(!st.empty())
//         {
//             res.push_back(st.top());
//             st.pop();
//         }
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };