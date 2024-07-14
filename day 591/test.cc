

// LCR 130. 衣橱整理
// https://leetcode.cn/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/description/
// 家居整理师将待整理衣橱划分为 m x n 的二维矩阵 grid，其中 grid[i][j] 代表一个需要整理的格子。整理师自 grid[0][0] 开始 逐行逐列 地整理每个格子。

// 整理规则为：在整理过程中，可以选择 向右移动一格 或 向下移动一格，但不能移动到衣柜之外。同时，不需要整理 digit(i) + digit(j) > cnt 的格子，其中 digit(x) 表示数字 x 的各数位之和。

// 请返回整理师 总共需要整理多少个格子。

 

// 示例 1：

// 输入：m = 4, n = 7, cnt = 5
// 输出：18
 

// 提示：

// 1 <= n, m <= 100
// 0 <= cnt <= 20


class Solution {
    int _m, _n, _cnt;
    int ret = 0;
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    int visi[101][101];

    int digit(int x)
    {
        int sum = 0;
        while(x)
        {
            sum += (x % 10);
            x /= 10;
        }
        return sum;
    }

    void dfs(int i, int j)
    {
        if(digit(i) + digit(j) > _cnt)
        {
            visi[i][j] = -1;
            return;
        }
        visi[i][j] = 1;
        ++ret;
        for(int k = 0;k < 4;++k)
        {
            int x = i + dx[k], y = j + dy[k];
            if(x >= 0 && x < _m && y >= 0 && y < _n && 0 == visi[x][y]) dfs(x , y);
        }
        // visi[i][j] = 0;
    }
public:
    int wardrobeFinishing(int m, int n, int cnt) {
        _m = m;
        _n = n;
        _cnt = cnt;
        dfs(0, 0);        
        return ret;
    }
};


// class Solution {
//     int digit(int x)
//     {
//         int sum = 0;
//         while(x)
//         {
//             sum += (x % 10);
//             x /= 10;
//         }
//         return sum;
//     }
// public:
//     int wardrobeFinishing(int m, int n, int cnt) {
//         int ret = 0;
//         for(int i = 0;i < n;++i)
//         {
//             for(int j = 0;j < m;++j)
//             {
//                 if(digit(i) + digit(j) <= cnt)
//                 {
//                     // cout<<i<<" "<<j<<endl;
//                     ++ret;
//                 }
//                 else
//                 {
//                     break;
//                 }
//             }
//         }
//         return ret;
//     }
// };

// class Solution {
//     int digit(int x)
//     {
//         int sum = 0;
//         while(x)
//         {
//             sum += (x % 10);
//             x /= 10;
//         }
//         return sum;
//     }

//     int M = 0, N = 0, C = 0;

//     int dfs(int i, int j)
//     {
//         int ret = 0;
//         if(i + 1 < M && digit(i + 1) + digit(j) <= C)
//         {
//             ret += dfs(i + 1, j) + 1;
//         }
//         if(j + 1 < N && digit(i) + digit(j + 1) <= C) ret += dfs(i, j + 1) + 1;
//         return ret;
//     }
// public:
//     int wardrobeFinishing(int m, int n, int cnt) {
//         M = m;
//         N = n;
//         C = cnt;
//         // int ret = 0;
//         // for(int i = 0;i < m;++i)
//         // {
//         //     for(int j = 0;j < n;++j)
//         //     {
//         //         if(digit(i) + digit(j) <= cnt)
//         //         {
//         //             cout<<i<<" "<<j<<endl;
//         //             ++ret;
//         //         }
//         //     }
//         // }
//         return dfs(0, 0);
//     }
// };
