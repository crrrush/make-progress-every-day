/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-24 19:14:36
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-24 19:15:06
 * @FilePath: \every-little-progress\day 337\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1331. 数组序号转换
// https://leetcode.cn/problems/rank-transform-of-an-array/
// 给你一个整数数组 arr ，请你将数组中的每个元素替换为它们排序后的序号。

// 序号代表了一个元素有多大。序号编号的规则如下：

// 序号从 1 开始编号。
// 一个元素越大，那么序号越大。如果两个元素相等，那么它们的序号相同。
// 每个数字的序号都应该尽可能地小。
 

// 示例 1：

// 输入：arr = [40,10,20,30]
// 输出：[4,1,2,3]
// 解释：40 是最大的元素。 10 是最小的元素。 20 是第二小的数字。 30 是第三小的数字。
// 示例 2：

// 输入：arr = [100,100,100]
// 输出：[1,1,1]
// 解释：所有元素有相同的序号。
// 示例 3：

// 输入：arr = [37,12,28,9,100,56,80,5,12]
// 输出：[5,3,4,2,8,6,7,1,3]
 

// 提示：

// 0 <= arr.length <= 105
// -109 <= arr[i] <= 109

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> res;
        res.reserve(arr.size());

        unordered_map<int, int> hash;
        vector<int> sa(arr);
        sort(sa.begin(), sa.end());

        int num = 1;
        for(const auto& e : sa) if(hash.find(e) == hash.end()) hash[e] = num++;

        for(const auto& e : arr) res.push_back(hash[e]);


        return res;
    }
};