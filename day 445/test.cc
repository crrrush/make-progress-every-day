/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-11 11:15:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-11 11:17:03
 * @FilePath: \every-little-progress\day 445\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 697. 数组的度
// https://leetcode.cn/problems/degree-of-an-array/description/
// 给定一个非空且只包含非负数的整数数组 nums，数组的 度 的定义是指数组里任一元素出现频数的最大值。

// 你的任务是在 nums 中找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。

 

// 示例 1：

// 输入：nums = [1,2,2,3,1]
// 输出：2
// 解释：
// 输入数组的度是 2 ，因为元素 1 和 2 的出现频数最大，均为 2 。
// 连续子数组里面拥有相同度的有如下所示：
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// 最短连续子数组 [2, 2] 的长度为 2 ，所以返回 2 。
// 示例 2：

// 输入：nums = [1,2,2,3,1,4,2]
// 输出：6
// 解释：
// 数组的度是 3 ，因为元素 2 重复出现 3 次。
// 所以 [2,2,3,1,4,2] 是最短子数组，因此返回 6 。
 

// 提示：

// nums.length 在 1 到 50,000 范围内。
// nums[i] 是一个在 0 到 49,999 范围内的整数。


class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int ,int> hash;
        unordered_map<int ,pair<int, int>> lens;
        for(int i = 0;i < nums.size();++i)
        {
            ++hash[nums[i]];
            if(lens.find(nums[i]) == lens.end())
                lens.insert(make_pair(nums[i], make_pair(i, i)));
            else
                lens[nums[i]].second = i;
        }

        int max = -1;
        size_t min_len = -1;
        vector<int> mlens;
        for(const auto& [x, y] : hash)
        {
            if(y > max)
            {
                max = y;
                mlens.clear();
                mlens.push_back(x);
            }
            else if(y == max)
                mlens.push_back(x);
        }

        for(const auto& e : mlens) if(lens[e].second - lens[e].first < min_len) min_len = lens[e].second - lens[e].first;

        return min_len + 1;
    }
};