#define _CRT_SECURE_NO_WARNINGS

//622. 设计循环队列
//
//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//
//你的实现应该支持如下操作：
//
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//isEmpty() : 检查循环队列是否为空。
//isFull() : 检查循环队列是否已满。
//
//
//
//示例：
//
//MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
//circularQueue.enQueue(1);  // 返回 true
//circularQueue.enQueue(2);  // 返回 true
//circularQueue.enQueue(3);  // 返回 true
//circularQueue.enQueue(4);  // 返回 false，队列已满
//circularQueue.Rear();  // 返回 3
//circularQueue.isFull();  // 返回 true
//circularQueue.deQueue();  // 返回 true
//circularQueue.enQueue(4);  // 返回 true
//circularQueue.Rear();  // 返回 4
//
//
//
//提示：
//
//所有的值都在 0 至 1000 的范围内；
//操作数将在 1 至 1000 的范围内；
//请不要使用内置的队列库。
//
//通过次数118, 156
//提交次数247, 611
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/design-circular-queue
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

typedef struct {
    int* circle;
    int front;
    int back;
    int N;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->circle = (int*)malloc((k + 1) * sizeof(int));
    obj->front = obj->back = 0;
    obj->N = k + 1;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->back == obj->front;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->back + 1) % obj->N == obj->front;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;

    obj->circle[obj->back++] = value;
    obj->back %= obj->N;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;

    obj->front++;
    obj->front %= obj->N;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->circle[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;

    return obj->circle[(obj->back - 1 + obj->N) % obj->N];
}


void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->circle);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/
