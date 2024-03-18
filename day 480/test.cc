/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-18 16:27:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-18 16:28:19
 * @FilePath: \every-little-progress\day 480\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 018. 验证回文串
// https://leetcode.cn/problems/XltzEq/description/
// 给定一个字符串 s ，验证 s 是否是 回文串 ，只考虑字母和数字字符，可以忽略字母的大小写。

// 本题中，将空字符串定义为有效的 回文串 。

 

// 示例 1:

// 输入: s = "A man, a plan, a canal: Panama"
// 输出: true
// 解释："amanaplanacanalpanama" 是回文串
// 示例 2:

// 输入: s = "race a car"
// 输出: false
// 解释："raceacar" 不是回文串
 

// 提示：

// 1 <= s.length <= 2 * 105
// 字符串 s 由 ASCII 字符组成
 

// 注意：本题与主站 125 题相同： https://leetcode-cn.com/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        // 空间复杂度O(n)
        string str;
        for(const auto& e : s)
        {
            if(isupper(e)) str += tolower(e);
            else if(islower(e)) str += e;
            else if(isdigit(e)) str += e;
        }

        int left = 0, right = str.size() - 1;
        while(left < right)
        {
            if(str[left++] != str[right--]) return false;
        }

        return true;
    }
};