#define _CRT_SECURE_NO_WARNINGS

//������ 17.04. ��ʧ������

//
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//
//ע�⣺�����������ԭ�������Ķ�
//
//ʾ�� 1��
//
//���룺[3, 0, 1]
//�����2
//
//
//
//ʾ�� 2��
//
//���룺[9, 6, 4, 2, 3, 5, 7, 0, 1]
//�����8
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/missing-number-lcci
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//


int missingNumber(int* nums, int numsSize) {
    int* tmp = malloc((numsSize + 1) * sizeof(int));
    if (tmp == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    int i = 0;
    for (i = 0; i <= numsSize; i++)
    {
        tmp[i] = i;
    }
    for (i = 0; i < numsSize; i++)
    {
        tmp[nums[i]] = -1;
    }
    for (i = 0; i <= numsSize; i++)
    {
        if (tmp[i] != -1)
            return tmp[i];
    }
    free(tmp);
    tmp = NULL;
    return -1;
}
