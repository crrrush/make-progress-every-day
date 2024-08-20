/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-20 11:30:46
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-20 11:31:25
 * @FilePath: \every-little-progress\day 625\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 207. 课程表
// https://leetcode.cn/problems/course-schedule/description/
// 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

// 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

// 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
// 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：numCourses = 2, prerequisites = [[1,0]]
// 输出：true
// 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
// 示例 2：

// 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
// 输出：false
// 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 

// 提示：

// 1 <= numCourses <= 2000
// 0 <= prerequisites.length <= 5000
// prerequisites[i].length == 2
// 0 <= ai, bi < numCourses
// prerequisites[i] 中的所有课程对 互不相同

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector< pair<int, vector<int>> > map(numCourses, {0, vector<int>()});
        // 入度， 指向的边

        // 1. 初始化 建图
        for(const auto& e : prerequisites)
        {
            map[e[1]].second.push_back(e[0]);
           ++(map[e[0]].first);
        }
        
        // 2.入队列 拓扑排序
        queue<int> q; 
        for(int i = 0;i < numCourses;++i) if(0 == map[i].first) q.push(i);
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int n = q.front();
                q.pop();
                auto [in_line, out_lines] = map[n];
                for(auto& e : out_lines) if(0 == --(map[e].first)) q.push(e);
            }
        }

        for(const auto& [in_line, out_lines] : map) if(in_line > 0) return false;

        return true;
    }
};
