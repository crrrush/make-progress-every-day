

// 315. 计算右侧小于当前元素的个数
// https://leetcode.cn/problems/count-of-smaller-numbers-after-self/description/
// 给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

 

// 示例 1：

// 输入：nums = [5,2,6,1]
// 输出：[2,1,1,0] 
// 解释：
// 5 的右侧有 2 个更小的元素 (2 和 1)
// 2 的右侧仅有 1 个更小的元素 (1)
// 6 的右侧有 1 个更小的元素 (1)
// 1 的右侧有 0 个更小的元素
// 示例 2：

// 输入：nums = [-1]
// 输出：[0]
// 示例 3：

// 输入：nums = [-1,-1]
// 输出：[0,0]
 

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// 1. 暴力解法 O(n^2) 简单
// 2. 归并 O(n)

// vector<pair<int, int>> Solution::sv(100005, make_pair(0, 0));

class Solution {
    static int tmp1[100010];
    static int tmp2[100010];
    vector<int> ret;

    void merge(vector<int>& nums, vector<int>& index, int left, int right)// 左闭右闭
    {
        if(left >= right) return;

        int mid = left + (right - left) / 2;
        merge(nums, index, left, mid);
        merge(nums, index, mid + 1, right);

        int l = left, r = mid + 1,i = 0;
        while(l <= mid && r <= right)
        {
            if(nums[l] <= nums[r])
            {
                tmp1[i] = nums[r];
                tmp2[i++] = index[r++];
            }
            else
            {
                ret[index[l]] += (right - r + 1);
                tmp1[i] = nums[l];
                tmp2[i++] = index[l++];
            }
        }
        while(l <= mid)
        {
            tmp1[i] = nums[l];
            tmp2[i++] = index[l++];
        }
        while(r <= right)
        {
            tmp1[i] = nums[r];
            tmp2[i++] = index[r++];
        }
        for(int j = left;j <= right;++j)
        {
            nums[j] = tmp1[j - left];
            index[j] = tmp2[j - left];
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums);
        ret.resize(nums.size());
        for(int i = 0;i < nums.size();++i) index[i] = i;
        merge(nums, index, 0, nums.size() - 1);

        return ret;
    }
};

int Solution::tmp1[100010];
int Solution::tmp2[100010];


// class Solution {
//     static int sv[100010];
//     // vector<int> ret;
//     unordered_map<int, int> hash;

//     void merge(vector<int>& nums, int left, int right)// 左闭右闭
//     {
//         if(left >= right) return;

//         int mid = left + (right - left) / 2;
//         merge(nums, left, mid);
//         merge(nums, mid + 1, right);

//         int l = left, r = mid + 1,i = 0;
//         while(l <= mid && r <= right)
//         {
//             if(nums[l] <= nums[r])
//             {
//                 sv[i++] = nums[r++];
//             }
//             else
//             {
//                 hash[nums[l]] += (right - r + 1);
//                 sv[i++] = nums[l++];
//             }
//         }
//         while(l <= mid) sv[i++] = nums[l++];
//         while(r <= right) sv[i++] = nums[r++];
//         i = 0;
//         for(int j = left;j <= right;++j) nums[j] = sv[i++];
//     }
// public:
//     vector<int> countSmaller(vector<int>& nums) {
//         vector<int> ret(nums);
//         for(const auto& e : nums) hash[e] = 0;
//         merge(ret, 0, ret.size() - 1);

//         for(int i = 0;i < nums.size();++i) ret[i] = hash[nums[i]];
//         return ret;
//     }
// };

// int Solution::sv[100010];


