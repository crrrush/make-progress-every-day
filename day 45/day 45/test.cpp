<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS

//448. 找到所有数组中消失的数字
//https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
//
//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。请你找出所有在[1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
//
//
//
//示例 1：
//
//输入：nums = [4, 3, 2, 7, 8, 2, 3, 1]
//输出：[5, 6]
//
//示例 2：
//
//输入：nums = [1, 1]
//输出：[2]
//
//
//
//提示：
//
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
//
//进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗 ? 你可以假定返回的数组不算在额外空间内。


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    //开辟数组记录数字是否出现
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);


    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        a[nums[i]] = 0;//记录
    }


    int* ret = (int*)malloc(sizeof(int) * numsSize);
    assert(ret);
    for (i = 1; i <= numsSize; i++)
    {
        if (a[i] != 0)
        {
            ret[*returnSize] = i;
            (*returnSize)++;
        }
    }
    free(a);
    return ret;
=======
#define _CRT_SECURE_NO_WARNINGS

//448. 找到所有数组中消失的数字
//https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
//
//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。请你找出所有在[1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
//
//
//
//示例 1：
//
//输入：nums = [4, 3, 2, 7, 8, 2, 3, 1]
//输出：[5, 6]
//
//示例 2：
//
//输入：nums = [1, 1]
//输出：[2]
//
//
//
//提示：
//
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
//
//进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗 ? 你可以假定返回的数组不算在额外空间内。


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    //开辟数组记录数字是否出现
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);


    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        a[nums[i]] = 0;//记录
    }


    int* ret = (int*)malloc(sizeof(int) * numsSize);
    assert(ret);
    for (i = 1; i <= numsSize; i++)
    {
        if (a[i] != 0)
        {
            ret[*returnSize] = i;
            (*returnSize)++;
        }
    }
    free(a);
    return ret;
>>>>>>> 24eeab1884a9e6869269cceb29f4a6d4f3d05ea1
}