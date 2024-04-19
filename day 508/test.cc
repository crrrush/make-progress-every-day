/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-19 12:35:04
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-19 12:35:30
 * @FilePath: \every-little-progress\day 508\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 852. 山脉数组的峰顶索引
// https://leetcode.cn/problems/peak-index-in-a-mountain-array/description/
// 符合下列属性的数组 arr 称为 山脉数组 ：
// arr.length >= 3
// 存在 i（0 < i < arr.length - 1）使得：
// arr[0] < arr[1] < ... arr[i-1] < arr[i] 
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// 给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

// 你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

 

// 示例 1：

// 输入：arr = [0,1,0]
// 输出：1
// 示例 2：

// 输入：arr = [0,2,1,0]
// 输出：1
// 示例 3：

// 输入：arr = [0,10,5,2]
// 输出：1
 

// 提示：

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// 题目数据保证 arr 是一个山脉数组

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            
            if(arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};