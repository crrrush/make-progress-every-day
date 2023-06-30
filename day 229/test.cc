


// 345. 反转字符串中的元音字母
// https://leetcode.cn/problems/reverse-vowels-of-a-string/
// 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。

// 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。

 

// 示例 1：

// 输入：s = "hello"
// 输出："holle"

// 示例 2：

// 输入：s = "leetcode"
// 输出："leotcede"

 

// 提示：

//     1 <= s.length <= 3 * 105
//     s 由 可打印的 ASCII 字符组成



class Solution {
    bool is_vowel(char& c)
    {
        switch(c)
        {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U': 
            return true;
        default:
            return false;
        }
    }
    void reverseVowels_(string& s, int& start, int& end)
    {
        while(end > start && !is_vowel(s[end])) --end;
        while(start < end && !is_vowel(s[start])) ++start;

        swap(s[start], s[end]);
        ++start;
        --end;
    }

public:
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        
        while(start < end) reverseVowels_(s, start, end);

        return s;
    }
};