#define _CRT_SECURE_NO_WARNINGS

//
//912. ��������
//https ://leetcode.cn/problems/sort-an-array/description/
//����һ���������� nums�����㽫�������������С�
//
//ʾ�� 1��
//
//���룺nums = [5, 2, 3, 1]
//�����[1, 2, 3, 5]
//
//ʾ�� 2��
//
//���룺nums = [5, 1, 1, 2, 0, 0]
//�����[0, 0, 1, 1, 2, 5]
//
//
//
//��ʾ��
//
//1 <= nums.length <= 5 * 104
//- 5 * 104 <= nums[i] <= 5 * 104




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int GetMid(int* a, int left, int right)
{
	int mid = (right + left) / 2;

	if ((a[mid] >= a[right] && a[mid] <= a[left]) || (a[mid] >= a[left] && a[mid] <= a[right]))
		return mid;
	else if ((a[left] <= a[right] && a[left] >= a[mid]) || (a[left] <= a[mid] && a[left] >= a[right]))
		return left;
	else
		return right;
}


typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);

// ��ջ 
void StackPush(Stack* ps, STDataType data);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);

// ��ʼ��ջ 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// ��ջ 
void StackPush(Stack* ps, STDataType data)
{
	assert(ps);
	if (ps->_top == ps->_capacity)
	{
		int newcapacity = ps->_capacity == 0 ? 4 : ps->_capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->_a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc failed");
			exit(-1);
		}
		ps->_a = tmp;
		ps->_capacity = newcapacity;
	}
	ps->_a[ps->_top] = data;
	ps->_top++;
}

// ��ջ 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}

// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

// ����ջ 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_capacity = ps->_top = 0;
}

int PartSort1(int* a, int left, int right)
{
	// ����ȡ��
	int mid = GetMid(a, left, right);
	//printf("[%d,%d]-%d\n", left, right, mid);

	Swap(&a[left], &a[mid]);

	int keyi = left;
	while (left < right)
	{
		// 6 6 6 6 6
		// R��С
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// L�Ҵ�
		while (left < right && a[left] <= a[keyi])
		{
			++left;
		}

		if (left < right)
			Swap(&a[left], &a[right]);
	}

	int meeti = left;

	Swap(&a[meeti], &a[keyi]);

	return meeti;
}

// �ڿӷ�
int PartSort2(int* a, int left, int right)
{
	// ����ȡ��
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// �ұ���С�����߿�
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;

		// ����Ҵ���ұ߿�
		while (left < right && a[left] <= key)
		{
			++left;
		}

		a[hole] = a[left];
		hole = left;
	}

	a[hole] = key;
	return hole;
}

// ǰ��ָ�뷨
int PartSort3(int* a, int left, int right)
{
	// ����ȡ��
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		// ��С
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[keyi], &a[prev]);

	return prev;
}

// ��Ϣ10:33����
// [begin, end]
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}

	//if (end - begin <= 8)
	//{
	//	InsertSort(a + begin, end - begin + 1);
	//}
	//else
	//{
	int keyi = PartSort3(a, begin, end);
	//[begin, keyi-1] keyi [keyi+1, end]

	QuickSort(a, begin, keyi - 1);
	QuickSort(a, keyi + 1, end);
	//}
}

void QuickSortNonR(int* a, int begin, int end)
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		/*if (left >= right)
		{
			continue;
		}*/

		int keyi = PartSort1(a, left, right);
		// [left, keyi-1] keyi [keyi+1,right]

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < keyi - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestroy(&st);
}



int* sortArray(int* nums, int numsSize, int* returnSize) {

	QuickSortNonR(nums, 0, numsSize - 1);

	*returnSize = numsSize;
	return nums;
}