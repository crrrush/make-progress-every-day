#define _CRT_SECURE_NO_WARNINGS

//142. �������� II
//
//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//
//�������޸� ����
//
//
//
//ʾ�� 1��
//
//���룺head = [3, 2, 0, -4], pos = 1
//�������������Ϊ 1 ������ڵ�
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//ʾ�� 2��
//
//���룺head = [1, 2], pos = 0
//�������������Ϊ 0 ������ڵ�
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//
//ʾ�� 3��
//
//���룺head = [1], pos = -1
//��������� null
//���ͣ�������û�л���
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/linked-list-cycle-ii
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            struct ListNode* meet = slow;
            while (head != meet)
            {
                head = head->next;
                meet = meet->next;
            }
            return head;
        }
    }
    return NULL;
}
