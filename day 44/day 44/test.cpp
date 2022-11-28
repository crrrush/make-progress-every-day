#define _CRT_SECURE_NO_WARNINGS

//238. 除自身以外数组的乘积
//https ://leetcode.cn/problems/product-of-array-except-self/description/
//
//给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
//
//题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
//
//请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//
//
//
//示例 1:
//
//输入: nums = [1, 2, 3, 4]
//输出 : [24, 12, 8, 6]
//
//示例 2 :
//
//    输入 : nums = [-1, 1, 0, -3, 3]
//    输出 : [0, 0, 9, 0, 0]
//
//
//
//    提示：
//
//    2 <= nums.length <= 105
//    - 30 <= nums[i] <= 30
//    保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
//
//
//
//    进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
//


int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* answer = (int*)malloc(sizeof(int) * numsSize);
    int i = 0;
    answer[0] = 1;
    for (i = 1; i < numsSize; i++)
    {
        answer[i] = answer[i - 1] * nums[i - 1];
    }
    int R = 1;
    for (i = 1; i <= numsSize; i++)
    {
        answer[numsSize - i] = answer[numsSize - i] * R;
        R *= nums[numsSize - i];
    }
    *returnSize = numsSize;
    return answer;
}




/*
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int* L = (int*)malloc(sizeof(int) * numsSize);
    int* R = (int*)malloc(sizeof(int) * numsSize);
    int i= 0;
    L[0] = R[numsSize - 1] = 1;
    for(i = 1;i < numsSize;i++)
    {
        L[i] = R[numsSize - i -1] = 1;
        L[i] = L[i - 1] * nums[i - 1];
        R[numsSize - i -1] = R[numsSize - i] * nums[numsSize - i];
    }
    for(i = 0;i < numsSize;i++)
    {
        ret[i] = L[i] * R[i];
    }
    *returnSize = numsSize;
    return ret;
}*/



/*
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int i= 0,j = 0;
    int zero = 0;
    int sum = 1;
    for(i = 0;i < numsSize;i++)
    {
        if(nums[i] != 0)
            sum *= nums[i];
        else
        {
            zero = i;
            j++;
        }
    }
    if(j >= 2)
    {
        for(i = 0;i < numsSize; i++)
        {
            ret[i] = 0;
        }
    }
    else if(j == 1)
    {
        for(i = 0;i < numsSize;i++)
        {
            if(i != zero)
            {
                ret[i] = 0;
            }
            else
            {
                ret[i] = sum;
            }
        }
    }
    else
    {
        for(i = 0;i < numsSize;i++)
        {
            ret[i] = sum / nums[i];
        }
    }
    *returnSize = numsSize;
    return ret;
}
*/
/*
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* ret = (int*)malloc(sizeof(int) * numsSize);
    int i= 0,j = 0;
    for(i = 0;i < numsSize;i++)
    {
        ret[i] = 1;
        for(j = 0;j < numsSize;j++)
        {
            if(i != j)
                ret[i] *= nums[j];
        }
    }
    *returnSize = numsSize;
    return ret;
}*/