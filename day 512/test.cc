/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-23 23:06:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-23 23:06:52
 * @FilePath: \every-little-progress\day 512\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 724. 寻找数组的中心下标
// https://leetcode.cn/problems/find-pivot-index/description/
// 给你一个整数数组 nums ，请计算数组的 中心下标 。

// 数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。

// 如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。

// 如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

 

// 示例 1：

// 输入：nums = [1, 7, 3, 6, 5, 6]
// 输出：3
// 解释：
// 中心下标是 3 。
// 左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
// 右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
// 示例 2：

// 输入：nums = [1, 2, 3]
// 输出：-1
// 解释：
// 数组中不存在满足此条件的中心下标。
// 示例 3：

// 输入：nums = [2, 1, -1]
// 输出：0
// 解释：
// 中心下标是 0 。
// 左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
// 右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
 

// 提示：

// 1 <= nums.length <= 104
// -1000 <= nums[i] <= 1000
 

// 注意：本题与主站 1991 题相同：https://leetcode-cn.com/problems/find-the-middle-index-in-array/


class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz = nums.size();
        vector<int> lnums(sz), rnums(sz);
        for(int i = 1;i < sz;++i)
        {
            lnums[i] = nums[i - 1] + lnums[i - 1];
            rnums[sz - i - 1] = rnums[sz - i] + nums[sz - i];
        }
        for(int i = 0;i < sz;++i) if(lnums[i] == rnums[i]) return i;

        return -1;
    }
};


// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         vector<int> lnums(nums), rnums(nums);
//         int lsum = 0, rsum = 0;
//         for(int i = 0;i < nums.size();++i)
//         {
//             lnums[i] += lsum;
//             lsum = lnums[i];

//             rnums[nums.size() - i - 1] += rsum;
//             rsum =  rnums[nums.size() - i - 1];
//         }
//         for(int i = 0;i < nums.size();++i) if(lnums[i] == rnums[i]) return i;

//         return -1;
//     }
// };

// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int sum = accumulate(nums.begin(), nums.end(), 0);
//         int lsum = 0;
//         for(int i = 0;i < nums.size();++i)
//         {
//             if(2 * lsum + nums[i] == sum) return i;
//             lsum += nums[i];
//         }
//         return -1;
//     }
// };