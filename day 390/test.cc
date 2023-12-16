/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-16 13:01:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-16 13:02:49
 * @FilePath: \every-little-progress\day 390\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1441. 用栈操作构建数组
// https://leetcode.cn/problems/build-an-array-with-stack-operations/description/
// 给你一个数组 target 和一个整数 n。每次迭代，需要从  list = { 1 , 2 , 3 ..., n } 中依次读取一个数字。

// 请使用下述操作来构建目标数组 target ：

// "Push"：从 list 中读取一个新元素， 并将其推入数组中。
// "Pop"：删除数组中的最后一个元素。
// 如果目标数组构建完成，就停止读取更多元素。
// 题目数据保证目标数组严格递增，并且只包含 1 到 n 之间的数字。

// 请返回构建目标数组所用的操作序列。如果存在多个可行方案，返回任一即可。

 

// 示例 1：

// 输入：target = [1,3], n = 3
// 输出：["Push","Push","Pop","Push"]
// 解释： 
// 读取 1 并自动推入数组 -> [1]
// 读取 2 并自动推入数组，然后删除它 -> [1]
// 读取 3 并自动推入数组 -> [1,3]
// 示例 2：

// 输入：target = [1,2,3], n = 3
// 输出：["Push","Push","Push"]
// 示例 3：

// 输入：target = [1,2], n = 4
// 输出：["Push","Push"]
// 解释：只需要读取前 2 个数字就可以停止。
 

// 提示：

// 1 <= target.length <= 100
// 1 <= n <= 100
// 1 <= target[i] <= n
// target 严格递增


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> oper;
        int pos = 0, pnum = 1;
        for(int i = 0;i < target.size();++i)
        {
            while(pnum < target[i])
            {
                oper.push_back("Push");
                oper.push_back("Pop");
                ++pnum;
            }
            if(pnum++ == target[i]) oper.push_back("Push");
        }

        return oper;
    }
};