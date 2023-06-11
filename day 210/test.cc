

// 219. 存在重复元素 II
// https://leetcode.cn/problems/contains-duplicate-ii/

// 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：nums = [1,2,3,1], k = 3
// 输出：true

// 示例 2：

// 输入：nums = [1,0,1,1], k = 1
// 输出：true

// 示例 3：

// 输入：nums = [1,2,3,1,2,3], k = 2
// 输出：false

 

 

// 提示：

//     1 <= nums.length <= 105
//     -109 <= nums[i] <= 109
//     0 <= k <= 105



class Solution {
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> hash;
        for(const auto& e : nums)
            hash[e]++;
        
        // for(const auto& e : hash)
        //     cout << e.first << " : " << e.second << endl;
        for(const auto& e : hash) if(e.second > 1) return true;

        return false;
    }
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> hash;
        for(const auto& e : nums)
            hash[e] = -1;
        

        for(int i = 0;i < nums.size();++i)
        {
            if(hash[nums[i]] == -1) hash[nums[i]] = i;
            else
            {
                if(abs(i - hash[nums[i]]) <= k) return true;
                else hash[nums[i]] = i;
            }
        }

        return false;
    }
};

