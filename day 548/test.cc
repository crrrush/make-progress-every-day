

// 49. 字母异位词分组
// https://leetcode.cn/problems/group-anagrams/description/
// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 

// 示例 1:

// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 示例 2:

// 输入: strs = [""]
// 输出: [[""]]
// 示例 3:

// 输入: strs = ["a"]
// 输出: [["a"]]
 

// 提示：

// 1 <= strs.length <= 104
// 0 <= strs[i].length <= 100
// strs[i] 仅包含小写字母


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable; // str pos

        for(auto& s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hashtable[tmp].push_back(s);
        }

        vector< vector<string> > ans;
        for(const auto& [x, y] : hashtable) ans.push_back(y);
        return ans;
    }
};

// class Solution {
//     struct equal_to
//     { 
//         bool operator()(const string& s1, const string& s2) const 
//         {
//             int hash[26] = { 0 };
//             for(const auto& e : s1) ++hash[e - 'a'];
//             for(const auto& e : s2) if(0 > --hash[e - 'a']) return false;
//             return true;
//         } 
//     };
//     struct str_hash
//     {
//         size_t operator()(const string& s) const
//         {
//             size_t ret = 0;
//             for(const auto& e : s) ret += e;
//             return ret;
//         }
//     };
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>, str_hash, equal_to> hashtable; // str pos

//         for(const auto& str : strs)
//         {
//             auto it = hashtable.find(str);
//             if(hashtable.end() != it)
//             {
//                 it->second.push_back(str);
//             }
//             else
//             {
//                 hashtable.insert(make_pair(str, vector<string>({str})));
//             }
//         }
//         vector< vector<string> > ans;
//         for(const auto& [x, y] : hashtable) ans.push_back(y);
//         return ans;
//     }
// };

// class Solution {
//     struct equal_to
//     { 
//         bool operator()(const string& s1, const string& s2) const 
//         {
//             int hash[26] = { 0 };
//             for(const auto& e : s1) ++hash[e - 'a'];
//             for(const auto& e : s2) if(0 > --hash[e - 'a']) return false;
//             return true;
//         } 
//     };
//     struct str_hash
//     {
//         size_t operator()(const string& s) const
//         {
//             size_t ret = 0;
//             for(const auto& e : s) ret += e;
//             return ret;
//         }
//     };
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, size_t, str_hash, equal_to> hashtable; // str pos
//         vector<vector<string> > ans;

//         for(const auto& str : strs)
//         {
//             auto it = hashtable.find(str);
//             if(hashtable.end() != it)
//             {
//                 ans[it->second].push_back(str);
//             }
//             else
//             {
//                 hashtable.insert(make_pair(str, ans.size()));
//                 ans.push_back({str});
//             }
//         }

//         return ans;
//     }
// };


// class Solution {
//     bool has_same_ch(const vector<int>& hash1, const vector<int>& hash2)
//     {
//         for(int i = 0;i < 26;++i) if(hash1[i] != hash2[i]) return false;
//         return true;
//     }

// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector< pair<size_t, vector<int>> > v_hash;
//         vector<vector<string>> ans;
//         for(const auto& str : strs)
//         {
//             vector<int> tmp(26);
//             for(const auto& e : str) ++tmp[e - 'a'];
//             bool push = true;
//             for(const auto& [pos, hash] : v_hash)
//                 if(has_same_ch(hash, tmp))
//                 {
//                     ans[pos].push_back(str);
//                     push = false;
//                     break;
//                 }

//             if(push)
//             {
//                 v_hash.push_back(make_pair(ans.size(), tmp));
//                 ans.push_back(vector<string>({str}));
//             }
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         int hash[26] = { 0 };
//         int len = 0;
//         vector<vector<string>> ans;
//         for(const auto& str : strs)
//     }
// };

