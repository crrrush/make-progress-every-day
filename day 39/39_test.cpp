#define _CRT_SECURE_NO_WARNINGS

//
//747. �������������������������
//https ://leetcode.cn/problems/largest-number-at-least-twice-of-others/description/
//����һ���������� nums ���������Ǵ��� Ψһ�� һ��������� ��
//
//�����ҳ������е����Ԫ�ز�������Ƿ� ������������ÿ���������ֵ����� ������ǣ��򷵻� ���Ԫ�ص��±� �����򷵻� - 1 ��
//
//
//
//ʾ�� 1��
//
//���룺nums = [3, 6, 1, 0]
//�����1
//���ͣ�6 ���������������������е�����������6 ����������������Ԫ�ص�������6 ���±��� 1 �����Է��� 1 ��
//
//ʾ�� 2��
//
//���룺nums = [1, 2, 3, 4]
//����� - 1
//���ͣ�4 û�г��� 3 �����������Է��� - 1 ��
//
//ʾ�� 3��
//
//���룺nums = [1]
//�����0
//���ͣ���Ϊ�������������֣�������Ϊ�������� 1 �������������ֵ�������
//

int dominantIndex(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    int first = 0, second = 1;
    if (nums[first] < nums[second])
    {
        first = 1;
        second = 0;
    }
    for (int i = 2; i < numsSize; i++)
    {
        if (nums[i] > nums[first])
        {
            second = first;
            first = i;
        }
        else if (nums[i] > nums[second])
        {
            second = i;
        }
    }
    if (nums[first] < 2 * nums[second])
        return -1;
    else
        return first;
}
