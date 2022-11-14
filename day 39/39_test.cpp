#define _CRT_SECURE_NO_WARNINGS

//
//747. 至少是其他数字两倍的最大数
//https ://leetcode.cn/problems/largest-number-at-least-twice-of-others/description/
//给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
//
//请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 - 1 。
//
//
//
//示例 1：
//
//输入：nums = [3, 6, 1, 0]
//输出：1
//解释：6 是最大的整数，对于数组中的其他整数，6 至少是数组中其他元素的两倍。6 的下标是 1 ，所以返回 1 。
//
//示例 2：
//
//输入：nums = [1, 2, 3, 4]
//输出： - 1
//解释：4 没有超过 3 的两倍大，所以返回 - 1 。
//
//示例 3：
//
//输入：nums = [1]
//输出：0
//解释：因为不存在其他数字，所以认为现有数字 1 至少是其他数字的两倍。
//

int dominantIndex(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    int first = 0, second = 1;
    if (nums[first] < nums[second])
    {
        first = 1;
        second = 0;
    }
    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] > nums[first])
        {
            second = first;
            first = i;
        }
        else if (nums[i] > nums[second])
        {
            second = i;
        }
    }
    if (nums[first] < 2 * nums[second])
        return -1;
    else
        return first;
}
