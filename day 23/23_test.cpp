#define _CRT_SECURE_NO_WARNINGS


//
//225. �ö���ʵ��ջ
//
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//
//ʵ�� MyStack �ࣺ
//
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��
//
//
//
//ע�⣺
//
//��ֻ��ʹ�ö��еĻ������� ���� Ҳ���� push to back��peek / pop from front��size �� is empty ��Щ������
//����ʹ�õ�����Ҳ��֧�ֶ��С� �����ʹ�� list ���б����� deque��˫�˶��У���ģ��һ������, ֻҪ�Ǳ�׼�Ķ��в������ɡ�
//
//
//
//ʾ����
//
//���룺
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//�����
//[null, null, null, 2, 2, false]
//
//���ͣ�
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // ���� 2
//myStack.pop(); // ���� 2
//myStack.empty(); // ���� False
//
//
//
//��ʾ��
//
//1 <= x <= 9
//������100 �� push��pop��top �� empty
//ÿ�ε��� pop �� top ����֤ջ��Ϊ��
//
//
//
//���ף����ܷ����һ��������ʵ��ջ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/implement-stack-using-queues
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//


typedef int QDataType;

// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;



// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;



// ��ʼ������ 
void QueueInit(Queue* q);

// ��β����� 
void QueuePush(Queue* q, QDataType data);

// ��ͷ������ 
void QueuePop(Queue* q);

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);

// ���ٶ��� 
void QueueDestroy(Queue* q);


// ��ʼ������ 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}

// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//������Ԫ�ز���ʼ��
	QNode* tmp = (QNode*)malloc(sizeof(QNode));
	if (tmp == NULL)
	{
		perror("malloc failed");
		exit(-1);
	}
	else
	{
		tmp->_next = NULL;
		tmp->_data = data;
	}
	//����
	if (q->_front == NULL)
	{
		q->_front = q->_rear = tmp;
	}
	else
	{
		q->_rear->_next = tmp;
		q->_rear = q->_rear->_next;
	}
	++q->size;
}

// ��ͷ������ 
void QueuePop(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	QNode* Next = q->_front->_next;
	if (Next)
	{
		free(q->_front);
		q->_front = Next;
	}
	else
	{
		q->_front = q->_rear = Next;
	}
	--q->size;
}

// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}

// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL && q->_rear == NULL;
}

// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->_front;
	while (cur)
	{
		QNode* tmp = cur->_next;
		free(cur);
		cur = tmp;
	}
	q->_front = q->_rear = NULL;
}

typedef struct {
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	QueueInit(&(obj->q1));
	QueueInit(&(obj->q2));

	return obj;
}

void myStackPush(MyStack* obj, int x) {
	if (!QueueEmpty(&(obj->q1)))
	{
		QueuePush(&(obj->q1), x);
	}
	else
	{
		QueuePush(&(obj->q2), x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* empty = &obj->q1, * notempty = &obj->q2;
	if (!QueueEmpty(&(obj->q1)))
	{
		empty = &obj->q2;
		notempty = &obj->q1;
	}
	int N = QueueSize(notempty);
	while (N-- > 1)
	{
		QueuePush(empty, QueueFront(notempty));
		QueuePop(notempty);
	}
	int ret = QueueFront(notempty);
	QueuePop(notempty);
	return ret;
}

int myStackTop(MyStack* obj) {
	if (!QueueEmpty(&(obj->q1)))
	{
		return QueueBack(&(obj->q1));
	}
	else
	{
		return QueueBack(&(obj->q2));
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&(obj->q1)) && QueueEmpty(&(obj->q2));
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&(obj->q1));
	QueueDestroy(&(obj->q2));
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
