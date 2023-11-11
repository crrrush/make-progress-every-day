/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-11 13:45:04
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-11 13:45:45
 * @FilePath: \every-little-progress\day 355\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 2895. 最小处理时间
// https://leetcode.cn/problems/minimum-processing-time/description/
// 你有 n 颗处理器，每颗处理器都有 4 个核心。现有 n * 4 个待执行任务，每个核心只执行 一个 任务。

// 给你一个下标从 0 开始的整数数组 processorTime ，表示每颗处理器最早空闲时间。另给你一个下标从 0 开始的整数数组 tasks ，表示执行每个任务所需的时间。返回所有任务都执行完毕需要的 最小时间 。

// 注意：每个核心独立执行任务。

 

// 示例 1：

// 输入：processorTime = [8,10], tasks = [2,2,3,1,8,7,4,5]
// 输出：16
// 解释：
// 最优的方案是将下标为 4, 5, 6, 7 的任务分配给第一颗处理器（最早空闲时间 time = 8），下标为 0, 1, 2, 3 的任务分配给第二颗处理器（最早空闲时间 time = 10）。 
// 第一颗处理器执行完所有任务需要花费的时间 = max(8 + 8, 8 + 7, 8 + 4, 8 + 5) = 16 。
// 第二颗处理器执行完所有任务需要花费的时间 = max(10 + 2, 10 + 2, 10 + 3, 10 + 1) = 13 。
// 因此，可以证明执行完所有任务需要花费的最小时间是 16 。
// 示例 2：

// 输入：processorTime = [10,20], tasks = [2,3,1,2,5,8,4,3]
// 输出：23
// 解释：
// 最优的方案是将下标为 1, 4, 5, 6 的任务分配给第一颗处理器（最早空闲时间 time = 10），下标为 0, 2, 3, 7 的任务分配给第二颗处理器（最早空闲时间 time = 20）。 
// 第一颗处理器执行完所有任务需要花费的时间 = max(10 + 3, 10 + 5, 10 + 8, 10 + 4) = 18 。 
// 第二颗处理器执行完所有任务需要花费的时间 = max(20 + 2, 20 + 1, 20 + 2, 20 + 3) = 23 。 
// 因此，可以证明执行完所有任务需要花费的最小时间是 23 。
 

// 提示：

// 1 <= n == processorTime.length <= 25000
// 1 <= tasks.length <= 105
// 0 <= processorTime[i] <= 109
// 1 <= tasks[i] <= 109
// tasks.length == 4 * n


class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        int min = -1;
        sort(tasks.begin(), tasks.end());
        sort(processorTime.begin(), processorTime.end());

        size_t pos = tasks.size() - 1;
        for(const auto& e : processorTime)
        {
            if(min < (e + tasks[pos])) min = (e + tasks[pos]);
            pos -= 4;
        }

        return min;
    }
};

// class Solution {
//     int Max(const int& time, const int& x1, const int& x2, const int& x3, const int& x4)
//     {
//         int max = x1 > x2 ? x1 : x2;
//         if(max < x3) max = x3;
//         if(max < x4) max = x4;
//         return time + max;
//     }
// public:
//     int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
//         int min = -1;
//         sort(tasks.begin(), tasks.end());
//         sort(processorTime.begin(), processorTime.end());

//         // for(const auto& e : tasks) cout<<e<<" ";
//         // cout<<endl;

//         for(const auto& e : processorTime)
//         {
//             int t1 = tasks.back();
//             tasks.pop_back();
//             int t2 = tasks.back();
//             tasks.pop_back();            
//             int t3 = tasks.back();
//             tasks.pop_back();            
//             int t4 = tasks.back();
//             tasks.pop_back();

//             int maxtime = Max(e, t1, t2, t3, t4);
//             if(min < maxtime) min = maxtime;
//             // cout<<"e:"<<e<<" "<<"t:"<<t4<<" "<<min<<"\n";
//         }

//         return min;
//     }
// };