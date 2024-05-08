

// 面试题 17.19. 消失的两个数字
// https://leetcode.cn/problems/missing-two-lcci/description/
// 给定一个数组，包含从 1 到 N 所有的整数，但其中缺了两个数字。你能在 O(N) 时间内只用 O(1) 的空间找到它们吗？

// 以任意顺序返回这两个数字均可。

// 示例 1:

// 输入: [1]
// 输出: [2,3]
// 示例 2:

// 输入: [2,3]
// 输出: [1,4]
// 提示：

// nums.length <= 30000

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int x_sum = 0;
        for(int i = 1;i <= nums.size() + 2;++i) x_sum ^= i;
        for(const auto& e : nums) x_sum ^= e;

        // int flag = x_sum ^ (x_sum & (x_sum - 1)); // 取最右侧的1作为标志位
        int flag = (x_sum == INT_MIN ? 1 : x_sum & -x_sum);

        int n1 = 0;
        int n2 = 0;
        for(int i = 1;i <= nums.size() + 2;++i)
        {
            if(flag & i)
                n1 ^= i;
            else
                n2 ^= i;
        }
        for(const auto& e : nums)
        {
            if(flag & e)
                n1 ^= e;
            else
                n2 ^= e;
        }

        return {n1, n2};
    }
};


// class Solution {
// public:
//     vector<int> missingTwo(vector<int>& nums) {
//         unordered_set<int> hash;
//         for(const auto& e : nums) hash.insert(e);
//         vector<int> ans;
//         for(int i = 1;i <= nums.size() + 2;++i) if(hash.find(i) == hash.end()) ans.push_back(i);
//         return ans;
//     }
// };
