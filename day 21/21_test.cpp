#define _CRT_SECURE_NO_WARNINGS

//138. ���ƴ����ָ�������
//
//����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ����ָ�����ָ�������е��κνڵ��սڵ㡣
//������������ ����� ���Ӧ�������� n �� ȫ�� �ڵ���ɣ�����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
//�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬�����������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��
//���磬���ԭ�������� X �� Y �����ڵ㣬���� X.random-- > Y ����ô�ڸ��������ж�Ӧ�������ڵ� x �� y ��ͬ���� x.random-- > y ��
//
//���ظ��������ͷ�ڵ㡣
//
//��һ���� n ���ڵ���ɵ���������ʾ���� / ����е�����ÿ���ڵ���һ��[val, random_index] ��ʾ��
//
//val��һ����ʾ Node.val ��������
//random_index�����ָ��ָ��Ľڵ���������Χ�� 0 �� n - 1���������ָ���κνڵ㣬��Ϊ  null ��
//
//��Ĵ��� ֻ ����ԭ�����ͷ�ڵ� head ��Ϊ���������
//
//
//
//ʾ�� 1��
//
//���룺head = [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//����� [[7, null], [13, 0], [11, 4], [10, 2], [1, 0]]
//
//ʾ�� 2��
//
//���룺head = [[1, 1], [2, 1]]
//����� [[1, 1], [2, 1]]
//
//ʾ�� 3��
//
//���룺head = [[3, null], [3, 0], [3, null]]
//����� [[3, null], [3, 0], [3, null]]
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/copy-list-with-random-pointer
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;
    struct Node* cur = head;
    struct Node* copy = NULL;
    while (cur)
    {
        //���ƽڵ㲢���½ڵ����ýڵ����
        copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = cur->next;
        cur->next = copy;
        copy->val = cur->val;
        copy->random = cur->random;
        //����һ���ڵ�
        cur = cur->next->next;
    }
    for (cur = head; cur; cur = copy->next)
    {
        copy = cur->next;
        if (copy->random)
        {
            copy->random = copy->random->next;
        }
        /*else
        {
            copy->random = NULL;
        }*/
    }
    //��ͷ
    struct Node* newhead = head->next;
    for (cur = head; cur; cur = cur->next)
    {
        copy = cur->next;
        cur->next = copy->next;
        if (copy->next)
        {
            copy->next = copy->next->next;
        }
    }
    return newhead;
}