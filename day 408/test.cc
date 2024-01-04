/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-04 11:29:56
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-04 11:30:31
 * @FilePath: \every-little-progress\day 408\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 941. 有效的山脉数组
// https://leetcode.cn/problems/valid-mountain-array/description/
// 给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。

// 让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：

// arr.length >= 3
// 在 0 < i < arr.length - 1 条件下，存在 i 使得：
// arr[0] < arr[1] < ... arr[i-1] < arr[i] 
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 



 

// 示例 1：

// 输入：arr = [2,1]
// 输出：false
// 示例 2：

// 输入：arr = [3,5,5]
// 输出：false
// 示例 3：

// 输入：arr = [0,3,2,1]
// 输出：true
 

// 提示：

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 104


class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() < 3) return false;
        // 二分
        // 暴力
        bool up = true;
        if(arr[0] > arr[1]) return false;
        for(int i = 0;i < arr.size() - 1;++i)
        {
            if(up && arr[i] > arr[i + 1])
                up = false;
            else if(up && arr[i] == arr[i + 1])
                return false;
            else if(!up && arr[i] <= arr[i + 1])
                return false;
        }
        if(up) return false;

        return true;
    }
};