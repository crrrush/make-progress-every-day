#define _CRT_SECURE_NO_WARNINGS


//����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
//
//
//
//ʾ�� 1:
//
//����: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//��� : [5, 6, 7, 1, 2, 3, 4]
//���� :
//    ������ת 1 �� : [7, 1, 2, 3, 4, 5, 6]
//    ������ת 2 �� : [6, 7, 1, 2, 3, 4, 5]
//    ������ת 3 �� : [5, 6, 7, 1, 2, 3, 4]
//
//    ʾ�� 2 :
//
//    ���룺nums = [-1, -100, 3, 99], k = 2
//    �����[3, 99, -1, -100]
//    ���� :
//    ������ת 1 �� : [99, -1, -100, 3]
//    ������ת 2 �� : [3, 99, -1, -100]
//
//    ��Դ�����ۣ�LeetCode��
//    ���ӣ�https ://leetcode.cn/problems/rotate-array
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


void reverse(int* pa, int sz)
{
    assert(pa);
    int sta = 0;
    int end = sz - 1;
    while (sta < end)
    {
        int tmp = pa[sta];
        pa[sta] = pa[end];
        pa[end] = tmp;
        sta++;
        end--;
    }
}



void rotate(int* nums, int numsSize, int k) {
    /*
    //����һ��
    k %= numsSize;
    while(k--)
    {
        int tmp = nums[numsSize - 1];
        for(int i = numsSize - 1;i > 0;--i)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
    //����ʱ������
    */

    /*
    k %= numsSize;//��������   ���Ż��ռ临�Ӷ�
    int* tmp = malloc(numsSize * sizeof(int));
    if(tmp == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    int i = 0;
    for(i = 0;i < numsSize;++i)
    {
        if(i < k)
        {
            tmp[i] = nums[numsSize - k + i];
        }
        else
        {
            tmp[i] = nums[i - k];
        }
    }
    for(i = 0;i < numsSize;++i)
    {
        nums[i] = tmp[i];
    }
    free(tmp);
    tmp = NULL;
    */

    //������  
    k %= numsSize;
    reverse(nums + numsSize - k, k);
    reverse(nums, numsSize - k);
    reverse(nums, numsSize);

}
