

// 1287. 有序数组中出现次数超过25%的元素
// https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/
// 给你一个非递减的 有序 整数数组，已知这个数组中恰好有一个整数，它的出现次数超过数组元素总数的 25%。

// 请你找到并返回这个整数

 

// 示例：

// 输入：arr = [1,2,2,6,6,6,6,7,10]
// 输出：6
 

// 提示：

// 1 <= arr.length <= 10^4
// 0 <= arr[i] <= 10^5

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int cnt = 0;
        int num = arr[0];
        for(const auto& e : arr)
        {
            if(e == num) ++cnt;
            else
            {
                if(cnt > arr.size() / 4) return num;
                num = e;
                cnt = 1;
            }
        }

        return num;
    }
};