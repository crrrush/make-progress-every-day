#define _CRT_SECURE_NO_WARNINGS


//21. 合并两个有序链表
//
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
//示例 1：
//
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]
//
//示例 2：
//
//输入：l1 = [], l2 = []
//输出：[]
//
//示例 3：
//
//输入：l1 = [], l2 = [0]
//输出：[0]
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/merge-two-sorted-lists
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* tail = head;
    struct ListNode* cur1 = list1, * cur2 = list2;
    while (cur1 && cur2)
    {
        if (cur1->val > cur2->val)
        {
            tail->next = cur2;
            cur2 = cur2->next;
        }
        else
        {
            tail->next = cur1;
            cur1 = cur1->next;
        }
        tail = tail->next;
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    if (cur2)
    {
        tail->next = cur2;
    }
    struct ListNode* ret = head->next;
    free(head);
    return ret;
}


