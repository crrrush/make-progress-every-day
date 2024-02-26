

// 539. 最小时间差
// https://leetcode.cn/problems/minimum-time-difference/description/
// 给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。

 

// 示例 1：

// 输入：timePoints = ["23:59","00:00"]
// 输出：1
// 示例 2：

// 输入：timePoints = ["00:00","23:59","00:00"]
// 输出：0
 

// 提示：

// 2 <= timePoints.length <= 2 * 104
// timePoints[i] 格式为 "HH:MM"


class Solution {
    int time_sub(const pair<int, int>& t1, const pair<int, int>& t2)
    {
        if(t1.first > t2.first)
            return 60 * (t1.first - t2.first) - t2.second + t1.second;
        else if(t1.first < t2.first)
            return 60 * (24 - t2.first + t1.first) - t2.second + t1.second;
        else
            return t1.second - t2.second;
    }

public:
    int findMinDifference(vector<string>& timePoints) {
        vector<vector<bool>> clock(24, vector<bool>(60, false));
        for(const auto& e : timePoints)
        {
            size_t h = stoul(string(e, 0, 2));
            size_t m = stoul(string(e, 3, 2));

            if(clock[h][m]) return 0;
            else clock[h][m] = true;
        }

        size_t min = 24 * 60;
        pair<int, int> last_time(-1, -1);
        pair<int, int> first_time(-1, -1);
        int dif = 0;
        for(int i = 0;i < 24;++i)
        {
            for(int j = 0;j < 60;++j)
            {
                if(clock[i][j])
                {
                    // if(last_time.first != -1 && last_time.second != -1)
                    if(last_time.first != -1)
                    {
                        dif = time_sub(make_pair(i, j), last_time);
                        if(dif < min) min = dif;
                    }
                    else
                    {
                        first_time.first = i;
                        first_time.second = j;
                    }

                    last_time.first = i;
                    last_time.second = j;
                }
            }
        }

        dif = time_sub(first_time, last_time);
        if(dif < min) min = dif;

        return min;
    }
};

// class Solution {
//     int time_sub(const pair<int, int>& t1, const pair<int, int>& t2)
//     {
//         if(t1.first > t2.first)
//             return 60 * (t1.first - t2.first) - t2.second + t1.second;
//         else if(t1.first < t2.first)
//             return 60 * (24 - t2.first + t1.first) - t2.second + t1.second;
//         else
//             return t1.second - t2.second;
//     }

// public:
//     int findMinDifference(vector<string>& timePoints) {
//         vector<vector<bool>> clock(24, vector<bool>(60, false));
//         for(const auto& e : timePoints)
//         {
//             size_t h = stoul(string(e, 0, 2));
//             size_t m = stoul(string(e, 3, 2));

//             if(clock[h][m]) return 0;
//             else clock[h][m] = true;
//         }

//         size_t min = 24 * 60;
//         pair<int, int> last_time(-1, -1);
//         for(int i = 0;i < 48;++i)
//         {
//             for(int j = 0;j < 60;++j)
//             {
//                 if(clock[i % 24][j])
//                 {
//                     // if(last_time.first != -1 && last_time.second != -1)
//                     if(last_time.first != -1)
//                     {
//                         int dif = time_sub(make_pair(i % 24, j), last_time);
//                         // if(dif > 12 * 60) dif = 24 * 60 - dif;
//                         if(dif < min) min = dif;
//                     }

//                     last_time.first = i % 24;
//                     last_time.second = j;
//                 }
//             }
//         }

//         return min;
//     }
// };