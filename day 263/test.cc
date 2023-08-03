/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-03 11:46:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-03 11:47:05
 * @FilePath: \every-little-progress\day 263\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1108. IP 地址无效化
// https://leetcode.cn/problems/defanging-an-ip-address/
// 给你一个有效的 IPv4 地址 address，返回这个 IP 地址的无效化版本。

// 所谓无效化 IP 地址，其实就是用 "[.]" 代替了每个 "."。

 

// 示例 1：

// 输入：address = "1.1.1.1"
// 输出："1[.]1[.]1[.]1"
// 示例 2：

// 输入：address = "255.100.50.0"
// 输出："255[.]100[.]50[.]0"
 

// 提示：

// 给出的 address 是一个有效的 IPv4 地址

class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        for(const auto& e : address)
        {
            if(e == '.') res += "[.]";
            else         res += e;
        }

        return res;
    }
};