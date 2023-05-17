
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

//     每个链表中的节点数在范围 [1, 100] 内
//     0 <= Node.val <= 9
//     题目数据保证列表表示的数字不含前导零



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
    ListNode* addTwoNumbers_(const int& n1, const int& n2, int& carry)
    {
        //求和
        int sum = n1 + n2 + carry;

        //进位
        if(sum >= 10)
        {
            sum -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        return new ListNode(sum);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode();
        ListNode* cur = nullptr;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            //连接
            if(cur == nullptr)
            {
                cur = addTwoNumbers_(l1->val, l2->val, carry);
                head->next = cur;
            }
            else
            {
                cur->next = addTwoNumbers_(l1->val, l2->val, carry);
                cur = cur->next;
            }

            //迭代
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            cur->next = addTwoNumbers_(l1->val, 0, carry);
            cur = cur->next;

            l1 = l1->next;
        }
        while(l2)
        {
            cur->next = addTwoNumbers_(0, l2->val, carry);
            cur = cur->next;

            l2 = l2->next;
        }

        if(carry) cur->next = new ListNode(carry);

        return head->next;
    }
};


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* head = new ListNode();
//         ListNode* cur = nullptr;
//         int carry = 0;
//         while(l1 != nullptr && l2 != nullptr)
//         {
//             //求和
//             int sum = l1->val + l2->val + carry;

//             //进位
//             if(sum >= 10)
//             {
//                 sum -= 10;
//                 carry = 1;
//             }
//             else
//             {
//                 carry = 0;
//             }

//             //连接
//             if(cur == nullptr)
//             {
//                 cur = new ListNode(sum);
//                 head->next = cur;
//             }
//             else
//             {
//                 ListNode* tmp = new ListNode(sum);
//                 cur->next = tmp;
//                 cur = tmp;
//             }

//             //迭代
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         while(l1)
//         {
//             int sum = l1->val + carry;
            
//             if(sum >= 10)
//             {
//                 sum -= 10;
//                 carry = 1;
//             }
//             else carry = 0;

//             cur->next = new ListNode(sum);
//             cur = cur->next;

//             l1 = l1->next;
//         }
//         while(l2)
//         {
//             int sum = l2->val + carry;
            
//             if(sum >= 10)
//             {
//                 sum -= 10;
//                 carry = 1;
//             }
//             else carry = 0;

//             cur->next = new ListNode(sum);
//             cur = cur->next;

//             l2 = l2->next;
//         }

//         if(carry) cur->next = new ListNode(carry);

//         return head->next;
//     }
// };