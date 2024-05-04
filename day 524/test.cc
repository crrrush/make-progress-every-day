/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-05 00:25:59
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-05 00:26:21
 * @FilePath: \every-little-progress\day 524\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 371. 两整数之和
// https://leetcode.cn/problems/sum-of-two-integers/description/
// 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

 

// 示例 1：

// 输入：a = 1, b = 2
// 输出：3
// 示例 2：

// 输入：a = 2, b = 3
// 输出：5
 

// 提示：

// -1000 <= a, b <= 1000


class Solution {
public:
    // 更简洁的写法
    int getSum(int a, int b) {
        while(b != 0)
        {
            int x = a ^ b; // 先算出无进位相加的结果
            unsigned int carry = (unsigned int)((a & b) << 1); // 再算出进位的位置
            a = x;
            b = carry;
        }
        return a;
    }
};


// class Solution {
// public:
//     int getSum(int a, int b) {
//         int sum = 0;
//         bool flag = false; 
//         for(int i = 0;i < 32;++i)
//         {
//             int atmp = a & (1 << i);
//             int btmp = b & (1 << i);

//             sum |= (atmp ^ btmp);
//             // 先结算上一个进位
//             if(flag)
//             {
//                 sum ^= (1 << i);
//                 // 这次计算两个都为0才不进位
//                 if(atmp || btmp) flag = true;
//                 else flag = false;
//             }
//             else
//             {
//                 // 这里再看这次计算是否有进位
//                 if(atmp & btmp) flag = true;
//             }
//         }

//         return sum;
//     }
// };

// class Solution {
// public:
//     int getSum(int a, int b) {
//         return a + b;
//     }
// };

