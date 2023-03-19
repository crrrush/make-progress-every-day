
// 链表中倒数第k个结点

//  输入一个链表，输出该链表中倒数第k个结点。
// 示例1
// 输入

// 1,{1,2,3,4,5}

// 输出

// {5}

/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

/**
 * 
 * @param pListHead ListNode类 
 * @param k int整型 
 * @return ListNode类
 */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k ) {
    // write code here
    if(pListHead == NULL || k == 0)
        return NULL;
    struct ListNode* slow = pListHead,* fast = pListHead;
    int i = k; 
    while(i > 1)
    {
        fast = fast->next;
        i--;
        if(fast == NULL)
            return NULL;
    }
    
    while(fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    
    return slow;
}
