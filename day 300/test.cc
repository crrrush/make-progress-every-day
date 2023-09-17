/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-17 13:54:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-17 13:56:07
 * @FilePath: \every-little-progress\day 300\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1512. 好数对的数目
// https://leetcode.cn/problems/number-of-good-pairs/description/
// 给你一个整数数组 nums 。

// 如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

// 返回好数对的数目。

 

// 示例 1：

// 输入：nums = [1,2,3,1,1,3]
// 输出：4
// 解释：有 4 组好数对，分别是 (0,3), (0,4), (3,4), (2,5) ，下标从 0 开始
// 示例 2：

// 输入：nums = [1,1,1,1]
// 输出：6
// 解释：数组中的每组数字都是好数对
// 示例 3：

// 输入：nums = [1,2,3]
// 输出：0
 

// 提示：

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0;i < nums.size();++i) for(int j = i + 1;j < nums.size();++j) if(nums[i] == nums[j] && i < j) ++cnt;

        return cnt;
    }
};