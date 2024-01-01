/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-01 18:05:04
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-01 18:05:35
 * @FilePath: \every-little-progress\day 405\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 024. 反转链表
// https://leetcode.cn/problems/UHnkqh/description/
// 给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。

 

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

 

// 注意：本题与主站 206 题相同： https://leetcode-cn.com/problems/reverse-linked-list/


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
    ListNode* RList(ListNode* cur, ListNode* prev)
    {
        if(cur == nullptr) return prev;
        ListNode* next = cur->next;
        cur->next = prev;
        return RList(next, cur);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return head;
        // 递归 
        ListNode* prev = head;
        ListNode* cur = head->next;
        prev->next = nullptr;
        return RList(cur, prev);
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         if(head == nullptr) return head;
//         // 迭代 
//         ListNode* prev = head;
//         ListNode* cur = head->next;
//         prev->next = nullptr;
//         while(cur != nullptr)
//         {
//             ListNode* tmp = cur->next;
//             cur->next = prev;
//             prev = cur;
//             cur = tmp;
//         }

//         return prev;
//     }
// };