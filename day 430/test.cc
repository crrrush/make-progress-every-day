/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-27 15:47:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-27 15:47:48
 * @FilePath: \every-little-progress\day 430\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2610. 转换二维数组
// https://leetcode.cn/problems/convert-an-array-into-a-2d-array-with-conditions/description/
// 给你一个整数数组 nums 。请你创建一个满足以下条件的二维数组：

// 二维数组应该 只 包含数组 nums 中的元素。
// 二维数组中的每一行都包含 不同 的整数。
// 二维数组的行数应尽可能 少 。
// 返回结果数组。如果存在多种答案，则返回其中任何一种。

// 请注意，二维数组的每一行上可以存在不同数量的元素。

 

// 示例 1：

// 输入：nums = [1,3,4,1,2,3,1]
// 输出：[[1,3,4,2],[1,3],[1]]
// 解释：根据题目要求可以创建包含以下几行元素的二维数组：
// - 1,3,4,2
// - 1,3
// - 1
// nums 中的所有元素都有用到，并且每一行都由不同的整数组成，所以这是一个符合题目要求的答案。
// 可以证明无法创建少于三行且符合题目要求的二维数组。
// 示例 2：

// 输入：nums = [1,2,3,4]
// 输出：[[4,3,2,1]]
// 解释：nums 中的所有元素都不同，所以我们可以将其全部保存在二维数组中的第一行。
 

// 提示：

// 1 <= nums.length <= 200
// 1 <= nums[i] <= nums.length

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(const auto& e : nums) ++hash[e];
        list<pair<int, int>> lp;
        for(const auto& [x, y] : hash) lp.push_front(make_pair(x, y));

        vector<vector<int>> vv;
        while(!lp.empty())
        {
            vector<int> tmp;
            tmp.reserve(lp.size());
            auto it = lp.begin();
            while(it != lp.end())
            {
                tmp.push_back(it->first);
                if(--(it->second) == 0) it = lp.erase(it);
                else ++it;
            }

            vv.push_back(tmp);
        }

        return vv;
    }
};