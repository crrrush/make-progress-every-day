#define _CRT_SECURE_NO_WARNINGS

//232. 用栈实现队列
//
//请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
//
//实现 MyQueue 类：
//
//void push(int x) 将元素 x 推到队列的末尾
//int pop() 从队列的开头移除并返回元素
//int peek() 返回队列开头的元素
//boolean empty() 如果队列为空，返回 true ；否则，返回 false
//
//说明：
//
//你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek / pop from top, size, 和 is empty 操作是合法的。
//你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
//
//
//
//示例 1：
//
//输入：
//["MyQueue", "push", "push", "peek", "pop", "empty"]
//[[], [1], [2], [], [], []]
//输出：
//[null, null, null, 1, 1, false]
//
//解释：
//MyQueue myQueue = new MyQueue();
//myQueue.push(1); // queue is: [1]
//myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
//myQueue.peek(); // return 1
//myQueue.pop(); // return 1, queue is [2]
//myQueue.empty(); // return false
//
//
//
//提示：
//
//1 <= x <= 9
//最多调用 100 次 push、pop、peek 和 empty
//假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）
//
//
//
//进阶：
//
//你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/implement-queue-using-stacks
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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