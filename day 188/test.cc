

// 14. 最长公共前缀
// https://leetcode.cn/problems/longest-common-prefix/
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

//     1 <= strs.length <= 200
//     0 <= strs[i].length <= 200
//     strs[i] 仅由小写英文字母组成



class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string com_pre = "";
        for(int i = 0;i < strs[0].size();++i)
        {
            char tmp = strs[0][i];
            bool flag = true;
            for(int j = 1;j < strs.size();++j)
            {
                if(tmp != strs[j][i])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
                com_pre += tmp;
            else
                break;
        }

        return com_pre;
    }
};