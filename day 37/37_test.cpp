#define _CRT_SECURE_NO_WARNINGS

//
//645. 错误的集合
//https ://leetcode.cn/problems/set-mismatch/description/
//集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。
//
//给定一个数组 nums 代表了集合 S 发生错误后的结果。
//
//请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。
//
//
//
//示例 1：
//
//输入：nums = [1, 2, 2, 4]
//输出：[2, 3]
//
//示例 2：
//
//输入：nums = [1, 1]
//输出：[1, 2]
//
//
//
//提示：
//
//2 <= nums.length <= 104
//1 <= nums[i] <= 104
//



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
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

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
	int* ret = (int*)malloc(2 * sizeof(int));
	assert(ret);
	*returnSize = 2;
	int cur = 1;
	ShellSort(nums, numsSize);
	int count = nums[0];
	while (cur < numsSize)
	{

		int prev = cur - 1;
		if (nums[cur] == nums[prev])
			ret[0] = nums[cur];

		count += nums[cur];
		++cur;
	}
	printf("%d", ret[0]);
	ret[1] = ret[0] + (((numsSize * numsSize) + numsSize) / 2) - count;
	return ret;
}

