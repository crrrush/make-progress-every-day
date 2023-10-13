/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-01 13:48:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-01 13:50:22
 * @FilePath: \every-little-progress\day 314\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1791. 找出星型图的中心节点
// https://leetcode.cn/problems/find-center-of-star-graph/description/
// 有一个无向的 星型 图，由 n 个编号从 1 到 n 的节点组成。星型图有一个 中心 节点，并且恰有 n - 1 条边将中心节点与其他每个节点连接起来。

// 给你一个二维整数数组 edges ，其中 edges[i] = [ui, vi] 表示在节点 ui 和 vi 之间存在一条边。请你找出并返回 edges 所表示星型图的中心节点。

 

// 示例 1：


// 输入：edges = [[1,2],[2,3],[4,2]]
// 输出：2
// 解释：如上图所示，节点 2 与其他每个节点都相连，所以节点 2 是中心节点。
// 示例 2：

// 输入：edges = [[1,2],[5,1],[1,3],[1,4]]
// 输出：1
 

// 提示：

// 3 <= n <= 105
// edges.length == n - 1
// edges[i].length == 2
// 1 <= ui, vi <= n
// ui != vi
// 题目数据给出的 edges 表示一个有效的星型图

class Solution {
public:
    int find(vector<int>& v, int val)
    {
        for(int i = 0;i < v.size();++i) if(v[i] == val) return i;

        return -1;
    }
    int findCenter(vector<vector<int>>& edges) {
        int res = 0;
        if(find(edges[1], edges[0][0]) != -1) res = edges[0][0];
        else res = edges[0][1];

        return res;
    }
};