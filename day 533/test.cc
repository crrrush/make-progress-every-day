


// 75. 颜色分类
// https://leetcode.cn/problems/sort-colors/description/
// 给定一个包含红色、白色和蓝色、共 n 个元素的数组 nums ，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

// 我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

// 必须在不使用库内置的 sort 函数的情况下解决这个问题。

 

// 示例 1：

// 输入：nums = [2,0,2,1,1,0]
// 输出：[0,0,1,1,2,2]
// 示例 2：

// 输入：nums = [2,0,1]
// 输出：[0,1,2]
 

// 提示：

// n == nums.length
// 1 <= n <= 300
// nums[i] 为 0、1 或 2
 

// 进阶：

// 你能想出一个仅使用常数空间的一趟扫描算法吗？


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        // 模板版
        // 分三块 以1为基准元素，0放左侧，2放右侧
        int left = -1, right = n;

        int mid = left + 1;
        while(mid < right)
        {
            if(0 == nums[mid])
                swap(nums[++left], nums[mid++]);
            else if(2 == nums[mid])
                swap(nums[--right], nums[mid]);
            else
                ++mid;
        }
    }
};

// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();

//         // 分三块 以1为基准元素，0放左侧，2放右侧
//         int left = 0, right = n - 1;
//         // while(left < right && nums[left] == 0) ++left;
//         // while(left < right && nums[right] == 2) --right;

//         int mid = left;
//         while(mid <= right)
//         {
//             if(0 == nums[mid])
//                 swap(nums[left++], nums[mid++]);
//             else if(2 == nums[mid])
//                 swap(nums[right--], nums[mid]);
//             else
//                 ++mid;
//         }
//     }
// };


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int n = nums.size();

//         // 分三块 以1为基准元素，0放左侧，2放右侧
//         int left = -1, right = n;
//         while(left + 1 < right && nums[left + 1] == 0) ++left;
//         while(left < right - 1 && nums[right - 1] == 2) --right;

//         int mid = left + 1;
//         while(mid < right)
//         {
//             if(0 == nums[mid])
//             {
//                 swap(nums[left + 1], nums[mid]);
//                 while(left < mid && 0 == nums[left + 1]) ++left;
//                 if(mid == left) ++mid;
//             }
//             else if(2 == nums[mid])
//             {
//                 swap(nums[right - 1], nums[mid]);
//                 while(mid < right && 2 == nums[right - 1]) --right;
//             }
//             else
//             {
//                 ++mid;
//             }
            
//             // cout<<left<<"-"<<mid<<"-"<<right<<endl;
//         }
//     }
// };


// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int left = 0;
//         int n = nums.size();

//         // 先将0移动至前面
//         while(left < n && 0 == nums[left]) ++left;
//         int right = left + 1;
//         while(left < n && right < n)
//         {
//             if(nums[right] == 0) swap(nums[left++], nums[right]);
//             ++right;
//         }

//         // 将1移动至中间区域
//         while(left < n && 1 == nums[left]) ++left;
//         right = left + 1;
//         while(right < n)
//         {
//             if(nums[right] == 1) swap(nums[left++], nums[right]);
//             ++right;
//         }
//     }
// };
