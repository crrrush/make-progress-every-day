/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-12 15:26:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-12 15:27:12
 * @FilePath: \every-little-progress\day 531\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 38. 外观数列
// https://leetcode.cn/problems/count-and-say/description/
// 给定一个正整数 n ，输出外观数列的第 n 项。

// 「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

// 你可以将其视作是由递归公式定义的数字字符串序列：

// countAndSay(1) = "1"
// countAndSay(n) 是对 countAndSay(n-1) 的描述，然后转换成另一个数字字符串。
// 前五项如下：

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 第一项是数字 1 
// 描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
// 描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
// 描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
// 描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
// 要 描述 一个数字字符串，首先要将字符串分割为 最小 数量的组，每个组都由连续的最多 相同字符 组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。

// 例如，数字字符串 "3322251" 的描述如下图：


 

// 示例 1：

// 输入：n = 1
// 输出："1"
// 解释：这是一个基本样例。
// 示例 2：

// 输入：n = 4
// 输出："1211"
// 解释：
// countAndSay(1) = "1"
// countAndSay(2) = 读 "1" = 一 个 1 = "11"
// countAndSay(3) = 读 "11" = 二 个 1 = "21"
// countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
 

// 提示：

// 1 <= n <= 30


class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while(--n)
        {
            string tmp;// 描述s
            int cnt = 1;
            char ch = s[0];
            for(int i = 1;i < s.size();++i)
            {
                if(s[i] == ch) ++cnt; // 计算符号
                else
                {
                    tmp += to_string(cnt);
                    tmp += ch;
                    ch = s[i]; // 更新符号
                    cnt = 1; // 重置计数器
                }
            }
            // 描述最后一串
            tmp += to_string(cnt);
            tmp += ch;

            // cout<<tmp<<endl;

            s = tmp;
        }



        return s;
    }
};
