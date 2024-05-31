/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-31 22:52:48
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-31 22:53:22
 * @FilePath: \every-little-progress\day 549\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 14. 最长公共前缀
// https://leetcode.cn/problems/longest-common-prefix/description/
// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

 

// 示例 1：

// 输入：strs = ["flower","flow","flight"]
// 输出："fl"
// 示例 2：

// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。
 

// 提示：

// 1 <= strs.length <= 200
// 0 <= strs[i].length <= 200
// strs[i] 仅由小写英文字母组成


class Solution {
    string comm_prefix(const string& s1, const string& s2)
    {
        int pos = 0;
        for(int i = 0;i < s1.length() && i < s2.length() && s2[i] == s1[i];++i) ++pos;
        return s1.substr(0, pos);
    }
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for(int i = 1;i < strs.size();++i)
        {
            prefix = comm_prefix(prefix, strs[i]);
            if(prefix.empty()) return prefix;
        }

        return prefix;
    }
};

// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         for(int i = 0;;++i)
//         {
//             bool flag = false;
//             for(const auto& s :strs)
//             {
//                 if(i >= s.length() || strs[0][i] != s[i])
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//             if(flag) return strs[0].substr(0, i);
//         }

//         return "";
//     }
// };
