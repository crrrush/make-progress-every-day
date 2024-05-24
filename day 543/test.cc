/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-24 23:36:35
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-24 23:37:10
 * @FilePath: \every-little-progress\day 543\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 25. K 个一组翻转链表
// https://leetcode.cn/problems/reverse-nodes-in-k-group/description/
// 给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

// k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

// 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

 

// 示例 1：


// 输入：head = [1,2,3,4,5], k = 2
// 输出：[2,1,4,3,5]
// 示例 2：



// 输入：head = [1,2,3,4,5], k = 3
// 输出：[3,2,1,4,5]
 

// 提示：
// 链表中的节点数目为 n
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// 进阶：你可以设计一个只用 O(1) 额外内存空间的算法解决此问题吗？

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = k;
        ListNode* newhead = new ListNode;
        ListNode* tail = newhead, *prev = newhead, *cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            if(tail == prev) tail = cur;

            if(0 == --cnt)
            {
                prev = tail;
                cnt = k;
            }
            cur = next;     
        }

        // 处理最后一组
        if(cnt < k)
        {
            cur = prev->next;
            prev->next = nullptr;
            while(cur)
            {
                ListNode* next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
                cur = next;
            }
        }

        cur = newhead->next;
        delete newhead;
        return cur;
    }
};

