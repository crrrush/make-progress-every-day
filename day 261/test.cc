

// 剑指 Offer 24. 反转链表
// https://leetcode.cn/problems/fan-zhuan-lian-biao-lcof/
// 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

// 示例:

// 输入: 1->2->3->4->5->NULL
// 输出: 5->4->3->2->1->NULL
 

// 限制：

// 0 <= 节点个数 <= 5000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* prev = head, *cur = head->next;
        ListNode* newhead = head;
        while(cur != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            if(tmp == nullptr) newhead = cur;
            cur = tmp;
        }
        head->next = nullptr;
        return newhead;
    }
};