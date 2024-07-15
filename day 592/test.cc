

// 509. 斐波那契数
// https://leetcode.cn/problems/fibonacci-number/description/
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

// F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n) 。

 

// 示例 1：

// 输入：n = 2
// 输出：1
// 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
// 示例 2：

// 输入：n = 3
// 输出：2
// 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
// 示例 3：

// 输入：n = 4
// 输出：3
// 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
 

// 提示：

// 0 <= n <= 30

class Solution {
    static int dp[31];

    // 动规
    void init()
    {
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i < 31;++i) dp[i] = dp[i - 1] + dp[i - 2];
    }
public:
    int fib(int n) {
        if(1 != dp[1]) init();

        return dp[n];
    }
};

int Solution::dp[31] = { 0 };


// class Solution {
//     int mem[31];

//     // 备忘录  剪枝
//     int dfs(int n)
//     {
//         if(-1 != mem[n]) return mem[n];

//         if(0 == n || 1 == n)
//         {
//             mem[n] = n;
//             return mem[n];
//         }
        
//         mem[n] = dfs(n - 1) + dfs(n - 2);
//         return mem[n];
//     }

// public:
//     int fib(int n) {
//         for(int i = 0;i < 31;++i) mem[i] = -1;
//         return dfs(n);
//     }
// };

// class Solution {
// public:
//     int fib(int n) {
//         if(0 == n) return 0;
//         if(1 == n) return 1;
//         int prev = 0, cur = 1;
//         for(int i = 2;i <= n;++i)
//         {
//             int tmp = cur;
//             cur += prev;
//             prev = tmp;
//         }
//         return cur;
//     }
// };

// class Solution {
// public:
//     int fib(int n) {
//         if(n <= 0) return 0;
//         else if(1 == n) return 1;
//         else return fib(n - 1) + fib(n - 2);
//     }
// };
