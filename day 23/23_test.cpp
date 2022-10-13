#define _CRT_SECURE_NO_WARNINGS


//
//225. 用队列实现栈
//
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//
//实现 MyStack 类：
//
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
//
//
//
//注意：
//
//你只能使用队列的基本操作 —— 也就是 push to back、peek / pop from front、size 和 is empty 这些操作。
//你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列, 只要是标准的队列操作即可。
//
//
//
//示例：
//
//输入：
//["MyStack", "push", "push", "top", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 2, 2, false]
//
//解释：
//MyStack myStack = new MyStack();
//myStack.push(1);
//myStack.push(2);
//myStack.top(); // 返回 2
//myStack.pop(); // 返回 2
//myStack.empty(); // 返回 False
//
//
//
//提示：
//
//1 <= x <= 9
//最多调用100 次 push、pop、top 和 empty
//每次调用 pop 和 top 都保证栈不为空
//
//
//
//进阶：你能否仅用一个队列来实现栈。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/implement-stack-using-queues
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
//


typedef int QDataType;

// 链式结构：表示队列 
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;



// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int size;
}Queue;



// 初始化队列 
void QueueInit(Queue* q);

// 队尾入队列 
void QueuePush(Queue* q, QDataType data);

// 队头出队列 
void QueuePop(Queue* q);

// 获取队列头部元素 
QDataType QueueFront(Queue* q);

// 获取队列队尾元素 
QDataType QueueBack(Queue* q);

// 获取队列中有效元素个数 
int QueueSize(Queue* q);

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);

// 销毁队列 
void QueueDestroy(Queue* q);


// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->_front = q->_rear = NULL;
	q->size = 0;
}

// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	//申请新元素并初始化
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
	//插入
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

// 队头出队列 
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

// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_front->_data;
}

// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->_rear->_data;
}

// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return q->_front == NULL && q->_rear == NULL;
}

// 销毁队列 
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
