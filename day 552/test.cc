

// 43. 字符串相乘
// https://leetcode.cn/problems/multiply-strings/description/
// 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

// 注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。

 

// 示例 1:

// 输入: num1 = "2", num2 = "3"
// 输出: "6"
// 示例 2:

// 输入: num1 = "123", num2 = "456"
// 输出: "56088"
 

// 提示：

// 1 <= num1.length, num2.length <= 200
// num1 和 num2 只能由数字组成。
// num1 和 num2 都不包含任何前导零，除了数字0本身。


class Solution {
    // 优化 无进位相加
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int sz1 = num1.size(), sz2 = num2.size();
        vector<int> vnum(sz1 + sz2 - 1, 0);
        for(int i = 0;i < sz1;++i)
        {
            for(int j = 0;j < sz2;++j)
            {
                vnum[i + j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int sum = 0;
        string ans;
        for(const auto& e : vnum)
        {
            sum += e;
            ans += (sum % 10 + '0');
            sum /= 10;
        }
        if(sum) ans += (sum % 10 + '0');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};


// class Solution {
//     string add(const string& n1, const string& n2)
//     {
//         if(n1.empty()) return n2;
//         else if(n2.empty()) return n1;

//         string ans;
//         int sum = 0, p1 = n1.size() - 1, p2 = n2.size() - 1;
//         while(p1 >= 0 && p2 >= 0)
//         {
//             sum += (n1[p1--] - '0') + (n2[p2--] - '0');
//             ans += (char)('0' + sum % 10);
//             sum /= 10;
//         }
//         while(p1 >= 0)
//         {
//             sum += n1[p1--] - '0';
//             ans += (char)('0' + sum % 10);
//             sum /= 10;
//         }
//         while(p2 >= 0)
//         {
//             sum += n2[p2--] - '0';
//             ans += (char)('0' + sum % 10);
//             sum /= 10;
//         }
//         if(sum > 0) ans += (char)('0' + sum % 10);
//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// public:
//     string multiply(string num1, string num2) {
//         if(num1 == "0" || num2 == "0") return "0";
//         int len1 = num1.size() - 1, len2 = num2.size() - 1;
//         int p2 = len2;
//         string ans;
//         int res = 0;
//         while(p2 >= 0)
//         {
//             res = 0;
//             int p1 = len1;
//             string tmp;
//             while(p1 >= 0)
//             {
//                 res += (num1[p1--] - '0') * (num2[p2] - '0');
//                 tmp += (char)('0' + res % 10);
//                 res /= 10;
//             }
//             if(res > 0) tmp += (char)('0' + res % 10);
//             reverse(tmp.begin(), tmp.end());

//             for(int i = len2;i > p2;--i) tmp += '0';
//             ans = add(ans, tmp);

//             --p2;
//         }
//         // if(res > 0) return to_string(res) + ans;

//         return ans;
//     }
// };


