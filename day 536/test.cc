

// 912. 排序数组
// https://leetcode.cn/problems/sort-an-array/description/
// 给你一个整数数组 nums，请你将该数组升序排列。

 

// 示例 1：

// 输入：nums = [5,2,3,1]
// 输出：[1,2,3,5]
// 示例 2：

// 输入：nums = [5,1,1,2,0,0]
// 输出：[0,0,1,1,2,5]
 

// 提示：

// 1 <= nums.length <= 5 * 104
// -5 * 104 <= nums[i] <= 5 * 104


// 归并排序
class Solution {
    vector<int> tmp;

    void merge(vector<int>& nums, int left, int right) // 左闭右闭
    {
        if(left >= right) return;

        int mid = left + (right - left) / 2;
        merge(nums, left, mid);
        merge(nums, mid + 1, right);

        int pl = left, pr = mid + 1, i = 0;
        while(pl <= mid && pr <= right)
        {
            if(nums[pl] < nums[pr])
                tmp[i++] = nums[pl++];
            else
                tmp[i++] = nums[pr++];
        }
        while(pl <= mid) tmp[i++] = nums[pl++];
        while(pr <= right) tmp[i++] = nums[pr++];
        // for(const auto& e : tmp) cout<<e<<" ";cout<<endl;
        i = 0;
        for(int j = left;j <= right;++j) nums[j] = tmp[i++];
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        merge(nums, 0, nums.size() - 1);
        return nums;
    }
};

// // 归并排序
// class Solution {
//     void merge(vector<int>& nums, int left, int right) // 左闭右闭
//     {
//         if(left >= right) return;

//         int mid = left + (right - left) / 2;
//         merge(nums, left, mid);
//         merge(nums, mid + 1, right);

//         vector<int> tmp(right - left + 1);
//         int pl = left, pr = mid + 1, i = 0;
//        //while(pl <= mid && pr <= right && i < tmp.size())
//         while(pl <= mid && pr <= right)
//         {
//             if(nums[pl] < nums[pr])
//                 tmp[i++] = nums[pl++];
//             else
//                 tmp[i++] = nums[pr++];
//         }
//         while(pl <= mid) tmp[i++] = nums[pl++];
//         while(pr <= right) tmp[i++] = nums[pr++];
//         // for(const auto& e : tmp) cout<<e<<" ";cout<<endl;
//         i = 0;
//         for(int j = left;j <= right;++j) nums[j] = tmp[i++];
//     }

// public:
//     vector<int> sortArray(vector<int>& nums) {
//         merge(nums, 0, nums.size() - 1);
//         return nums;
//     }
// };



//// 快速选择排序
// class Solution {
//     void sortArray(vector<int>& nums, int left, int right)// 左闭右开
//     {
//         if(left + 1 >= right) return;

//         // 数组分三块
//         int key = nums[rand() % (right - left) + left]; // 随机取一个当基准值
//         int l = left - 1, r = right; // 左边界左边，右边界右边
//         // cout<<left<<"-"<<right<<"-"<<key<<"->";

//         int i = left; 
//         while(i < r)
//         {
//             if(nums[i] < key)
//                 swap(nums[++l], nums[i++]);
//             else if(nums[i] > key)
//                 swap(nums[--r], nums[i]);
//             else
//                 ++i;
//         }
//         // for(const auto& e : nums) cout<<e<<" ";
//         // cout<<endl;

//         // 注意这里需要传的是一个左闭右开的区间
//         sortArray(nums, left, l + 1);
//         sortArray(nums, r, right);
//     }
// public:
//     vector<int> sortArray(vector<int>& nums) {
//         srand((size_t)time(nullptr) ^ nums.size());
//         sortArray(nums, 0, nums.size());
//         return nums;
//     }
// };

