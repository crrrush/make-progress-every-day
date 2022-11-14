#define _CRT_SECURE_NO_WARNINGS


//
//349. ��������Ľ���
//https ://leetcode.cn/problems/intersection-of-two-arrays/description/
//
//������������ nums1 �� nums2 ������ ���ǵĽ��� ���������е�ÿ��Ԫ��һ���� Ψһ �ġ����ǿ��� ��������������˳�� ��
//
//
//
//ʾ�� 1��
//
//���룺nums1 = [1, 2, 2, 1], nums2 = [2, 2]
//�����[2]
//
//ʾ�� 2��
//
//���룺nums1 = [4, 9, 5], nums2 = [9, 4, 9, 8, 4]
//�����[9, 4]
//���ͣ�[4, 9] Ҳ�ǿ�ͨ����
//
//
//
//��ʾ��
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
            //�ƶ������ٲ���
            while (end >= 0)
            {
                if (a[end] > tmp)//��������
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