/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-04 20:37:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-04 20:37:38
 * @FilePath: \every-little-progress\day 553\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1047. 删除字符串中的所有相邻重复项
// https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/
// 给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

// 在 S 上反复执行重复项删除操作，直到无法继续删除。

// 在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

 

// 示例：

// 输入："abbaca"
// 输出："ca"
// 解释：
// 例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
 

// 提示：

// 1 <= S.length <= 20000
// S 仅由小写英文字母组成。


class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for(const auto& e : s)
        {
            if(!st.empty() && e == st.back())
                st.pop_back();
            else
                st.push_back(e);
        }

        return st;
    }
};

