#define _CRT_SECURE_NO_WARNINGS


//206. ��ת����

//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������
//
//
//
//ʾ�� 1��
//
//���룺head = [1, 2, 3, 4, 5]
//�����[5, 4, 3, 2, 1]
//
//ʾ�� 2��
//
//���룺head = [1, 2]
//�����[2, 1]
//
//ʾ�� 3��
//
//���룺head = []
//�����[]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/reverse-linked-list
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 /*
 struct ListNode* rev = head,*rev_next = NULL,*rev_work = head;
     while(rev_work->next->next)
     {
         rev_work = rev_work->next;
     }
     rev = rev_work->next;
     rev->next = rev_work;

     rev_next = rev_work;
     rev_work->next = head;
     while(rev_work->next != rev_next)
     {
         rev_work = rev_work->next;
         if(rev_work->next == rev_next)
         {
             rev_next->next = rev_work;
             rev_work = head;
             rev_next = rev_next->next;
         }
     }
     head->next = NULL;
     return rev;
 */

struct ListNode* reverseList(struct ListNode* head) {
    /*
     if(head == NULL || head->next ==NULL)
    {
        return head;
    }
    struct ListNode* rev = head,* work = head;
    while(work->next->next)
    {
        work = work->next;
    }
    struct ListNode* ret = rev = work->next;
    rev->next = work;
    while(rev->next != head)
    {
        rev = rev->next;
        work = head;
        while(work->next != rev)
        {
            work = work->next;
        }
        rev->next = work;
    }
    head->next = NULL;
    return ret;
    */
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* newhead = NULL, * cur = head, * next = head->next;
    while (next)
    {
        cur->next = newhead;
        newhead = cur;
        cur = next;
        next = next->next;
    }
    cur->next = newhead;
    newhead = cur;
    return newhead;
}