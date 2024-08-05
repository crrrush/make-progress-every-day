
// 675. 为高尔夫比赛砍树
// https://leetcode.cn/problems/cut-off-trees-for-golf-event/description/
// 你被请来给一个要举办高尔夫比赛的树林砍树。树林由一个 m x n 的矩阵表示， 在这个矩阵中：

// 0 表示障碍，无法触碰
// 1 表示地面，可以行走
// 比 1 大的数 表示有树的单元格，可以行走，数值表示树的高度
// 每一步，你都可以向上、下、左、右四个方向之一移动一个单位，如果你站的地方有一棵树，那么你可以决定是否要砍倒它。

// 你需要按照树的高度从低向高砍掉所有的树，每砍过一颗树，该单元格的值变为 1（即变为地面）。

// 你将从 (0, 0) 点开始工作，返回你砍完所有树需要走的最小步数。 如果你无法砍完所有的树，返回 -1 。

// 可以保证的是，没有两棵树的高度是相同的，并且你至少需要砍倒一棵树。

 

// 示例 1：


// 输入：forest = [[1,2,3],[0,0,4],[7,6,5]]
// 输出：6
// 解释：沿着上面的路径，你可以用 6 步，按从最矮到最高的顺序砍掉这些树。
// 示例 2：


// 输入：forest = [[1,2,3],[0,0,0],[7,6,5]]
// 输出：-1
// 解释：由于中间一行被障碍阻塞，无法访问最下面一行中的树。
// 示例 3：

// 输入：forest = [[2,3,4],[0,0,5],[8,7,6]]
// 输出：6
// 解释：可以按与示例 1 相同的路径来砍掉所有的树。
// (0,0) 位置的树，可以直接砍去，不用算步数。
 

// 提示：

// m == forest.length
// n == forest[i].length
// 1 <= m, n <= 50
// 0 <= forest[i][j] <= 109

// class Solution {
//     bool hash[51][51];

// public:
//     int cutOffTree(vector<vector<int>>& forest) {
//     }
// };


class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int m, n;
    bool hash[51][51];
    

    int bfs(vector<vector<int>>& forest, const int& target, pair<int, int>& p)
    {
        if(target == forest[p.first][p.second]) return 0;
        queue<pair<int, int>> q;
        for(int i = 0;i < 51;++i) for(int j = 0;j < 51;++j) hash[i][j] = false;
        q.push(p);
        int cnt = 0;
        hash[p.first][p.second] = true;
        while(!q.empty())
        {
            ++cnt;
            int sz = q.size();
            while(sz--)
            {
                auto [i, j] = q.front();
                q.pop();
                for(int k = 0;k < 4;++k)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if(x >= 0 && x < m && y >= 0 && y < n && !hash[x][y] && forest[x][y] > 0)
                    {
                        hash[x][y] = true;
                        if(target == forest[x][y])
                        {
                            forest[x][y] = 1;
                            p = {x, y};
                            return cnt;
                        }
                        q.push({x, y});
                    }
                }
            }
        }

        return -1;
    }
public:
    int cutOffTree(vector<vector<int>>& forest) {
        // int hash[51][51] = { { 0 } };
        m = forest.size(), n = forest[0].size();
        set<int> s;
        for(const auto& e : forest) for(const auto& r : e) if(r > 1) s.insert(r);


        int cnt = 0;
        pair<int, int> p(0, 0);
        for(const auto& e : s)
        {
            int tmp = bfs(forest, e, p);
            // cout<<e<<" "<<p.first<<":"<<p.second<<endl;
            if(-1 == tmp) return -1;
            cnt += tmp;
        }

        return cnt;
    }
};


