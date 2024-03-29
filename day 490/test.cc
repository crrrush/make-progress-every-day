/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-29 12:51:28
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-29 12:51:54
 * @FilePath: \every-little-progress\day 490\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 202. 快乐数
// https://leetcode.cn/problems/happy-number/description/
// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

 

// 示例 1：

// 输入：n = 19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// 示例 2：

// 输入：n = 2
// 输出：false
 

// 提示：

// 1 <= n <= 231 - 1


class Solution {
    int cal(int n)
    {
        int res = 0;
        while(n)
        {
            res += ((n % 10) * (n % 10));

            n /= 10;
        }
        return res;
    }

public:
    bool isHappy(int n) {
        int slow = n,fast = n;

        // 快慢指针解法
        // 计算到随后会陷入一个环
        // 可能环中全是1，即是快乐数
        // 可能环中没有1（有1就不会循环了），即不是快乐数
        do
        {
            slow = cal(slow);
            fast = cal(cal(fast));
        }while(slow != fast);

        return slow == 1;
    }
};