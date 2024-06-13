/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-13 11:10:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-13 11:13:36
 * @FilePath: \every-little-progress\day 562\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 24. 两两交换链表中的节点
// https://leetcode.cn/problems/swap-nodes-in-pairs/description/
// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

 

// 示例 1：


// 输入：head = [1,2,3,4]
// 输出：[2,1,4,3]
// 示例 2：

// 输入：head = []
// 输出：[]
// 示例 3：

// 输入：head = [1]
// 输出：[1]
 

// 提示：

// 链表中节点的数目在范围 [0, 100] 内
// 0 <= Node.val <= 100


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
    // 写法更新 递归
    ListNode* swapPairs(ListNode* head) {
        if(nullptr == head || nullptr == head->next) return head;

        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;

        return next;
    }
};

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* newhead = new ListNode;
//         ListNode* tail = newhead;

//         ListNode* cur = head;
//         while(cur)
//         {
//             tail->next = cur; // 尾插
//             ListNode* tmp = cur;

//             cur = cur->next;
//             if(cur)
//             {
//                 tmp->next = cur->next;
//                 cur->next = tmp;
//                 tail->next = cur;
//                 cur = tmp->next;
//                 tail = tmp;
//             }
//         }

//         return newhead->next;
//     }
// };

