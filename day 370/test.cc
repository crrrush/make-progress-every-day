/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-26 15:27:11
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-26 15:27:40
 * @FilePath: \every-little-progress\day 370\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2710. 移除字符串中的尾随零
// https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/description/
// 给你一个用字符串表示的正整数 num ，请你以字符串形式返回不含尾随零的整数 num 。

 

// 示例 1：

// 输入：num = "51230100"
// 输出："512301"
// 解释：整数 "51230100" 有 2 个尾随零，移除并返回整数 "512301" 。
// 示例 2：

// 输入：num = "123"
// 输出："123"
// 解释：整数 "123" 不含尾随零，返回整数 "123" 。
 

// 提示：

// 1 <= num.length <= 1000
// num 仅由数字 0 到 9 组成
// num 不含前导零

class Solution {
public:
    string removeTrailingZeros(string num) {
        while(num.back() == '0') num.pop_back();
        return num;
    }
};