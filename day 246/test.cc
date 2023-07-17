

// 500. 键盘行
// https://leetcode.cn/problems/keyboard-row/
// 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

// 美式键盘 中：

//     第一行由字符 "qwertyuiop" 组成。
//     第二行由字符 "asdfghjkl" 组成。
//     第三行由字符 "zxcvbnm" 组成。

// American keyboard

 

// 示例 1：

// 输入：words = ["Hello","Alaska","Dad","Peace"]
// 输出：["Alaska","Dad"]

// 示例 2：

// 输入：words = ["omk"]
// 输出：[]

// 示例 3：

// 输入：words = ["adsdf","sfd"]
// 输出：["adsdf","sfd"]

 

// 提示：

//     1 <= words.length <= 20
//     1 <= words[i].length <= 100
//     words[i] 由英文字母（小写和大写字母）组成



class Solution {
    char trans(const char& a)
    {
        if(a < 'a') return a + 'a' - 'A';
        else return a;
    }
    void vsInit(vector<unordered_set<char>>& vs)
    {
        if(!vs.empty()) return;

        vector<string> vv = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        for(const auto& e : vv)
        {
            unordered_set<char> s;
            for(const auto& r : e) s.insert(r);

            vs.push_back(s);
        }

    }
    bool findWords__(const string& words)
    {
        static vector<unordered_set<char>> vs;
        vsInit(vs);

        for(const auto& e : vs)
        {
            bool flag = true;
            for(const auto& r : words)
            {
                if(e.end() == e.find(trans(r)))
                {
                    flag = false;
                    break;
                }
            } 
            if(flag) return true;
        }

        return false;
    }
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> vs;
        for(const auto& e : words)
        {
            if(findWords__(e)) vs.push_back(e);
        }

        return vs;
    }
};

// class Solution {
//     char trans(const char& a)
//     {
//         if(a < 'a') return a + 'a' - 'A';
//         else return a;
//     }
//     void vsInit(vector<set<char>>& vs)
//     {
//         if(!vs.empty()) return;

//         vector<string> vv = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
//         for(const auto& e : vv)
//         {
//             set<char> s;
//             for(const auto& r : e) s.insert(r);

//             vs.push_back(s);
//         }

//     }
//     bool findWords__(const string& words)
//     {
//         static vector<set<char>> vs;
//         vsInit(vs);

//         for(const auto& e : vs)
//         {
//             bool flag = true;
//             for(const auto& r : words)
//             {
//                 if(e.end() == e.find(trans(r)))
//                 {
//                     flag = false;
//                     break;
//                 }
//             } 
//             if(flag) return true;
//         }

//         return false;
//     }
// public:
//     vector<string> findWords(vector<string>& words) {
//         vector<string> vs;
//         for(const auto& e : words)
//         {
//             if(findWords__(e)) vs.push_back(e);
//         }

//         return vs;
//     }
// };