/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-07 14:06:17
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-07 14:07:06
 * @FilePath: \every-little-progress\day 469\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 925. 长按键入
// https://leetcode.cn/problems/long-pressed-name/description/
// 你的朋友正在使用键盘输入他的名字 name。偶尔，在键入字符 c 时，按键可能会被长按，而字符可能被输入 1 次或多次。

// 你将会检查键盘输入的字符 typed。如果它对应的可能是你的朋友的名字（其中一些字符可能被长按），那么就返回 True。

 

// 示例 1：

// 输入：name = "alex", typed = "aaleex"
// 输出：true
// 解释：'alex' 中的 'a' 和 'e' 被长按。
// 示例 2：

// 输入：name = "saeed", typed = "ssaaedd"
// 输出：false
// 解释：'e' 一定需要被键入两次，但在 typed 的输出中不是这样。
 

// 提示：

// 1 <= name.length, typed.length <= 1000
// name 和 typed 的字符都是小写字母


class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length() > typed.length() 
        || name.front() != typed.front())
            return false;

        size_t p1 = 0,p2 = 0;
        // while(p1 < name.length() && p2 < typed.length())
        while(p1 < name.length())
        {
            if(name[p1] == typed[p2])
            {
                ++p1;
                ++p2;
            }
            else
            {
                if(name[p1 - 1] == typed[p2])
                    ++p2;
                else
                    return false;
            }
        }
        while(p2 < typed.length()) if(typed[p2++] != name.back()) return false;

        return true;
    }
};