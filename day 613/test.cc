

// 面试题 08.01. 三步问题
// https://leetcode.cn/problems/three-steps-problem-lcci/description/
// 三步问题。有个小孩正在上楼梯，楼梯有n阶台阶，小孩一次可以上1阶、2阶或3阶。实现一种方法，计算小孩有多少种上楼梯的方式。结果可能很大，你需要对结果模1000000007。

// 示例1:

//  输入：n = 3 
//  输出：4
//  说明: 有四种走法
// 示例2:

//  输入：n = 5
//  输出：13
// 提示:

// n范围在[1, 1000000]之间


class Solution {
public:
    int waysToStep(int n) {
        if(1 == n) return 1;
        else if(2 == n) return 2;
        else if(3 == n) return 4;
        int dp[4];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 4;
        for(int i = 3;i < n;++i)
        {
            dp[3] = (((dp[0] + dp[1]) % 1000000007) + dp[2]) % 1000000007;
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
        }
        return dp[3];
    }
};


// class Solution {
//     static vector<int> dp;

//     void init()
//     {
//         if(0 != dp.size()) return;
//         dp.resize(1000000);
//         dp[1] = 1;
//         dp[2] = 2;
//         dp[3] = 4;
//         for(int i = 4;i < dp.size();++i) dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000007 + dp[i - 3]) % 1000000007);
//     }
// public:
//     int waysToStep(int n) {
//         init();
//         return dp[n];
//     }
// };

// vector<int> Solution::dp;


// class Solution {
// public:
//     int waysToStep(int n) {
//         if(1 == n) return 1;
//         else if(2 == n) return 2;
//         else if(3 == n) return 4;
//         vector<int> dp(n);
//         dp[0] = 1;
//         dp[1] = 2;
//         dp[2] = 4;
//         for(int i = 3;i < dp.size();++i) dp[i] = (((dp[i - 1] + dp[i - 2]) % 1000000007 + dp[i - 3]) % 1000000007);
//         return dp[n - 1];
//     }
// };


// class Solution {
//     int memo[1000000];

//     int dfs(int n)
//     {
//         if(n <= 0) return 0;
//         if(-1 != memo[n]) return memo[n];

//         int cnt = 0;
//         // cout<<n<<" ";
//         for(int i = 1;i <= 3;++i)
//         {
//             cnt += dfs(n - i);
//             cnt %= 1000000007;
//         }
//         memo[n] = cnt;
//         return cnt;
//     }
// public: // 记忆化搜索 dfs
//     int waysToStep(int n) {
//         for(int i = 0;i < 1000000;++i) memo[i] = -1;
//         memo[1] = 1;
//         memo[2] = 2;
//         memo[3] = 4;
//         return dfs(n);
//     }
// };
