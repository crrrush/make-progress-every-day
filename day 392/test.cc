/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-18 14:59:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-18 15:00:44
 * @FilePath: \every-little-progress\day 392\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 500. 键盘行
// https://leetcode.cn/problems/keyboard-row/description/
// 给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

// 美式键盘 中：

// 第一行由字符 "qwertyuiop" 组成。
// 第二行由字符 "asdfghjkl" 组成。
// 第三行由字符 "zxcvbnm" 组成。
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

// 1 <= words.length <= 20
// 1 <= words[i].length <= 100
// words[i] 由英文字母（小写和大写字母）组成


class board
{
public:
    board()
    {
        string one("qwertyuiop");
        string two("asdfghjkl");
        string three("zxcvbnm");
        for(const auto& e : one) map[e] = 1;
        for(const auto& e : two) map[e] = 2;
        for(const auto& e : three) map[e] = 3;
    }

    int operator[](const char& c) 
    { 
        if(isupper(c)) return map[c + 32];
        return map[c];
    }
private:
    unordered_map<char, int> map;
};

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(const auto& e : words)
        {
            int tmp = _map[e[0]];
            bool flag = true;
            for(const auto& r : e)
            {
                if(_map[r] != tmp)
                {
                    flag = false;
                    break;
                }
            }
            if(flag) res.push_back(e);
        }
        return res;
    }
private:
    static board _map;
};

board Solution::_map;
