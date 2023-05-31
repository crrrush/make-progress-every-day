
// 215. 数组中的第K个最大元素
// https://leetcode.cn/problems/kth-largest-element-in-an-array/
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

//     1 <= k <= nums.length <= 105
//     -104 <= nums[i] <= 104


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > heap(nums.begin(), nums.begin() + k);
        for(int i = k;i < nums.size();++i)
        {
            if(nums[i] > heap.top())
            {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};

// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         priority_queue<int> heap(nums.begin(), nums.end());

//         while(--k)
//         {
//             heap.pop();
//         }

//         return heap.top();
//     }
// };