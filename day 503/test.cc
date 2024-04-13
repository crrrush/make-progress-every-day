

// 30. 串联所有单词的子串
// https://leetcode.cn/problems/substring-with-concatenation-of-all-words/description/
// 给定一个字符串 s 和一个字符串数组 words。 words 中所有字符串 长度相同。

//  s 中的 串联子串 是指一个包含  words 中所有字符串以任意顺序排列连接起来的子串。

// 例如，如果 words = ["ab","cd","ef"]， 那么 "abcdef"， "abefcd"，"cdabef"， "cdefab"，"efabcd"， 和 "efcdab" 都是串联子串。 "acdbef" 不是串联子串，因为他不是任何 words 排列的连接。
// 返回所有串联子串在 s 中的开始索引。你可以以 任意顺序 返回答案。

 

// 示例 1：

// 输入：s = "barfoothefoobarman", words = ["foo","bar"]
// 输出：[0,9]
// 解释：因为 words.length == 2 同时 words[i].length == 3，连接的子字符串的长度必须为 6。
// 子串 "barfoo" 开始位置是 0。它是 words 中以 ["bar","foo"] 顺序排列的连接。
// 子串 "foobar" 开始位置是 9。它是 words 中以 ["foo","bar"] 顺序排列的连接。
// 输出顺序无关紧要。返回 [9,0] 也是可以的。
// 示例 2：

// 输入：s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
// 输出：[]
// 解释：因为 words.length == 4 并且 words[i].length == 4，所以串联子串的长度必须为 16。
// s 中没有子串长度为 16 并且等于 words 的任何顺序排列的连接。
// 所以我们返回一个空数组。
// 示例 3：

// 输入：s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
// 输出：[6,9,12]
// 解释：因为 words.length == 3 并且 words[i].length == 3，所以串联子串的长度必须为 9。
// 子串 "foobarthe" 开始位置是 6。它是 words 中以 ["foo","bar","the"] 顺序排列的连接。
// 子串 "barthefoo" 开始位置是 9。它是 words 中以 ["bar","the","foo"] 顺序排列的连接。
// 子串 "thefoobar" 开始位置是 12。它是 words 中以 ["the","foo","bar"] 顺序排列的连接。
 

// 提示：

// 1 <= s.length <= 104
// 1 <= words.length <= 5000
// 1 <= words[i].length <= 30
// words[i] 和 s 由小写英文字母组成


class Solution {
public:
    // O(n)
    vector<int> findSubstring(string s, vector<string>& words) {
        const int n = words.size();
        const int len = words[0].size();
        if(n * len > s.size()) return vector<int>();

        vector<int> res;
        unordered_map<string, int> hash1;
        for(const auto& e : words) ++hash1[e];

        for(int i = 0;i < len;++i)
        {
            unordered_map<string, int> hash2;
            for(int cnt = 0, left = i, right = i;right + len <= s.size();right += len)
            {
                // 入窗口
                string in = s.substr(right, len);
                ++hash2[in];
                if(hash1.count(in) && hash2[in] <= hash1[in]) ++cnt;
                // 出窗口
                if(right - left + 1 > len * n)
                {
                    string out = s.substr(left, len);
                    if(hash1.count(out) && hash2[out] <= hash1[out]) --cnt;;
                    --hash2[out];
                    left += len;
                }
                if(n == cnt) res.push_back(left);
            }
        }

        return res;
    }
};

// class Solution {
// public:
//     // O(n^2)
//     vector<int> findSubstring(string s, vector<string>& words) {
//         const int n = words.size();
//         const int len = words[0].size();
//         if(n * len > s.size()) return vector<int>();

//         vector<int> res;
//         unordered_map<string, int> hash;
//         for(const auto& e : words) ++hash[e];

//         // 大窗口套小窗口

//         int left = 0;
//         while(left + len * n <= s.size())
//         {
//             int right = left, cnt = 0;
//             // 入窗口
//             while(right <= left + len * n)
//             {
//                 auto it = hash.find(string(s, right, len));
//                 if(hash.end() != it && it->second > 0)
//                 {
//                     --it->second;
//                     ++cnt;
//                     right += len;
//                 }
//                 else
//                 {
//                     if(n == cnt) res.push_back(left);
//                     // 回收串联集
//                     for(int i = left;i < right;i += len) ++hash[string(s, i, len)];
//                     cnt = 0;
//                     break;
//                 }
//             }
//             if(n == cnt) res.push_back(left);

//             ++left;
//         }

//         return res;
//     }
// };

// class Solution { // failed
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         const int n = words.size();
//         const int len = words[0].size();
//         if(n * len > s.size()) return vector<int>();

//         vector<int> res;
//         unordered_map<string, int> hash;
//         for(const auto& e : words) ++hash[e];

//         int left = 0, right = 0, cnt = 0;
//         while(right < s.size())
//         {
//             string tmp(s, right, len);
//             cout<<tmp<<" ";
//             auto it = hash.find(tmp);
//             // 入窗口
//             if(hash.end() != it && it->second > 0)
//             {
//                 --it->second;
//                 ++cnt;
//                 // right += len;
//                 ++right;
//             }
//             else
//             {
//                 if(cnt == n) res.push_back(left); // 是子串则记录

//                 if((right - len) % len == 0)
//                 {
//                     // 出窗口
//                     if(hash.end() != it)
//                     {
//                         // 回收串联集
//                         while(left < right && 0 == it->second)
//                         {
//                             ++hash[string(s, left, len)];
//                             left += len;
//                             --cnt;
//                         }

//                     }
//                     else
//                     {
//                         // 回收串联集
//                         while(left < right)
//                         {
//                             ++hash[string(s, left, len)];
//                             left += len;
//                         }
//                         cnt = 0;
//                         // right += len;
//                         left = ++right;
//                     }
//                 }
//                 else
//                 {
//                     ++right;
//                 }
//             }
//         }
//         if(cnt == n) res.push_back(left); // 是子串则记录

//         return res;
//     }
// };
