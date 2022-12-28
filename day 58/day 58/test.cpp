#define _CRT_SECURE_NO_WARNINGS

//
//137. 只出现一次的数字 II
//https ://leetcode.cn/problems/single-number-ii/
//给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。
//
//你必须设计并实现线性时间复杂度的算法且不使用额外空间来解决此问题。
//
//
//
//示例 1：
//
//输入：nums = [2, 2, 3, 2]
//输出：3
//
//示例 2：
//
//输入：nums = [0, 1, 0, 1, 0, 1, 99]
//输出：99
//
//
//
//提示：
//
//1 <= nums.length <= 3 * 104
//- 231 <= nums[i] <= 231 - 1
//nums 中，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次
//


class Solution {
public:
    void ShellSort(vector<int>& a)
    {
        int gap = a.size();
        while (gap > 1)
        {
            gap = gap / 3 + 1;
            for (int i = 0; i < a.size() - gap; i++)
            {
                int end = i;
                int tmp = a[end + gap];


                //移动数据再插入
                while (end >= 0)
                {
                    if (a[end] > tmp)//调升降序
                    {
                        a[end + gap] = a[end];
                        end -= gap;
                    }
                    else
                    {
                        break;
                    }
                }
                a[end + gap] = tmp;
            }
        }
    }
    int singleNumber(vector<int>& nums) {
        ShellSort(nums);
        int tmp = nums[0];
        int count = 1;


        for (int i = 1; i < nums.size(); ++i)
        {
            if (tmp != nums[i])
            {
                if (count == 1)
                    return tmp;
                else if (i + 1 == nums.size())
                    return nums[i];

                count = 1;
                tmp = nums[i];
            }
            else
                ++count;
        }
        return nums[0];
    }
};