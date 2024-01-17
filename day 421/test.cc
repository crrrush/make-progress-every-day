


// LCR 026. 重排链表
// https://leetcode.cn/problems/LGjMqU/description/
// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

//  L0 → L1 → … → Ln-1 → Ln 
// 请将其重新排列后变为：

// L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

// 示例 1:



// 输入: head = [1,2,3,4]
// 输出: [1,4,2,3]
// 示例 2:



// 输入: head = [1,2,3,4,5]
// 输出: [1,5,2,4,3]
 

// 提示：

// 链表的长度范围为 [1, 5 * 104]
// 1 <= node.val <= 1000
 

// 注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/ 


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
    ListNode* reverselist(ListNode* head)// 不能传空指针
    {
        ListNode* cur = head->next;
        if(cur == nullptr) return head; // 后半段只有一个
        head->next = nullptr;
        ListNode* prev = head;
        ListNode* newhead = nullptr;
        while(cur)
        {
            ListNode* next = cur->next;
            if(next == nullptr) newhead = cur;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return newhead;
    }

    ListNode* find_mid(ListNode* head)
    {
        ListNode* prev = head, *cur = head;
        while(cur && cur->next)
        {
            cur = cur->next->next;
            if(cur == nullptr) return prev;
            prev = prev->next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        ListNode* mid = find_mid(head);
        if(mid == head) return;
        ListNode* sec_half = reverselist(mid->next);
        mid->next = nullptr;

        ListNode* cur1 = head;
        ListNode* cur2 = sec_half;
        while(cur1 && cur2)
        {
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;

            cur1 = next1;
            cur2 = next2;
        }
    }
};


// 空间O(n)
// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         ListNode* cur = head;
//         vector<ListNode*> nodes;
//         while(cur != nullptr)
//         {
//             nodes.push_back(cur);
//             cur = cur->next;
//         }
//         // for(const auto& e : nodes) cout<<e->val<<" ";

//         int left = 0, right = nodes.size() - 1;
//         ListNode* last = nullptr;
//         while(left < right)
//         {
//             if(last) last->next = nodes[left];
//             (nodes[left])->next = nodes[right];
//             last = nodes[right];
//             ++left;
//             --right;
//         }
//         if(left == right && last) last->next = nodes[left];
//         nodes[left]->next = nullptr;
//     }
// };