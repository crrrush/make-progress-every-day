/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-19 15:42:32
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-19 15:42:45
 * @FilePath: \every-little-progress\day 422\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2520. 统计能整除数字的位数
// https://leetcode.cn/problems/count-the-digits-that-divide-a-number/description/
// 给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

// 如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。

 

// 示例 1：

// 输入：num = 7
// 输出：1
// 解释：7 被自己整除，因此答案是 1 。
// 示例 2：

// 输入：num = 121
// 输出：2
// 解释：121 可以被 1 整除，但无法被 2 整除。由于 1 出现两次，所以返回 2 。
// 示例 3：

// 输入：num = 1248
// 输出：4
// 解释：1248 可以被它每一位上的数字整除，因此答案是 4 。
 

// 提示：

// 1 <= num <= 109
// num 的数位中不含 0



class Solution {
public:
    int countDigits(int num) {
        int cnt = 0;
        for(int i = num;i >= 1;i /= 10)
        {
            int val = i % 10;
            if(num % val == 0) ++cnt;
        }

        return cnt;
    }
};