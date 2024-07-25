

// 692. 前K个高频单词
// https://leetcode.cn/problems/top-k-frequent-words/description/
// 给定一个单词列表 words 和一个整数 k ，返回前 k 个出现次数最多的单词。

// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率， 按字典顺序 排序。

 

// 示例 1：

// 输入: words = ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出: ["i", "love"]
// 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//     注意，按字母顺序 "i" 在 "love" 之前。
// 示例 2：

// 输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// 输出: ["the", "is", "sunny", "day"]
// 解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//     出现次数依次为 4, 3, 2 和 1 次。
 

// 注意：

// 1 <= words.length <= 500
// 1 <= words[i] <= 10
// words[i] 由小写英文字母组成。
// k 的取值范围是 [1, 不同 words[i] 的数量]
 

// 进阶：尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。

class Solution {
    struct cmp
    {
        bool operator()(const pair<string, int>& k1, const pair<string, int>& k2)
        {
            if(k1.second > k2.second) return true;
            else if(k1.second == k2.second) return k1.first < k2.first;
            else return false;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hash;
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> heap;

        for(const auto& e : words) ++hash[e];
        int i = 0;
        auto it = hash.begin();
        // for(;i < k && it != hash.end();++i) heap.push(*it++);
        for(;i < k;++i) heap.push(*it++);
        while(it != hash.end())
        {
            heap.push(*it++);
            heap.pop();
        }
        // 另一种思路，可以建小堆，遍历hash，堆入k个值，然后遇到比堆顶大的值就入堆，出堆，更换最小值

        vector<string> res(k);
        i = k - 1;
        while(!heap.empty())
        {
            res[i--] = heap.top().first;
            heap.pop();
        }
        // reverse(res.begin(), res.end());
        return res;
    }
};

// class Solution {
//     struct cmp
//     {
//         bool operator()(const pair<string, int>& k1, const pair<string, int>& k2)
//         {
//             if(k1.second < k2.second) return true;
//             else if(k1.second == k2.second) return k1.first > k2.first;
//             else return false;
//         }
//     };
// public:
//     vector<string> topKFrequent(vector<string>& words, int k) {
//         unordered_map<string, int> hash;
//         priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> heap;

//         for(const auto& e : words) ++hash[e];
//         for(const auto& e : hash) heap.push(e);
//         // 另一种思路，可以建小堆，遍历hash，堆入k个值，然后遇到比堆顶大的值就入堆，出堆，更换最小值

//         vector<string> res;
//         while(k--)
//         {
//             res.push_back(heap.top().first);
//             heap.pop();
//         }

//         return res;
//     }
// };

