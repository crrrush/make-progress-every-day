#define _CRT_SECURE_NO_WARNINGS


//169. 多数元素
//https ://leetcode.cn/problems/majority-element/description/
//给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n / 2 ⌋ 的元素。
//
//你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//
//
//
//示例 1：
//
//输入：nums = [3, 2, 3]
//输出：3
//
//示例 2：
//
//输入：nums = [2, 2, 1, 1, 1, 2, 2]
//输出：2
//
//
//提示：
//
//n == nums.length
//1 <= n <= 5 * 104
//- 109 <= nums[i] <= 109
//
//
//
//进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。



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
				if (a[end] < tmp)//调升降序
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

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 堆排序
void AdjustDown(int* pa, int N, int parent)
{
	assert(pa);
	int MinChild = parent * 2 + 1;
	while (MinChild < N)
	{
		//if (MinChild + 1 < N && pa[MinChild] < pa[MinChild + 1])//大堆
		if (MinChild + 1 < N && pa[MinChild] > pa[MinChild + 1])//小堆
		{
			MinChild += 1;
		}
		//if (pa[MinChild] > pa[parent])//大堆
		if (pa[MinChild] < pa[parent])//小堆
		{
			Swap(&pa[MinChild], &pa[parent]);
			parent = MinChild;
			MinChild = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	assert(a);

	//建堆
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; --i)//建小堆
	{
		AdjustDown(a, n, i);
	}

	for (i = 1; i < n; ++i)
	{
		Swap(&a[0], &a[n - i]);//置后，降序
		AdjustDown(a, n - i, 0);
	}

}

int majorityElement(int* nums, int numsSize) {
	HeapSort(nums, numsSize);
	return nums[numsSize / 2];
}