

// 680. 验证回文串 II
// https://leetcode.cn/problems/valid-palindrome-ii/
// 给你一个字符串 s，最多 可以从中删除一个字符。

// 请你判断 s 是否能成为回文字符串：如果能，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：s = "aba"
// 输出：true

// 示例 2：

// 输入：s = "abca"
// 输出：true
// 解释：你可以删除字符 'c' 。

// 示例 3：

// 输入：s = "abc"
// 输出：false

 

// 提示：

//     1 <= s.length <= 105
//     s 由小写英文字母组成


class Solution {
    bool validPalindrome_(string& s, size_t l, size_t r)
    {
        while(l < r) if(s[l++] != s[r--]) return false;
        
        return true;
    }
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        int flag = 1;
        while(l <= r)
        {
            if(s[l] != s[r]) return validPalindrome_(s, l + 1, r) || validPalindrome_(s, l, r -1);

            --r;
            ++l;
        }


        return true;
    }
};
