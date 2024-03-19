/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-19 21:06:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-19 21:07:24
 * @FilePath: \every-little-progress\day 481\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// LCR 060. 前 K 个高频元素
// https://leetcode.cn/problems/g5c51o/description/
// 给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。

 

// 示例 1:

// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]
// 示例 2:

// 输入: nums = [1], k = 1
// 输出: [1]
 

// 提示：

// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的
 

// 进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

 

// 注意：本题与主站 347 题相同：https://leetcode-cn.com/problems/top-k-frequent-elements/

class Solution {
    struct cmp
    {
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) { return p1.second > p2.second; }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(const auto& e : nums) ++hash[e];
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for(const auto& [x, y] : hash)
        {
            if(pq.size() < k)
            {
                pq.push(make_pair(x, y));
            }
            else
            {
                if(pq.top().second < y)
                {
                    pq.pop();
                    pq.push(make_pair(x, y));
                }
            }
        }

        vector<int> res;
        res.reserve(k);
        while(!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }

        return res;
    }
};
