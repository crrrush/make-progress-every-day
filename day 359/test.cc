/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-15 15:02:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-15 15:03:54
 * @FilePath: \every-little-progress\day 359\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1266. 访问所有点的最小时间
// https://leetcode.cn/problems/minimum-time-visiting-all-points/description/
// 平面上有 n 个点，点的位置用整数坐标表示 points[i] = [xi, yi] 。请你计算访问所有这些点需要的 最小时间（以秒为单位）。

// 你需要按照下面的规则在平面上移动：

// 每一秒内，你可以：
// 沿水平方向移动一个单位长度，或者
// 沿竖直方向移动一个单位长度，或者
// 跨过对角线移动 sqrt(2) 个单位长度（可以看作在一秒内向水平和竖直方向各移动一个单位长度）。
// 必须按照数组中出现的顺序来访问这些点。
// 在访问某个点时，可以经过该点后面出现的点，但经过的那些点不算作有效访问。
 

// 示例 1：



// 输入：points = [[1,1],[3,4],[-1,0]]
// 输出：7
// 解释：一条最佳的访问路径是： [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
// 从 [1,1] 到 [3,4] 需要 3 秒 
// 从 [3,4] 到 [-1,0] 需要 4 秒
// 一共需要 7 秒
// 示例 2：

// 输入：points = [[3,2],[-2,2]]
// 输出：5
 

// 提示：

// points.length == n
// 1 <= n <= 100
// points[i].length == 2
// -1000 <= points[i][0], points[i][1] <= 1000

class Solution {
    int cross_time(const int& x1, const int& y1, const int& x2, const int& y2)
    {
        if(x1 == x2) return abs(y1 - y2);
        if(y1 == y2) return abs(x1 - x2);
        int x = abs(x1 - x2);
        int y = abs(y1 - y2);
        return x > y ? x : y;
    }
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int time = 0;
        for(int i = 0;i < points.size() - 1;++i) time += cross_time(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        return time;
    }
};