#define _CRT_SECURE_NO_WARNINGS

//141. ��������
//
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
//
//��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
//
//
//
//ʾ�� 1��
//
//���룺head = [3, 2, 0, -4], pos = 1
//�����true
//���ͣ���������һ��������β�����ӵ��ڶ����ڵ㡣
//
//ʾ�� 2��
//
//���룺head = [1, 2], pos = 0
//�����true
//���ͣ���������һ��������β�����ӵ���һ���ڵ㡣
//
//ʾ�� 3��
//
//���룺head = [1], pos = -1
//�����false
//���ͣ�������û�л���
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/linked-list-cycle
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return true;
    }
    return false;
}