

// 143. 重排链表
// https://leetcode.cn/problems/reorder-list/description/
// 给定一个单链表 L 的头节点 head ，单链表 L 表示为：

// L0 → L1 → … → Ln - 1 → Ln
// 请将其重新排列后变为：

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

// 示例 1：



// 输入：head = [1,2,3,4]
// 输出：[1,4,2,3]
// 示例 2：



// 输入：head = [1,2,3,4,5]
// 输出：[1,5,2,4,3]
 

// 提示：

// 链表的长度范围为 [1, 5 * 104]
// 1 <= node.val <= 1000


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
public:
    void reorderList(ListNode* head) {
        ListNode* l1 = new ListNode(0, head);
        ListNode* l2 = new ListNode;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast)
        {
            fast = fast->next;
            if(fast)
                slow = slow->next;
            else
                break;

            fast = fast->next;
        }

        fast = slow->next;
        while(fast)
        {
            ListNode* next = fast->next;
            fast->next = l2->next;
            l2->next = fast;
            fast = next;
        }
        slow->next = nullptr;

        ListNode* cur1 = l1->next;
        ListNode* cur2 = l2->next;
        while(cur1 && cur2)
        {
            ListNode* next1 = cur1->next;
            ListNode* next2 = cur2->next;
            cur1->next = cur2;
            cur2->next = next1;

            cur1 = next1;
            cur2 = next2;
        }

        delete l1;
        delete l2;
    }
};


// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         vector<ListNode*> vlist;
//         ListNode* cur = head;
//         while(cur)
//         {
//             vlist.push_back(cur);
//             cur = cur->next;
//         }

//         int left = 0, right = vlist.size() - 1;
//         while(left < right)
//         {
//             vlist[left]->next = vlist[right];
//             vlist[right]->next = vlist[left + 1];

//             ++left;
//             --right;
//         }
//         vlist[left]->next = nullptr;
//     }
// };

