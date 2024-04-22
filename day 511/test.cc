/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-22 20:40:22
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-22 20:40:45
 * @FilePath: \every-little-progress\day 511\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 173. 点名
// https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/
// 某班级 n 位同学的学号为 0 ~ n-1。点名结果记录于升序数组 records。假定仅有一位同学缺席，请返回他的学号。

 

// 示例 1:

// 输入: records = [0,1,2,3,5]
// 输出: 4
// 示例 2:

// 输入: records = [0, 1, 2, 3, 4, 5, 6, 8]
// 输出: 7
 

// 提示：

// 1 <= records.length <= 10000

class Solution {
public:
    // 1. 哈希
    // 2. 暴力
    // 3. 异或
    // 4. 数学（高斯求和） 等差数列的求和公式 + 遍历减去每一个数
    int takeAttendance(vector<int>& records) {
        int left = 0, right = records.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;

            if(records[mid] == mid)
                left = mid + 1;
            else
                right = mid;
        }
        // 首尾不清楚缺哪一个
        // if(left == 0 || left == records.size() - 1) if(records[left] == left) return left + 1;

        return records[left] == left ? left + 1 : left;
    }
};