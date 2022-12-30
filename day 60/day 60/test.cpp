#define _CRT_SECURE_NO_WARNINGS
//
//260. 只出现一次的数字 III
//https ://leetcode.cn/problems/single-number-iii/description/
//
//给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
//
//你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 1, 3, 2, 5]
//输出：[3, 5]
//解释：[5, 3] 也是有效的答案。
//
//示例 2：
//
//输入：nums = [-1, 0]
//输出：[-1, 0]
//
//示例 3：
//
//输入：nums = [0, 1]
//输出：[1, 0]
//
//
//
//提示：
//
//2 <= nums.length <= 3 * 104
//- 231 <= nums[i] <= 231 - 1
//除两个只出现一次的整数外，nums 中的其他数字都出现两次
//



class Solution {
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
public:
    vector<int> singleNumber(vector<int>& nums) {
        //返回答案
        vector<int> res;
        ShellSort(nums);

        int tmp = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            if (tmp != nums[i])
            {
                if (count == 1)
                    res.push_back(tmp);
                if (i + 1 == nums.size())
                    res.push_back(nums[i]);

                count = 1;
                tmp = nums[i];
            }
            else
                ++count;
        }


        return res;
    }
};