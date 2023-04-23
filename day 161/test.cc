
// 面试题 01.06. 字符串压缩

// https://leetcode.cn/problems/compress-string-lcci/
// 字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

// 示例1:

//  输入："aabcccccaaa"
//  输出："a2b1c5a3"

// 示例2:

//  输入："abbccd"
//  输出："abbccd"
//  解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。

// 提示：

//     字符串长度在[0, 50000]范围内。

class Solution
{
public:
    string compressString(string S)
    {
        string res;
        pair<char, int> p;
        p.first = S[0];
        p.second = 1;
        int i = 0;
        for (i = 1; i < S.length(); ++i)
        {
            if (S[i] == p.first)
                ++p.second;
            else
            {
                res += p.first;
                string in;
                while (p.second >= 1)
                {
                    in += '0' + (p.second % 10);
                    p.second /= 10;
                }
                reverse(in.begin(), in.end());
                res += in;
                // res += '0' + p.second;
                p.first = S[i];
                p.second = 1;
            }
        }
        res += p.first;
        string in;
        while (p.second >= 1)
        {
            in += '0' + (p.second % 10);
            p.second /= 10;
        }
        reverse(in.begin(), in.end());
        res += in;

        if (res.length() >= S.length())
            return S;
        else
            return res;
    }
};