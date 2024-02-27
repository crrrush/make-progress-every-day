


// 1209. 删除字符串中的所有相邻重复项 II
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii/description/
// 给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

// 你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

// 在执行完所有删除操作后，返回最终得到的字符串。

// 本题答案保证唯一。

 

// 示例 1：

// 输入：s = "abcd", k = 2
// 输出："abcd"
// 解释：没有要删除的内容。
// 示例 2：

// 输入：s = "deeedbbcccbdaa", k = 3
// 输出："aa"
// 解释： 
// 先删除 "eee" 和 "ccc"，得到 "ddbbbdaa"
// 再删除 "bbb"，得到 "dddaa"
// 最后删除 "ddd"，得到 "aa"
// 示例 3：

// 输入：s = "pbbcggttciiippooaais", k = 2
// 输出："ps"
 

// 提示：

// 1 <= s.length <= 10^5
// 2 <= k <= 10^4
// s 中只含有小写英文字母。


class Solution {
public:
    string removeDuplicates(string s, int k) {
        list<pair<char, int>> st;
        for(const auto& e : s)
        {
            if(st.empty())
            {
                st.push_back(make_pair(e, 1));
            }
            else if(st.back().first == e)
            {
                ++st.back().second;
            }
            else
            {
                st.push_back(make_pair(e, 1));
            }

            while(!st.empty() && st.back().second == k) st.pop_back();
        }
        
        s.clear();
        for(auto& e : st)
        {
            while(e.second--) s += e.first;
        }
        return s;
    }
};

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         stack<pair<char, int>> st;
//         for(const auto& e : s)
//         {
//             if(st.empty())
//             {
//                 st.push(make_pair(e, 1));
//             }
//             else if(st.top().first == e)
//             {
//                 ++st.top().second;
//             }
//             else
//             {
//                 st.push(make_pair(e, 1));
//             }

//             while(!st.empty() && st.top().second == k) st.pop();
//         }
        
//         s.clear();
//         while(!st.empty())
//         {
//             while(st.top().second--) s += st.top().first;
//             st.pop();
//         }

//         reverse(s.begin(), s.end());
//         return s;
//     }
// };

// class Solution {
// public:
//     string removeDuplicates(string s, int k) {
//         list<char> l(s.begin(), s.end());
//         while(true)
//         {
//             auto it = l.begin();
//             auto left = it;
//             int cnt = 0;
//             size_t len = l.size();
//             while(it != l.end())
//             {
//                 if(cnt == k)
//                 {
//                     it = l.erase(left, it);
//                     cnt = 1;
//                     left = it;
//                 }
//                 else if(cnt != k && *left == *it)
//                 {
//                     ++cnt;
//                 }
//                 else
//                 {
//                     left = it;
//                     cnt = 1;
//                 }

//                 ++it;
//             }
//             // cout<<endl;
//             if(cnt == k) it = l.erase(left, it);

//             if(len == l.size()) break;
//         }

//         return string(l.begin(), l.end());
//     }
// };