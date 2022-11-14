#define _CRT_SECURE_NO_WARNINGS

//203. �Ƴ�����Ԫ��
//
//����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��
//
//
//
//ʾ�� 1��
//
//���룺head = [1, 2, 6, 3, 4, 5, 6], val = 6
//�����[1, 2, 3, 4, 5]
//
//ʾ�� 2��
//
//���룺head = [], val = 1
//�����[]
//
//ʾ�� 3��
//
//���룺head = [7, 7, 7, 7], val = 7
//�����[]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/remove-linked-list-elements
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* pre = head, * prev = NULL;
    while (pre)
    {
        if (pre->val == val)
        {
            if (pre == head)
            {
                pre = pre->next;
                free(head);
                head = pre;
            }
            else
            {
                pre = pre->next;
                prev->next = pre;
            }
        }
        else
        {
            prev = pre;
            pre = pre->next;
        }
    }
    return head;
}