

// 733. 图像渲染
// https://leetcode.cn/problems/flood-fill/description/
// 有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。

// 你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。

// 为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。

// 最后返回 经过上色渲染后的图像 。

 

// 示例 1:



// 输入: image = [[1,1,1],[1,1,0],[1,0,1]]，sr = 1, sc = 1, newColor = 2
// 输出: [[2,2,2],[2,2,0],[2,0,1]]
// 解析: 在图像的正中间，(坐标(sr,sc)=(1,1)),在路径上所有符合条件的像素点的颜色都被更改成2。
// 注意，右下角的像素没有更改为2，因为它不是在上下左右四个方向上与初始点相连的像素点。
// 示例 2:

// 输入: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
// 输出: [[2,2,2],[2,2,2]]
 

// 提示:

// m == image.length
// n == image[i].length
// 1 <= m, n <= 50
// 0 <= image[i][j], newColor < 216
// 0 <= sr < m
// 0 <= sc < n


class Solution {
    // BFS
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        int m = image.size();
        int n = image[0].size();
        int oldc = image[sr][sc];
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0;i < sz;++i)
            {
                int r = q.front().first, c = q.front().second;
                image[r][c] = color;
                q.pop();
                for(int j = 0;j < 4;++j)
                {
                    int x = dx[j] + r, y = dy[j] + c;
                    if(x >= 0 && x < m && y >= 0 && y < n && oldc == image[x][y]) q.push({x, y});
                }
            }
        }
        
        return image;
    }
};


// class Solution {
//     int oldc = 0, newc = 0;
//     // bool check[50][50];
//     int m = 0, n = 0;

//     int dx[4] = {1, -1, 0, 0};
//     int dy[4] = {0, 0, 1, -1};

//     void dfs(vector<vector<int>>& image, int i, int j)
//     {
//         image[i][j] = newc;

//         for(int k = 0;k < 4;++k)
//         {
//             int x = i + dx[k], y = j + dy[k];
//             // if(x >= 0 && x < image.size() && y >= 0 && y < image[i].size() && !check[x][y] && oldc == image[x][y])
//             if(x >= 0 && x < m && y >= 0 && y < n && oldc == image[x][y])
//             {
//                 // image[x][y] = newc;
//                 // check[x][y] = true;
//                 dfs(image, x, y);
//             }
//         }
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         if(image[sr][sc] == color) return image;
//         m = image.size();
//         n = image[0].size();
//         oldc = image[sr][sc];
//         image[sr][sc] = newc = color;
//         dfs(image, sr, sc);
//         return image;
//     }
// };
