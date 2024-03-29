/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-08 21:22:33
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-08 21:23:00
 * @FilePath: \every-little-progress\day 321\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1720. 解码异或后的数组
// https://leetcode.cn/problems/decode-xored-array/description/
// 未知 整数数组 arr 由 n 个非负整数组成。

// 经编码后变为长度为 n - 1 的另一个整数数组 encoded ，其中 encoded[i] = arr[i] XOR arr[i + 1] 。例如，arr = [1,0,2,1] 经编码后得到 encoded = [1,2,3] 。

// 给你编码后的数组 encoded 和原数组 arr 的第一个元素 first（arr[0]）。

// 请解码返回原数组 arr 。可以证明答案存在并且是唯一的。

 

// 示例 1：

// 输入：encoded = [1,2,3], first = 1
// 输出：[1,0,2,1]
// 解释：若 arr = [1,0,2,1] ，那么 first = 1 且 encoded = [1 XOR 0, 0 XOR 2, 2 XOR 1] = [1,2,3]
// 示例 2：

// 输入：encoded = [6,2,7,3], first = 4
// 输出：[4,2,0,7,4]
 

// 提示：

// 2 <= n <= 104
// encoded.length == n - 1
// 0 <= encoded[i] <= 105
// 0 <= first <= 105

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> org;
        org.push_back(first);
        int pos = 0;
        for(const auto& e : encoded) org.push_back(e ^ org[pos++]);

        return org;
    }
};