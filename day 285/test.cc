/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-01 20:36:12
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-01 20:37:01
 * @FilePath: \every-little-progress\day 285\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2000. 反转单词前缀
// https://leetcode.cn/problems/reverse-prefix-of-word/
// 给你一个下标从 0 开始的字符串 word 和一个字符 ch 。找出 ch 第一次出现的下标 i ，反转 word 中从下标 0 开始、直到下标 i 结束（含下标 i ）的那段字符。如果 word 中不存在字符 ch ，则无需进行任何操作。

// 例如，如果 word = "abcdefd" 且 ch = "d" ，那么你应该 反转 从下标 0 开始、直到下标 3 结束（含下标 3 ）。结果字符串将会是 "dcbaefd" 。
// 返回 结果字符串 。

 

// 示例 1：

// 输入：word = "abcdefd", ch = "d"
// 输出："dcbaefd"
// 解释："d" 第一次出现在下标 3 。 
// 反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "dcbaefd" 。
// 示例 2：

// 输入：word = "xyxzxe", ch = "z"
// 输出："zxyxxe"
// 解释："z" 第一次也是唯一一次出现是在下标 3 。
// 反转从下标 0 到下标 3（含下标 3）的这段字符，结果字符串是 "zxyxxe" 。
// 示例 3：

// 输入：word = "abcd", ch = "z"
// 输出："abcd"
// 解释："z" 不存在于 word 中。
// 无需执行反转操作，结果字符串是 "abcd" 。
 

// 提示：

// 1 <= word.length <= 250
// word 由小写英文字母组成
// ch 是一个小写英文字母

class Solution {
public:
    string reversePrefix(string word, char ch) {
        size_t pos = word.find(ch);
        reverse(word.begin(), word.begin() + pos + 1);
        return word;
    }
};