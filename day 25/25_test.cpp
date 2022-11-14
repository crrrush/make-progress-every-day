#define _CRT_SECURE_NO_WARNINGS

//622. ���ѭ������
//
//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ����������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ���ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//
//���ʵ��Ӧ��֧�����²�����
//
//MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//isFull() : ���ѭ�������Ƿ�������
//
//
//
//ʾ����
//
//MyCircularQueue circularQueue = new MyCircularQueue(3); // ���ó���Ϊ 3
//circularQueue.enQueue(1);  // ���� true
//circularQueue.enQueue(2);  // ���� true
//circularQueue.enQueue(3);  // ���� true
//circularQueue.enQueue(4);  // ���� false����������
//circularQueue.Rear();  // ���� 3
//circularQueue.isFull();  // ���� true
//circularQueue.deQueue();  // ���� true
//circularQueue.enQueue(4);  // ���� true
//circularQueue.Rear();  // ���� 4
//
//
//
//��ʾ��
//
//���е�ֵ���� 0 �� 1000 �ķ�Χ�ڣ�
//���������� 1 �� 1000 �ķ�Χ�ڣ�
//�벻Ҫʹ�����õĶ��п⡣
//
//ͨ������118, 156
//�ύ����247, 611
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/design-circular-queue
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

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
