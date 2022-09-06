#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#include<stdlib.h>

#include<assert.h>

//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ������ҳ�������[1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    //���������¼�����Ƿ����
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);
    int i = 0;
    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] <= numsSize && nums[i] >= 1)
            a[nums[i]] = 0;//��¼
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