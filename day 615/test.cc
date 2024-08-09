/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-09 13:41:09
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-09 13:41:34
 * @FilePath: \every-little-progress\day 615\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 127. 单词接龙
// https://leetcode.cn/problems/word-ladder/description/
// 字典 wordList 中从单词 beginWord 到 endWord 的 转换序列 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk：

// 每一对相邻的单词只差一个字母。
//  对于 1 <= i <= k 时，每个 si 都在 wordList 中。注意， beginWord 不需要在 wordList 中。
// sk == endWord
// 给你两个单词 beginWord 和 endWord 和一个字典 wordList ，返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目 。如果不存在这样的转换序列，返回 0 。

 
// 示例 1：

// 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
// 输出：5
// 解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
// 示例 2：

// 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
// 输出：0
// 解释：endWord "cog" 不在字典中，所以无法进行转换。
 

// 提示：

// 1 <= beginWord.length <= 10
// endWord.length == beginWord.length
// 1 <= wordList.length <= 5000
// wordList[i].length == beginWord.length
// beginWord、endWord 和 wordList[i] 由小写英文字母组成
// beginWord != endWord
// wordList 中的所有字符串 互不相同


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> hash;
        for(const auto& e : wordList) hash[e] = false;
        if(hash.end() == hash.find(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        int len = beginWord.length(), cnt = 1;
        while(!q.empty())
        {
            ++cnt;
            int sz = q.size();
            for(int i = 0;i < sz;++i)
            {
                string tmp = q.front();
                q.pop();
                // cout<< tmp<<" ";
                for(int j = 0;j < len;++j)
                {
                    char t = tmp[j];
                    for(int ch = 'a';ch <= 'z';++ch)
                    {
                        tmp[j] = ch;
                        if(hash.end() != hash.find(tmp) && !hash[tmp])
                        {
                            if(tmp == endWord) return cnt;
                            hash[tmp] = true;
                            q.push(tmp);
                        }
                        tmp[j] = t;
                    }
                }
            }
            // cout<<endl;
        }

        return 0;
    }
};
