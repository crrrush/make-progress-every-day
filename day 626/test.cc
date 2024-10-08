/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-21 13:09:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-21 13:09:49
 * @FilePath: \every-little-progress\day 626\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 210. 课程表 II
// https://leetcode.cn/problems/course-schedule-ii/description/
// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

 

// 示例 1：

// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：[0,1]
// 解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
// 示例 2：

// 输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
// 输出：[0,2,1,3]
// 解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
// 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
// 示例 3：

// 输入：numCourses = 1, prerequisites = []
// 输出：[0]
 

// 提示：
// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= numCourses * (numCourses - 1)
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// ai != bi
// 所有[ai, bi] 互不相同

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector< pair<int, vector<int>> > map(numCourses, {0, vector<int>()});

        // 初始化，建图
        for(const auto& e : prerequisites)
        {
            map[e[1]].second.push_back(e[0]);
            ++(map[e[0]].first);
        }

        // 起始点入队列，拓扑排序
        vector<int> ret;
        queue<int> q;
        for(int i = 0;i < numCourses;++i) if(0 == map[i].first) q.push(i);
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int n = q.front();
                q.pop();
                ret.push_back(n);
                auto out_lines = map[n].second;
                for(auto& e : out_lines) if(0 == --(map[e].first)) q.push(e);
            }
        }

        for(const auto& [in_line, out_lines] : map) if(0 != in_line) return vector<int>();
        return ret;
    }
};
