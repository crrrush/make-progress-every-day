/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-13 13:44:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-13 13:46:39
 * @FilePath: \every-little-progress\day 273\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1678. 设计 Goal 解析器
// https://leetcode.cn/problems/goal-parser-interpretation/
// 请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。

// 给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。

 

// 示例 1：

// 输入：command = "G()(al)"
// 输出："Goal"
// 解释：Goal 解析器解释命令的步骤如下所示：
// G -> G
// () -> o
// (al) -> al
// 最后连接得到的结果是 "Goal"
// 示例 2：

// 输入：command = "G()()()()(al)"
// 输出："Gooooal"
// 示例 3：

// 输入：command = "(al)G(al)()()G"
// 输出："alGalooG"
 

// 提示：

// 1 <= command.length <= 100
// command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成


class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i = 0;i < command.length();++i)
        {
            if(command[i] == 'G')
                res += "G";
            else
            {
                if(command[i + 1] == ')')
                {
                    res += "o";
                    i += 1;
                }
                else
                {
                    res += "al";
                    i += 3;
                }
            }
        }

        return res;
    }
};