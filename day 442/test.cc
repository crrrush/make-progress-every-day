

// 1752. 检查数组是否经排序和轮转得到
// https://leetcode.cn/problems/check-if-array-is-sorted-and-rotated/description/
// 给你一个数组 nums 。nums 的源数组中，所有元素与 nums 相同，但按非递减顺序排列。

// 如果 nums 能够由源数组轮转若干位置（包括 0 个位置）得到，则返回 true ；否则，返回 false 。

// 源数组中可能存在 重复项 。

// 注意：我们称数组 A 在轮转 x 个位置后得到长度相同的数组 B ，当它们满足 A[i] == B[(i+x) % A.length] ，其中 % 为取余运算。

 

// 示例 1：

// 输入：nums = [3,4,5,1,2]
// 输出：true
// 解释：[1,2,3,4,5] 为有序的源数组。
// 可以轮转 x = 3 个位置，使新数组从值为 3 的元素开始：[3,4,5,1,2] 。
// 示例 2：

// 输入：nums = [2,1,3,4]
// 输出：false
// 解释：源数组无法经轮转得到 nums 。
// 示例 3：

// 输入：nums = [1,2,3]
// 输出：true
// 解释：[1,2,3] 为有序的源数组。
// 可以轮转 x = 0 个位置（即不轮转）得到 nums 。
 

// 提示：

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100


class Solution {
public:
    bool check(vector<int>& nums) {
        int min_pos = 0;
        int sz = nums.size();
        for(int i = 0;i < nums.size();++i) if(nums[i] <= nums[min_pos] && nums[(i + sz - 1) % sz] > nums[i]) min_pos = i;

        for(int i = min_pos;i < min_pos + sz - 1;++i) if(nums[i % sz] > nums[(i + 1) % sz]) return false;
        
        return true;
    }
};


// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         int min_pos = 0;
//         for(int i = 0;i < nums.size();++i) if(nums[i] <= nums[min_pos]) min_pos = i;
//         cout<<"min pos: "<<min_pos<<endl;

//         for(int i = 0;i < min_pos - 1;++i) if(nums[i] > nums[i + 1] && nums[i] != nums[min_pos] && nums[i + 1] != nums[min_pos]) return false;
        
//         if(min_pos != 0)
//         {
//             for(int i = min_pos;i < nums.size() - 1;++i) 
//                 if(nums[i] > nums[i + 1]) return false;
            
//             for(int i = 0;i < min_pos - 1;++i) if(nums[min_pos] != nums[i] && nums.back() > nums[i]) return false;
//         }
//         else
//         {
//             for(int i = min_pos;i < nums.size() - 1;++i) 
//                 if(nums[i] > nums[i + 1]) return false;
//         }

//         return true;
//     }
// };

// class Solution {
// public:
//     bool check(vector<int>& nums) {
//         // 二分找最小
//         int min_pos = -1;
//         int left = 0, right = nums.size() - 1;
//         while(left <= right)
//         {
//             min_pos = left + (right - left) / 2;
//             cout<<"left: "<<left<<" right: "<<right<<endl;
//             // 边界检测
//             if(min_pos == 0 || min_pos == nums.size() - 1)
//             {
//                 if(nums[left] < nums[right]) min_pos = left;
//                 else min_pos = right;
//                 break;
//             }
//             if((nums[min_pos - 1] > nums[min_pos] && nums[min_pos + 1] > nums[min_pos])) break;
            
//             if(nums[left] < nums[min_pos] && nums[right] < nums[min_pos])
//                 left = min_pos + 1;
//             else if(nums[left] > nums[min_pos] && nums[right] > nums[min_pos])
//                 right = min_pos - 1;
//             else if(nums[left] <= nums[min_pos] && nums[min_pos] <= nums[right])
//                 right = min_pos- 1;
//             else
//                 left = min_pos + 1;
//         }

//         // min_pos前的是否都比后的大


//         for(int i = 0;i < min_pos - 1;++i) if(nums[i] > nums[i + 1]) return false;
        
//         if(min_pos != 0)
//             for(int i = min_pos;i < nums.size() - 1;++i) if(nums[i] > nums[i + 1] || nums[i] > nums[0] || nums[i + 1] > nums[0]) return false;
//         else
//             for(int i = min_pos;i < nums.size() - 1;++i) if(nums[i] > nums[i + 1]) return false;



//         return true;
//     }
// };