
// 寻找峰值 

// 链接：https://www.nowcoder.com/questionTerminal/fcf87540c4f347bcb4cf720b5b350c76
// 来源：牛客网

// 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。
// 1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于
// 2.假设 nums[-1] = nums[n] = −∞−∞
// 3.对于所有有效的 i 都有 nums[i] != nums[i + 1]
// 4.你可以使用O(logN)的时间复杂度实现此问题吗？

// 数据范围：
// 1≤nums.length≤2×105 1≤nums.length≤2×105 
// −231<=nums[i]<=231−1−231<=nums[i]<=231−1

// 如输入[2,4,1,2,7,8,4]时，会形成两个山峰，一个是索引为1，峰值为4的山峰，另一个是索引为5，峰值为8的山峰，如下图所示：
// 示例1
// 输入

// [2,4,1,2,7,8,4]

// 输出

// 1

// 说明

// 4和8都是峰值元素，返回4的索引1或者8的索引5都可以     

// 示例2
// 输入

// [1,2,3,1]

// 输出

// 2

// 说明

// 3 是峰值元素，返回其索引 2     

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

/*
int findPeakElement(int* nums, int numsLen ) {
    int i = 0;
    for(i = 0;i < numsLen;i++)
    {
        if(nums[i] > nums[i + 1])
        {
            return i;
        }
    }
    return i;
}*/


int findPeakElement(int* nums, int numsLen ) {
    if(nums[0] > nums[1])
        return 0;
    if(nums[numsLen - 1] > nums[numsLen - 2])
        return numsLen - 1;
    
    int left = 0;
    int right = numsLen - 1;
    
    while(left < right)
    {
        int mid = (left + right) / 2;
        if(mid == left || mid == right)
        {
            if(nums[left] > nums[right])
                return left;
            else
                return right;
        }
        if(nums[mid - 1] < nums[mid] && nums[mid] < nums[mid + 1])
            left = mid;
        else if(nums[mid - 1] > nums[mid] && nums[mid] > nums[mid + 1])
            right = mid;
        else
            return mid;
    }
    return left;
}