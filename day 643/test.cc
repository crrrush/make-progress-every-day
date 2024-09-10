/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-10 23:55:13
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-10 23:55:37
 * @FilePath: \every-little-progress\day 643\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 467. 环绕字符串中唯一的子字符串
// https://leetcode.cn/problems/unique-substrings-in-wraparound-string/submissions/563536838/
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串，所以 base 看起来是这样的：

// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现。

 

// 示例 1：

// 输入：s = "a"
// 输出：1
// 解释：字符串 s 的子字符串 "a" 在 base 中出现。
// 示例 2：

// 输入：s = "cac"
// 输出：2
// 解释：字符串 s 有两个子字符串 ("a", "c") 在 base 中出现。
// 示例 3：

// 输入：s = "zab"
// 输出：6
// 解释：字符串 s 有六个子字符串 ("z", "a", "b", "za", "ab", and "zab") 在 base 中出现。
 

// 提示：

// 1 <= s.length <= 105
// s 由小写英文字母组成
