/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-14 13:44:05
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-14 13:44:37
 * @FilePath: \every-little-progress\day 388\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 189. 设计机械累加器
// https://leetcode.cn/problems/qiu-12n-lcof/description/
// 请设计一个机械累加器，计算从 1、2... 一直累加到目标数值 target 的总和。注意这是一个只能进行加法操作的程序，不具备乘除、if-else、switch-case、for 循环、while 循环，及条件判断语句等高级功能。

 

// 示例 1：

// 输入: target = 5
// 输出: 15
// 示例 2：

// 输入: target = 7
// 输出: 28
 

// 提示：

// 1 <= target <= 10000


class add
{
public:
    add() { sum += num++; }
    static int getsum() { return sum; }
    ~add() 
    { 
        sum = 0;
        num = 1;
    }
private:
    static int num; 
    static int sum; 
};

int add::num = 1; 
int add::sum = 0; 

class Solution {
public:
    int mechanicalAccumulator(int target) {
        add nums[target];
        return add::getsum();
    }
};

