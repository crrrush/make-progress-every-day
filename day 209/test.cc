

// 977. 有序数组的平方
// https://leetcode.cn/problems/squares-of-a-sorted-array/

// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

 

// 示例 1：

// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]
// 排序后，数组变为 [0,1,9,16,100]

// 示例 2：

// 输入：nums = [-7,-3,2,3,11]
// 输出：[4,9,9,49,121]

 

// 提示：

//     1 <= nums.length <= 104
//     -104 <= nums[i] <= 104
//     nums 已按 非递减顺序 排序

 

// 进阶：

//     请你设计时间复杂度为 O(n) 的算法解决本问题




class Solution {
    int findmid(vector<int> nums)
    {
        int pos = 0;
        while(pos != nums.size() && nums[pos] < 0) ++pos;

        return pos;
    }

    int pow(int& n) {return n*n;}

public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid = findmid(nums);
        int left = mid - 1, right = mid;
        vector<int> res;
        while(left >= 0 && right < nums.size())
        {
            if(pow(nums[left]) <= pow(nums[right])) 
                res.push_back(pow(nums[left--]));
            else                                    
                res.push_back(pow(nums[right++]));
        }
        while(left >= 0) res.push_back(pow(nums[left--]));
        while(right < nums.size()) res.push_back(pow(nums[right++]));

        return res;
    }
};
