

// 493. 翻转对
// https://leetcode.cn/problems/reverse-pairs/description/
// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。

// 你需要返回给定数组中的重要翻转对的数量。

// 示例 1:

// 输入: [1,3,2,3,1]
// 输出: 2
// 示例 2:

// 输入: [2,4,3,5,1]
// 输出: 3
// 注意:

// 给定数组的长度不会超过50000。
// 输入数组中的所有数字都在32位整数的表示范围内。


class Solution {
    static int tmp[50001];
    // 利用单调性，使用同向双指针

    int merge(vector<int>& nums, int left, int right) // 左闭右闭
    {
        if(left >= right) return 0;

        // int mid = (left + right) >> 1;
        int mid = left + (right - left) / 2;
        int cnt = merge(nums, left, mid);
        cnt += merge(nums, mid + 1, right);

        // 升序
        int cur1 = left, cur2 = mid + 1, i = 0;
        while(cur1 <= mid && cur2 <= right)
        {
            if(nums[cur1] / 2.0 <= nums[cur2])
                ++cur1;
            else
            {
                cnt += mid - cur1 + 1;
                ++cur2;
            }
        }

        cur1 = left, cur2 = mid + 1;
        while(cur1 <= mid && cur2 <= right)
        {
            if(nums[cur1] <= nums[cur2])
                tmp[i++] = nums[cur1++];
            else
                tmp[i++] = nums[cur2++];
        }
        while(cur1 <= mid) tmp[i++] = nums[cur1++];
        while(cur2 <= right) tmp[i++] = nums[cur2++];
        for(int j = left;j <= right;++j) nums[j] = tmp[j - left];

        return cnt;
    }
public:
    int reversePairs(vector<int>& nums) {
        int cnt = merge(nums, 0, nums.size() - 1);
        // for(auto& e : nums) cout<<e<<" ";
        return cnt;
        // return merge(nums, 0, nums.size() - 1);
    }
};

int Solution::tmp[50001] = { 0 };

// class Solution {
//     static int tmp[50001];
//     // 利用单调性，使用同向双指针

//     int merge(vector<int>& nums, int left, int right) // 左闭右闭
//     {
//         if(left >= right) return 0;

//         // int mid = (left + right) >> 1;
//         int mid = left + (right - left) / 2;
//         int cnt = merge(nums, left, mid);
//         cnt += merge(nums, mid + 1, right);

//         // 降序
//         int cur1 = left, cur2 = mid + 1, i = 0;
//         while(cur1 <= mid && cur2 <= right)
//         {
//             long long pro = (long long)2 * nums[cur2];
//             if(nums[cur1] <= pro)
//                 ++cur2;
//             else
//             {
//                 cnt += right - cur2 + 1;
//                 ++cur1;
//             }
//         }

//         cur1 = left, cur2 = mid + 1;
//         while(cur1 <= mid && cur2 <= right)
//         {
//             if(nums[cur1] <= nums[cur2])
//                 tmp[i++] = nums[cur2++];
//             else
//                 tmp[i++] = nums[cur1++];
//         }
//         while(cur1 <= mid) tmp[i++] = nums[cur1++];
//         while(cur2 <= right) tmp[i++] = nums[cur2++];
//         for(int j = left;j <= right;++j) nums[j] = tmp[j - left];

//         return cnt;
//     }
// public:
//     int reversePairs(vector<int>& nums) {
//         int cnt = merge(nums, 0, nums.size() - 1);
//         // for(auto& e : nums) cout<<e<<" ";
//         return cnt;
//         // return merge(nums, 0, nums.size() - 1);
//     }
// };

// int Solution::tmp[50001] = { 0 };
