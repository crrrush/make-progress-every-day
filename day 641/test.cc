/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-09-08 22:04:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-09-08 22:04:59
 * @FilePath: \every-little-progress\day 641\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 978. 最长湍流子数组
// https://leetcode.cn/problems/longest-turbulent-subarray/description/
// 给定一个整数数组 arr ，返回 arr 的 最大湍流子数组的长度 。

// 如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是 湍流子数组 。

// 更正式地来说，当 arr 的子数组 A[i], A[i+1], ..., A[j] 满足仅满足下列条件时，我们称其为湍流子数组：

// 若 i <= k < j ：
// 当 k 为奇数时， A[k] > A[k+1]，且
// 当 k 为偶数时，A[k] < A[k+1]；
// 或 若 i <= k < j ：
// 当 k 为偶数时，A[k] > A[k+1] ，且
// 当 k 为奇数时， A[k] < A[k+1]。
 

// 示例 1：

// 输入：arr = [9,4,2,10,7,8,8,1,9]
// 输出：5
// 解释：arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
// 示例 2：

// 输入：arr = [4,8,12,16]
// 输出：2
// 示例 3：

// 输入：arr = [100]
// 输出：1
 

// 提示：

// 1 <= arr.length <= 4 * 104
// 0 <= arr[i] <= 109


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int n = arr.size();
        int dp[40001] = { 0 };
        dp[1] = dp[2] = 1;
        if(n >= 2) dp[2] = (arr[0] == arr[1] ? 1 : 2);

        int ret = dp[2];
        for(int i = 3;i <= n;++i)
        {
            if((arr[i - 3] < arr[i - 2] && arr[i - 2] > arr[i - 1])
            || (arr[i - 3] > arr[i - 2] && arr[i - 2] < arr[i - 1]))
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = (arr[i - 2] == arr[i - 1] ? 1 : 2);
            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};
