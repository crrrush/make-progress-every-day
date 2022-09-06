#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<assert.h>

//给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间[1, n] 内。请你找出所有在[1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    //开辟数组记录数字是否出现
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);
    int i = 0;
    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= numsSize && nums[i] >= 1)
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
}



int main()
{
    int a[] = { 4,3,2,7,8,2,3,1 };
    int sz = sizeof(a) / sizeof(a[0]);
    int n;

    int* ret = findDisappearedNumbers(a, sz, &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ret[i]);
    }
	return 0;
}