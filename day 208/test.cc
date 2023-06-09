

// 34. 在排序数组中查找元素的第一个和最后一个位置
// https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

 

// 示例 1：

// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

// 示例 2：

// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]

// 示例 3：

// 输入：nums = [], target = 0
// 输出：[-1,-1]

 

// 提示：

//     0 <= nums.length <= 105
//     -109 <= nums[i] <= 109
//     nums 是一个非递减数组
//     -109 <= target <= 109


class Solution {
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = (right - left) / 2 + left;

            if(nums[mid] < target)       left = mid + 1;
            else if(nums[mid] > target)  right = mid - 1;
            else                         return mid;


        }

        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = search(nums, target);
        vector<int> range;
        if(pos == -1)
        {
            range.push_back(-1);
            range.push_back(-1);
            return range;
        }

        int start = pos, end = pos;
        while(start >= 1 && nums[start - 1] == target) --start;
        while(end < nums.size() - 1 && nums[end + 1] == target) ++end;

        range.push_back(start);
        range.push_back(end);
        return range;
    }
};
