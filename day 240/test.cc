

// 504. 七进制数
// https://leetcode.cn/problems/base-7/
// 给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

 

// 示例 1:

// 输入: num = 100
// 输出: "202"

// 示例 2:

// 输入: num = -7
// 输出: "-10"

 

// 提示：

//     -107 <= num <= 107



class Solution {
public:
    string convertToBase7(int num) {
        string N;
        char symbol = 0;
        if(num < 0)
        {
            symbol = '-';
            num = -num;
        }
        else if(num == 0) return string("0");

        while(num)
        {
            N += ('0' + num % 7);
            num /= 7;
        }

        if(symbol == '-') N += symbol;

        reverse(N.begin(), N.end());

        return N;
    }
};