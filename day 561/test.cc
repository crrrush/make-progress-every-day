

// 206. 反转链表
// https://leetcode.cn/problems/reverse-linked-list/description/
// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

// 示例 1：


// 输入：head = [1,2,3,4,5]
// 输出：[5,4,3,2,1]
// 示例 2：


// 输入：head = [1,2]
// 输出：[2,1]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目范围是 [0, 5000]
// -5000 <= Node.val <= 5000
 

// 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* _reverseList(ListNode* prev, ListNode* node) {
        if(nullptr == node->next)
        {
            node->next = prev;
            return node;
        }
        
        ListNode* next = node->next;
        node->next = prev;
        return _reverseList(node, next);
    }

    // 递归插入
    void insertR(ListNode* head, ListNode* node)
    {
        ListNode* next = node->next;
        node->next = head->next;
        head->next = node;
        if(next) insertR(head, next);
    }

    ListNode*& dfs(ListNode*& head, ListNode*& node)
    {
        if(nullptr == node->next)
        {
            head = node;
            return node;
        }
        dfs(head, node->next)->next = node;
        node->next = nullptr;
        return node;
    }
public:
    // 写法更新 递归
    ListNode* reverseList(ListNode* head) {
        if(nullptr == head || nullptr == head->next) return head;

        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newhead;
    }

    // ListNode* reverseList(ListNode* head) {
    //     if(nullptr == head) return nullptr;
    //     ListNode* ret = nullptr;
    //     // dfs(ret, head)->next = nullptr;
    //     dfs(ret, head);
    //     return ret;
    // }

    // ListNode* reverseList(ListNode* head) {
    //     if(nullptr == head) return nullptr;
    //     ListNode* newhead = new ListNode;
    //     insertR(newhead, head);

    //     ListNode* tmp = newhead->next;
    //     delete newhead;

    //     return tmp;
    //     // return _reverseList(nullptr, head);
    // }
};
