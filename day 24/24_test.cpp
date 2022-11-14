#define _CRT_SECURE_NO_WARNINGS

//232. ��ջʵ�ֶ���
//
//�����ʹ������ջʵ�������ȳ����С�����Ӧ��֧��һ�����֧�ֵ����в�����push��pop��peek��empty����
//
//ʵ�� MyQueue �ࣺ
//
//void push(int x) ��Ԫ�� x �Ƶ����е�ĩβ
//int pop() �Ӷ��еĿ�ͷ�Ƴ�������Ԫ��
//int peek() ���ض��п�ͷ��Ԫ��
//boolean empty() �������Ϊ�գ����� true �����򣬷��� false
//
//˵����
//
//�� ֻ�� ʹ�ñ�׼��ջ���� ���� Ҳ����ֻ�� push to top, peek / pop from top, size, �� is empty �����ǺϷ��ġ�
//����ʹ�õ�����Ҳ��֧��ջ�������ʹ�� list ���� deque��˫�˶��У���ģ��һ��ջ��ֻҪ�Ǳ�׼��ջ�������ɡ�
//
//
//
//ʾ�� 1��
//
//���룺
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//�����
//[null, null, null, 1, 1, false]
//
//���ͣ�
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
//
//
//
//��ʾ��
//
//1 <= x <= 9
//������ 100 �� push��pop��peek �� empty
//�������в���������Ч�� �����磬һ���յĶ��в������ pop ���� peek ������
//
//
//
//���ף�
//
//���ܷ�ʵ��ÿ��������̯ʱ�临�Ӷ�Ϊ O(1) �Ķ��У����仰˵��ִ�� n ����������ʱ�临�Ӷ�Ϊ O(n) ����ʹ����һ���������ܻ��ѽϳ�ʱ�䡣
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/implement-queue-using-stacks
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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


typedef struct {
	Stack in;
	Stack out;
} MyQueue;


MyQueue* myQueueCreate() {
	MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&obj->in);
	StackInit(&obj->out);
	return obj;
}

void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->in, x);
}

int myQueuePop(MyQueue* obj) {
	if (StackEmpty(&obj->out))
	{
		while (!StackEmpty(&obj->in))
		{
			StackPush(&obj->out, StackTop(&obj->in));
			StackPop(&obj->in);
		}
	}
	int ret = StackTop(&obj->out);
	StackPop(&obj->out);
	return ret;
}

int myQueuePeek(MyQueue* obj) {
	if (StackEmpty(&obj->out))
	{
		while (!StackEmpty(&obj->in))
		{
			StackPush(&obj->out, StackTop(&obj->in));
			StackPop(&obj->in);
		}
	}
	return StackTop(&obj->out);
}

bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->in) && StackEmpty(&obj->out);
}

void myQueueFree(MyQueue* obj) {
	StackDestroy(&obj->in);
	StackDestroy(&obj->out);
	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/