

// 707. 设计链表
// https://leetcode.cn/problems/design-linked-list/
// 你可以选择使用单链表或者双链表，设计并实现自己的链表。

// 单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

// 如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

// 实现 MyLinkedList 类：

// MyLinkedList() 初始化 MyLinkedList 对象。
// int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
// void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
// void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
// void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
// void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 

// 示例：

// 输入
// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// 输出
// [null, null, null, null, 2, null, 3]

// 解释
// MyLinkedList myLinkedList = new MyLinkedList();
// myLinkedList.addAtHead(1);
// myLinkedList.addAtTail(3);
// myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
// myLinkedList.get(1);              // 返回 2
// myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
// myLinkedList.get(1);              // 返回 3
 

// 提示：

// 0 <= index, val <= 1000
// 请不要使用内置的 LinkedList 库。
// 调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。

class MyLinkedList {
    struct ListNode
    {
    public:
        ListNode(int val = 0):_prev(nullptr), _next(nullptr), _val(val){}

        ListNode* _prev;
        ListNode* _next;
        int _val;
    };
public:
    MyLinkedList():_head(new ListNode) 
    {
        _head->_next = _head;
        _head->_prev = _head;
    }
    ~MyLinkedList()
    {
        // ListNode* cur = _head->_next;

        // while(cur != _head)
        // {
        //     cur = cur->_next;
        //     delete cur->_prev;
        // }

        // delete _head;
    }

    bool empty() { return _head->_next == _head; }

    void print()
    {
        ListNode* cur = _head->_next;
        while(cur != _head)
        {
            cout<<cur->_val<<" ";
            cur = cur->_next;
        }
        cout<<endl;
    }
    
    int get(int index) {
        ListNode* cur = _head->_next;
        print();

        for(int i = 0;cur != _head;(++i, cur = cur->_next))
        {
            if(i == index)
            {
                return cur->_val;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        if(empty())
        {
            _head->_next = node;
            node->_prev = _head;

            _head->_prev = node;
            node->_next = _head;
        }
        else
        {
            ListNode* nextnode =  _head->_next;

            nextnode->_prev = node;
            node->_next = nextnode;

            _head->_next = node;
            node->_prev = _head;
        }
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        if(empty())
        {
            _head->_next = node;
            node->_prev = _head;

            _head->_prev = node;
            node->_next = _head;
        }
        else
        {
            ListNode* prevnode =  _head->_prev;

            prevnode->_next = node;
            node->_prev = prevnode;

            _head->_prev = node;
            node->_next = _head;
        }
    }
    
    void addAtIndex(int index, int val) {
        ListNode* cur = _head->_next;
        int i = 0;
        for(i = 0;cur != _head;(++i, cur = cur->_next))
        {
            if(i == index)
            {
                ListNode* node = new ListNode(val);

                ListNode* prevnode =  cur->_prev;

                prevnode->_next = node;
                node->_prev = prevnode;

                cur->_prev = node;
                node->_next = cur;

                return;
            }
        }
        if(i == index) addAtTail(val);
    }
    
    void deleteAtIndex(int index) {
        ListNode* cur = _head->_next;
        for(int i = 0;cur != _head;(++i, cur = cur->_next))
        {
            if(i == index)
            {
                ListNode* prevnode =  cur->_prev;
                ListNode* nextnode =  cur->_next;

                prevnode->_next = nextnode;
                nextnode->_prev = prevnode;

                delete cur;
                return;
            }
        }
    }
private:
    ListNode* _head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */