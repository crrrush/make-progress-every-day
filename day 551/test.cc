/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-02 11:42:02
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-02 11:42:31
 * @FilePath: \every-little-progress\day 551\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 67. 二进制求和
// https://leetcode.cn/problems/add-binary/description/
// 给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和。

 

// 示例 1：

// 输入:a = "11", b = "1"
// 输出："100"
// 示例 2：

// 输入：a = "1010", b = "1011"
// 输出："10101"
 

// 提示：

// 1 <= a.length, b.length <= 104
// a 和 b 仅由字符 '0' 或 '1' 组成
// 字符串如果不是 "0" ，就不含前导零

class Solution {
public:
    // 写法更新
    string addBinary(string a, string b) {
        int pa = a.size() - 1, pb = b.size() - 1;
        // int pa = alen - 1, pb = blen - 1;
        string ans;
        int sum = 0;
        while(pa >= 0 && pb >= 0)
        {
            sum += a[pa--] - '0' + b[pb--] - '0';
            ans += to_string(sum % 2);
            sum /= 2;
        }
        while(pa >= 0)
        {
            sum += a[pa--] - '0';
            ans += to_string(sum % 2);
            sum /= 2;
        }
        while(pb >= 0)
        {
            sum += b[pb--] - '0';
            ans += to_string(sum % 2);
            sum /= 2;
        }
        if(sum > 0) ans += to_string(sum % 2);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

