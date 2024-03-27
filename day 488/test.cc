/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-27 10:51:23
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-27 10:51:48
 * @FilePath: \every-little-progress\day 488\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1089. 复写零
// https://leetcode.cn/problems/duplicate-zeros/description/
// 给你一个长度固定的整数数组 arr ，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。

// 注意：请不要在超过该数组长度的位置写入元素。请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。

 

// 示例 1：

// 输入：arr = [1,0,2,3,0,4,5,0]
// 输出：[1,0,0,2,3,0,0,4]
// 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
// 示例 2：

// 输入：arr = [1,2,3]
// 输出：[1,2,3]
// 解释：调用函数后，输入的数组将被修改为：[1,2,3]
 

// 提示：

// 1 <= arr.length <= 104
// 0 <= arr[i] <= 9



class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int sz = -1;
        int e_pos = 0;

        // e_pos找到最后一个数的下一位
        while(e_pos < arr.size())
        {
            if(0 == arr[e_pos])
            {
                ++sz;
            }

            if(sz == arr.size() - 1)
            {
                arr[sz] = 0;
                --sz;
                break;
            }

            ++sz;
            ++e_pos;
            if(sz == arr.size() - 1) break;
        }

        // 校正
        --e_pos;

        for(int i = e_pos;i >= 0 && sz != i;--i)
        {
            if(0 == arr[i])
            {
                arr[sz - 1] = arr[sz] = 0;
                sz -= 2;
            }
            else
                arr[sz--] = arr[i];
        }
    }
};