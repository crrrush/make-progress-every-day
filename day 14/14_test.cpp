#define _CRT_SECURE_NO_WARNINGS


//21. �ϲ�������������
//
//��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
//
//
//
//ʾ�� 1��
//
//���룺l1 = [1, 2, 4], l2 = [1, 3, 4]
//�����[1, 1, 2, 3, 4, 4]
//
//ʾ�� 2��
//
//���룺l1 = [], l2 = []
//�����[]
//
//ʾ�� 3��
//
//���룺l1 = [], l2 = [0]
//�����[0]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/merge-two-sorted-lists
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������



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


