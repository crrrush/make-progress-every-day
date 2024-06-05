

// 844. 比较含退格的字符串
// https://leetcode.cn/problems/backspace-string-compare/description/
// 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。

// 注意：如果对空文本输入退格字符，文本继续为空。

 

// 示例 1：

// 输入：s = "ab#c", t = "ad#c"
// 输出：true
// 解释：s 和 t 都会变成 "ac"。
// 示例 2：

// 输入：s = "ab##", t = "c#d#"
// 输出：true
// 解释：s 和 t 都会变成 ""。
// 示例 3：

// 输入：s = "a#c", t = "b"
// 输出：false
// 解释：s 会变成 "c"，但 t 仍然是 "b"。
 

// 提示：

// 1 <= s.length, t.length <= 200
// s 和 t 只含有小写字母以及字符 '#'
 

// 进阶：

// 你可以用 O(n) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？


class Solution {
    const string& in_text(string& text)
    {
        int left = 0, right = 0;
        while(right < text.size())
        {
            if(text[right] == '#')
            {
                if(left > 0) --left;
            }
            else
            {
                text[left++] = text[right];
            }
            ++right;
        }
        text.erase(left);
        return text;
    }
public:
    bool backspaceCompare(string s, string t) {
        return in_text(s) == in_text(t);
    }
};

// class Solution {
//     void in_text(string& text)
//     {
//         int left = 0, right = 0;
//         while(right < text.size())
//         {
//             if(text[right] == '#')
//             {
//                 if(left > 0) --left;
//             }
//             else
//             {
//                 text[left++] = text[right];
//             }
//             ++right;
//         }
//         // cout<<left<<endl;
//         text.erase(left);
//     }
// public:
//     bool backspaceCompare(string s, string t) {
//         in_text(s);
//         in_text(t);
//         // cout<<s<<" "<<t;
//         return s == t;
//     }
// };



// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         string cs, ct;
//         for(const auto& e : s)
//         {
//             if('#' == e)
//             {
//                 if(!cs.empty()) cs.pop_back();
//             }
//             else
//                 cs.push_back(e);
//         }
//         for(const auto& e : t)
//         {
//             if('#' == e)
//             {
//                 if(!ct.empty()) ct.pop_back();
//             }
//             else
//                 ct.push_back(e);
//         }

//         return cs == ct;
//     }
// };

