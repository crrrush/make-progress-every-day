#define _CRT_SECURE_NO_WARNINGS

//
//645. ����ļ���
//https ://leetcode.cn/problems/set-mismatch/description/
//���� s ������ 1 �� n �����������ҵ��ǣ���Ϊ���ݴ��󣬵��¼�������ĳһ�����ָ����˳��˼������������һ�����ֵ�ֵ�����¼��� ��ʧ��һ������ ���� ��һ�������ظ� ��
//
//����һ������ nums �����˼��� S ���������Ľ����
//
//�����ҳ��ظ����ֵ����������ҵ���ʧ�����������������������ʽ���ء�
//
//
//
//ʾ�� 1��
//
//���룺nums = [1, 2, 2, 4]
//�����[2, 3]
//
//ʾ�� 2��
//
//���룺nums = [1, 1]
//�����[1, 2]
//
//
//
//��ʾ��
//
//2 <= nums.length <= 104
//1 <= nums[i] <= 104
//



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // ϣ������
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

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
	int* ret = (int*)malloc(2 * sizeof(int));
	assert(ret);
	*returnSize = 2;
	int cur = 1;
	ShellSort(nums, numsSize);
	int count = nums[0];
	while (cur < numsSize)
	{

		int prev = cur - 1;
		if (nums[cur] == nums[prev])
			ret[0] = nums[cur];

		count += nums[cur];
		++cur;
	}
	printf("%d", ret[0]);
	ret[1] = ret[0] + (((numsSize * numsSize) + numsSize) / 2) - count;
	return ret;
}

