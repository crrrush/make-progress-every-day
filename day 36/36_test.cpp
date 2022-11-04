#define _CRT_SECURE_NO_WARNINGS

//
//912. 排序数组
//https ://leetcode.cn/problems/sort-an-array/description/
//给你一个整数数组 nums，请你将该数组升序排列。
//
//示例 1：
//
//输入：nums = [5, 2, 3, 1]
//输出：[1, 2, 3, 5]
//
//示例 2：
//
//输入：nums = [5, 1, 1, 2, 0, 0]
//输出：[0, 0, 1, 1, 2, 5]
//
//
//
//提示：
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
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

// 初始化栈 
void StackInit(Stack* ps);

// 入栈 
void StackPush(Stack* ps, STDataType data);

// 出栈 
void StackPop(Stack* ps);

// 获取栈顶元素 
STDataType StackTop(Stack* ps);

// 获取栈中有效元素个数 
int StackSize(Stack* ps);

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);

// 销毁栈 
void StackDestroy(Stack* ps);

// 初始化栈 
void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

// 入栈 
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

// 出栈 
void StackPop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	ps->_top--;
}

// 获取栈顶元素 
STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->_a[ps->_top - 1];
}

// 获取栈中有效元素个数 
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}

// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0;
}

// 销毁栈 
void StackDestroy(Stack* ps)
{
	assert(ps);
	free(ps->_a);
	ps->_capacity = ps->_top = 0;
}

int PartSort1(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMid(a, left, right);
	//printf("[%d,%d]-%d\n", left, right, mid);

	Swap(&a[left], &a[mid]);

	int keyi = left;
	while (left < right)
	{
		// 6 6 6 6 6
		// R找小
		while (left < right && a[right] >= a[keyi])
		{
			--right;
		}

		// L找大
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

// 挖坑法
int PartSort2(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int key = a[left];
	int hole = left;
	while (left < right)
	{
		// 右边找小，填到左边坑
		while (left < right && a[right] >= key)
		{
			--right;
		}

		a[hole] = a[right];
		hole = right;

		// 左边找大，填到右边坑
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

// 前后指针法
int PartSort3(int* a, int left, int right)
{
	// 三数取中
	int mid = GetMid(a, left, right);
	Swap(&a[left], &a[mid]);

	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		// 找小
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[keyi], &a[prev]);

	return prev;
}

// 休息10:33继续
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