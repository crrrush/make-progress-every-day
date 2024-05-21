

// 2. 两数相加
// https://leetcode.cn/problems/add-two-numbers/description/
// 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

// 示例 1：


// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[7,0,8]
// 解释：342 + 465 = 807.
// 示例 2：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
// 示例 3：

// 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// 输出：[8,9,9,9,0,0,0,1]
 

// 提示：

// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* new_head = new ListNode;
        ListNode* tail = new_head;
        int sum = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 || cur2 || sum)
        {
            int tmp = 0;
            if(cur1)
            {
                tmp += cur1->val;
                cur1 = cur1->next;
            }
            if(cur2)
            {
                tmp += cur2->val;
                cur2 = cur2->next;
            }

            sum += tmp;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
            sum /= 10;
        }
        

        return new_head->next;
    }
};



// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* new_head = new ListNode;
//         ListNode* tail = nullptr;
//         int sum = 0;
//         ListNode* cur1 = l1;
//         ListNode* cur2 = l2;
//         while(cur1 != nullptr && cur2 != nullptr)
//         {
//             if(tail == nullptr)
//             {
//                 sum += cur1->val + cur2->val;
//                 new_head->next = new ListNode(sum % 10);
//                 tail = new_head->next;
//             }
//             else
//             {
//                 sum += cur1->val + cur2->val;
//                 tail->next = new ListNode(sum % 10);
//                 tail = tail->next;
//             }

//             sum /= 10;
//             cur1 = cur1->next;
//             cur2 = cur2->next;
//         }
//         while(cur1 != nullptr)
//         {
//             sum += cur1->val;
//             tail->next = new ListNode(sum % 10);
//             tail = tail->next;
//             sum /= 10;
//             cur1 = cur1->next;
//         }
//         while(cur2 != nullptr)
//         {
//             sum += cur2->val;
//             tail->next = new ListNode(sum % 10);
//             tail = tail->next;
//             sum /= 10;
//             cur2 = cur2->next;
//         }
//         if(sum > 0) tail->next = new ListNode(sum % 10);
        

//         return new_head->next;
//     }
// };
