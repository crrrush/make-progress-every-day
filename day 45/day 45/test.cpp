<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS

//448. �ҵ�������������ʧ������
//https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
//
//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ������ҳ�������[1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
//
//
//
//ʾ�� 1��
//
//���룺nums = [4, 3, 2, 7, 8, 2, 3, 1]
//�����[5, 6]
//
//ʾ�� 2��
//
//���룺nums = [1, 1]
//�����[2]
//
//
//
//��ʾ��
//
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
//
//���ף������ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�Ϊ O(n) ������½����������� ? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    //���������¼�����Ƿ����
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);


    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
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
=======
#define _CRT_SECURE_NO_WARNINGS

//448. �ҵ�������������ʧ������
//https ://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/description/
//
//����һ���� n ������������ nums ������ nums[i] ������[1, n] �ڡ������ҳ�������[1, n] ��Χ�ڵ�û�г����� nums �е����֣������������ʽ���ؽ����
//
//
//
//ʾ�� 1��
//
//���룺nums = [4, 3, 2, 7, 8, 2, 3, 1]
//�����[5, 6]
//
//ʾ�� 2��
//
//���룺nums = [1, 1]
//�����[2]
//
//
//
//��ʾ��
//
//n == nums.length
//1 <= n <= 105
//1 <= nums[i] <= n
//
//���ף������ڲ�ʹ�ö���ռ���ʱ�临�Ӷ�Ϊ O(n) ������½����������� ? ����Լٶ����ص����鲻���ڶ���ռ��ڡ�


int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int i = 0;
    //���������¼�����Ƿ����
    int* a = (int*)malloc(sizeof(int) * (numsSize + 1));
    assert(a);


    for (i = 0; i <= numsSize; i++)
        a[i] = 1;

    *returnSize = 0;
    for (i = 0; i < numsSize; i++)
    {
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
>>>>>>> 24eeab1884a9e6869269cceb29f4a6d4f3d05ea1
}