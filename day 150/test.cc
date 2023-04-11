
// 第一个只出现一次的字符

// 链接：https://www.nowcoder.com/questionTerminal/1c82e8cf713b4bbeb2a5b31cf5b0417c
// 来源：牛客网

// 在一个长为 字符串中找到第一个只出现一次的字符,并返回它的位置, 如果没有则返回 -1（需要区分大小写）.（从0开始计数）


// 数据范围：0≤n≤100000≤n≤10000，且字符串只有字母组成。
// 要求：空间复杂度 O(n)O(n)，时间复杂度 O(n)O(n)
// 示例1
// 输入

// "google"

// 输出

// 4

// 示例2
// 输入

// "aa"

// 输出

// -1

//#include <vector>
class Solution {
    void FindOne(string& str, vector<pair<int, int>>& find)
    {
        for(int i = 0;i < str.size();++i)
        {
            ++(find[str[i]].first);
            if(find[str[i]].second == -1)
                find[str[i]].second = i;
        }
    }
public:
    int FirstNotRepeatingChar(string str) {
        vector<pair<int, int>> find;
        find.resize(128,pair<int, int>(0,-1));
        FindOne(str, find);

        int res = str.size();
        bool flag = true;
        for(int i = 'A';i <= 'z';++i)
        {
            if(find[i].first == 1)
            {
                flag = false;
                if(find[i].second < res)
                    res = find[i].second;
            }
        }

        if(flag)
            return -1;
        else
            return res;
    }
};