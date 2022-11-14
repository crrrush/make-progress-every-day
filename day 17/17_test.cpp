#define _CRT_SECURE_NO_WARNINGS

//88. �ϲ�������������
//
//���������� �ǵݼ�˳�� ���е��������� nums1 �� nums2�������������� m �� n ���ֱ��ʾ nums1 �� nums2 �е�Ԫ����Ŀ��
//
//���� �ϲ� nums2 �� nums1 �У�ʹ�ϲ��������ͬ���� �ǵݼ�˳�� ���С�
//
//ע�⣺���գ��ϲ������鲻Ӧ�ɺ������أ����Ǵ洢������ nums1 �С�Ϊ��Ӧ�����������nums1 �ĳ�ʼ����Ϊ m + n������ǰ m ��Ԫ�ر�ʾӦ�ϲ���Ԫ�أ��� n ��Ԫ��Ϊ 0 ��Ӧ���ԡ�nums2 �ĳ���Ϊ n ��
//
//
//
//ʾ�� 1��
//
//���룺nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3
//�����[1, 2, 2, 3, 5, 6]
//���ͣ���Ҫ�ϲ�[1, 2, 3] ��[2, 5, 6] ��
//�ϲ������[1, 2, 2, 3, 5, 6] ������б��Ӵֱ�ע��Ϊ nums1 �е�Ԫ�ء�
//
//ʾ�� 2��
//
//���룺nums1 = [1], m = 1, nums2 = [], n = 0
//�����[1]
//���ͣ���Ҫ�ϲ�[1] ��[] ��
//�ϲ������[1] ��
//
//ʾ�� 3��
//
//���룺nums1 = [0], m = 0, nums2 = [1], n = 1
//�����[1]
//���ͣ���Ҫ�ϲ���������[] ��[1] ��
//�ϲ������[1] ��
//ע�⣬��Ϊ m = 0 ������ nums1 ��û��Ԫ�ء�nums1 �н���� 0 ������Ϊ��ȷ���ϲ��������˳����ŵ� nums1 �С�
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/merge-sorted-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//




void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* tmp = (int*)malloc((m + n) * sizeof(int));
    int i = 0;
    int n1 = 0, n2 = 0;
    while (n1 < m && n2 < n)
    {
        if (nums1[n1] < nums2[n2])
        {
            tmp[i++] = nums1[n1++];
        }
        else
        {
            tmp[i++] = nums2[n2++];
        }
    }
    while (n1 < m)
    {
        tmp[i++] = nums1[n1++];
    }
    while (n2 < n)
    {
        tmp[i++] = nums2[n2++];
    }
    for (i = 0; i < m + n; i++)
    {
        nums1[i] = tmp[i];
    }
}
