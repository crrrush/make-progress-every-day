/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-10 13:07:18
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-10 13:08:55
 * @FilePath: \every-little-progress\day 354\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1037. 有效的回旋镖
// https://leetcode.cn/problems/valid-boomerang/description/
// 给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，如果这些点构成一个 回旋镖 则返回 true 。

// 回旋镖 定义为一组三个点，这些点 各不相同 且 不在一条直线上 。

 

// 示例 1：

// 输入：points = [[1,1],[2,3],[3,2]]
// 输出：true
// 示例 2：

// 输入：points = [[1,1],[2,2],[3,3]]
// 输出：false
 

// 提示：

// points.length == 3
// points[i].length == 2
// 0 <= xi, yi <= 100


class Solution {
    bool has_same_point(vector<vector<int>>& points)
    {
        return (points[0][0] == points[1][0] && points[0][1] == points[1][1])
            || (points[1][0] == points[2][0] && points[1][1] == points[2][1])
            || (points[0][0] == points[2][0] && points[0][1] == points[2][1]);
    }
public:
    // y = kx + b
    // k = (y1 - y2)/(x1 - x2)
    // y1 = k * x1 + b
    bool isBoomerang(vector<vector<int>>& points) {
        if(has_same_point(points)) return false;
        
        if(points[0][0] == points[1][0]) return points[2][0] == points[0][0] ? false : true;
        else if(points[0][1] == points[1][1]) return points[2][1] == points[0][1] ? false : true;
        else if(points[0][0] == points[2][0]) return points[1][0] == points[0][0] ? false : true;
        else if(points[0][1] == points[2][1]) return points[1][1] == points[0][1] ? false : true;
        else if(points[1][0] == points[2][0]) return points[0][0] == points[1][0] ? false : true;
        else if(points[1][1] == points[2][1]) return points[0][1] == points[1][1] ? false : true;

        double k1 = (double)(points[0][1] - points[1][1]) / (double)(points[0][0] - points[1][0]);
        double k2 = (double)(points[0][1] - points[2][1]) / (double)(points[0][0] - points[2][0]);

        return k1 != k2;


        // double k = (double)(points[0][1] - points[1][1]) / (double)(points[0][0] - points[1][0]);
        // double b = (double)points[0][1] - k * ((double)points[0][0]);
        // return (double)points[2][1] == (double)points[2][0] * k + b ? false : true;
    }
};