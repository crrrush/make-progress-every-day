#define _CRT_SECURE_NO_WARNINGS

//724. Ѱ������������±�
//https ://leetcode.cn/problems/find-pivot-index/description/
//
//����һ���������� nums ������������ �����±� ��
//
//���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ͡�
//
//��������±�λ����������ˣ���ô�����֮����Ϊ 0 ����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ�����á�
//
//��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� - 1 ��
//
//
//
//ʾ�� 1��
//
//���룺nums = [1, 7, 3, 6, 5, 6]
//�����3
//���ͣ�
//�����±��� 3 ��
//�����֮�� sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ��
//�Ҳ���֮�� sum = nums[4] + nums[5] = 5 + 6 = 11 ��������ȡ�
//
//ʾ�� 2��
//
//���룺nums = [1, 2, 3]
//����� - 1
//���ͣ�
//�����в���������������������±ꡣ
//
//ʾ�� 3��
//
//���룺nums = [2, 1, -1]
//�����0
//���ͣ�
//�����±��� 0 ��
//�����֮�� sum = 0 �����±� 0 ��಻����Ԫ�أ���
//�Ҳ���֮�� sum = nums[1] + nums[2] = 1 + -1 = 0 ��

int pivotIndex(int* nums, int numsSize) {
    int sumLeft = 0, sumRight = 0;
    int midi = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        sumRight += nums[i];
    }
    while (midi < numsSize)
    {
        if (midi > 0)
            sumLeft += nums[midi - 1];

        sumRight -= nums[midi];

        if (sumLeft == sumRight)
            break;

        ++midi;
    }
    if (midi == numsSize)
        return -1;
    else
        return midi;
}