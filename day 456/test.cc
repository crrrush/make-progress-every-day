/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-22 15:50:38
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-22 15:51:04
 * @FilePath: \every-little-progress\day 456\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2810. 故障键盘
// https://leetcode.cn/problems/faulty-keyboard/description/
// 你的笔记本键盘存在故障，每当你在上面输入字符 'i' 时，它会反转你所写的字符串。而输入其他字符则可以正常工作。

// 给你一个下标从 0 开始的字符串 s ，请你用故障键盘依次输入每个字符。

// 返回最终笔记本屏幕上输出的字符串。

 

// 示例 1：

// 输入：s = "string"
// 输出："rtsng"
// 解释：
// 输入第 1 个字符后，屏幕上的文本是："s" 。
// 输入第 2 个字符后，屏幕上的文本是："st" 。
// 输入第 3 个字符后，屏幕上的文本是："str" 。
// 因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "rts" 。
// 输入第 5 个字符后，屏幕上的文本是："rtsn" 。
// 输入第 6 个字符后，屏幕上的文本是： "rtsng" 。
// 因此，返回 "rtsng" 。
// 示例 2：

// 输入：s = "poiinter"
// 输出："ponter"
// 解释：
// 输入第 1 个字符后，屏幕上的文本是："p" 。
// 输入第 2 个字符后，屏幕上的文本是："po" 。
// 因为第 3 个字符是 'i' ，屏幕上的文本被反转，变成 "op" 。
// 因为第 4 个字符是 'i' ，屏幕上的文本被反转，变成 "po" 。
// 输入第 5 个字符后，屏幕上的文本是："pon" 。
// 输入第 6 个字符后，屏幕上的文本是："pont" 。
// 输入第 7 个字符后，屏幕上的文本是："ponte" 。
// 输入第 8 个字符后，屏幕上的文本是："ponter" 。
// 因此，返回 "ponter" 。
 

// 提示：

// 1 <= s.length <= 100
// s 由小写英文字母组成
// s[0] != 'i'


class Solution {
public:
    string finalString(string s) {
        list<char> lt;
        for(const auto& e : s)
        {
            if(e == 'i') lt.reverse();
            else lt.push_back(e);
        }

        return string(lt.begin(), lt.end());
    }
};

// class Solution {
// public:
//     string finalString(string s) {
//         auto it = s.begin();
//         while(it != s.end())
//         {
//             if(*it == 'i') reverse(s.begin(), it);

//             ++it;
//         }

//         string res;
//         for(const auto& e : s) if(e != 'i') res += e;

//         return res;
//     }
// };