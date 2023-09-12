/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-12 10:57:07
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-12 10:57:39
 * @FilePath: \every-little-progress\day 295\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2119. 反转两次的数字
// https://leetcode.cn/problems/a-number-after-a-double-reversal/
// 反转 一个整数意味着倒置它的所有位。

// 例如，反转 2021 得到 1202 。反转 12300 得到 321 ，不保留前导零 。
// 给你一个整数 num ，反转 num 得到 reversed1 ，接着反转 reversed1 得到 reversed2 。如果 reversed2 等于 num ，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：num = 526
// 输出：true
// 解释：反转 num 得到 625 ，接着反转 625 得到 526 ，等于 num 。
// 示例 2：

// 输入：num = 1800
// 输出：false
// 解释：反转 num 得到 81 ，接着反转 81 得到 18 ，不等于 num 。 
// 示例 3：

// 输入：num = 0
// 输出：true
// 解释：反转 num 得到 0 ，接着反转 0 得到 0 ，等于 num 。
 

// 提示：

// 0 <= num <= 106

class Solution {
public:
    void DelZero(string& num) { while(num.size() > 1 && num.back() == '0') num.pop_back(); }
    
    bool isSameAfterReversals(int num) {
        string n = to_string(num);
        string rn = n;
        DelZero(n);
        reverse(rn.begin(), rn.end());
        reverse(n.begin(), n.end());
        return rn == n;
    }
};