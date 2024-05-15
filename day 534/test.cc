/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-15 21:01:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-15 21:01:57
 * @FilePath: \every-little-progress\day 534\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 215. 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
// 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

// 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

// 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

// 示例 1:

// 输入: [3,2,1,5,6,4], k = 2
// 输出: 5
// 示例 2:

// 输入: [3,2,3,1,2,4,5,5,6], k = 4
// 输出: 4
 

// 提示：

// 1 <= k <= nums.length <= 105
// -104 <= nums[i] <= 104


class Solution {
    size_t get_key(int l, int r) { return (rand() % (r - l + 1)) + l; }

    int findKth(vector<int>& nums, const int l, const int r,int k) // 左闭右闭 第k大
    {
        if(l == r) return nums[l];

        int key = nums[get_key(l, r)];
        int i = l, left = l - 1, right = r + 1;

        while(i < right)
        {
            if(nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if(nums[i] > key)
                swap(nums[--right], nums[i]);
            else
                ++i;
        }
        
        // cout<<key<<"-";for(const auto& e : nums) cout<<e <<" ";cout<<endl;

        int a = left - l + 1;
        int b = right - left - 1;
        int c = r - right + 1;
        
        if(c >= k)
            return findKth(nums, right, r, k);
        else if(b + c < k)
            return findKth(nums, l, left, k - b - c);
        else
            return key;
    }
public:
    // 快速选择排序
    int findKthLargest(vector<int>& nums, int k) {
        srand((size_t)time(nullptr) ^ nums.size());
        return findKth(nums, 0, nums.size() - 1, k);
    }
};
