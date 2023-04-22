

// 面试题 01.03. URL化

// https://leetcode.cn/problems/string-to-url-lcci/

// URL化。编写一种方法，将字符串中的空格全部替换为%20。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度。（注：用Java实现的话，请使用字符数组实现，以便直接在数组上操作。）

 

// 示例 1：

// 输入："Mr John Smith    ", 13
// 输出："Mr%20John%20Smith"

// 示例 2：

// 输入："               ", 5
// 输出："%20%20%20%20%20"

 

// 提示：

//     字符串长度在 [0, 500000] 范围内。


class Solution {
public:
    string& replaceSpaces(string& S, int length) {
        int SpaceNum = 0;
        int i = 0;
        for(i = 0;i < length;++i)
        {
            if(S[i] == ' ')
                ++SpaceNum;
        }

        int tmp = length - 1;
        for(i = length + 2 * SpaceNum - 1;tmp >= 0 && i >= 0;--i,--tmp)
        {
            if(S[tmp] != ' ')
                S[i] = S[tmp];
            else
            {
                S[i--] = '0';
                S[i--] = '2';
                S[i] = '%';
            }
        }

        if(S.length() > length + 2 * SpaceNum - 1)
            S[length + 2 * SpaceNum] = '\0';
        
        return S;
    }
};