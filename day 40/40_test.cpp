#define _CRT_SECURE_NO_WARNINGS


//
//349. 两个数组的交集
//https ://leetcode.cn/problems/intersection-of-two-arrays/description/
//
//给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
//
//
//
//示例 1：
//
//输入：nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//输出：[2]
//
//示例 2：
//
//输入：nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//输出：[9, 4]
//解释：[4, 9] 也是可通过的
//
//
//
//提示：
//
//1 <= nums1.length, nums2.length <= 1000
//0 <= nums1[i], nums2[i] <= 1000
//


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ret = (int*)malloc((nums1Size + nums2Size) * sizeof(int));
    ShellSort(nums1, nums1Size);
    ShellSort(nums2, nums2Size);
    int n1 = 0, n2 = 0;
    *returnSize = 0;
    while (n1 < nums1Size && n2 < nums2Size)
    {
        if (nums1[n1] == nums2[n2])
        {
            ret[(*returnSize)] = nums1[n1];
            (*returnSize)++;
            n1++;
            n2++;
            while (n1 < nums1Size && nums1[n1 - 1] == nums1[n1])
                n1++;
            while (n2 < nums2Size && nums2[n2 - 1] == nums2[n2])
                n2++;
        }
        else if (nums1[n1] > nums2[n2])
        {
            n2++;
            while (n2 < nums2Size && nums2[n2 - 1] == nums2[n2])
                n2++;
        }
        else
        {
            n1++;
            while (n1 < nums1Size && nums1[n1 - 1] == nums1[n1])
                n1++;
        }
    }
    return ret;
}