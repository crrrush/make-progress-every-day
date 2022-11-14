#define _CRT_SECURE_NO_WARNINGS

//160. �ཻ����
//
//
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
//
//ͼʾ���������ڽڵ� c1 ��ʼ�ཻ��
//
//��Ŀ���� ��֤ ������ʽ�ṹ�в����ڻ���
//
//ע�⣬�������ؽ����������� ������ԭʼ�ṹ ��
//
//�Զ������⣺
//
//����ϵͳ ���������£�����Ƶĳ��� ������ �����룩��
//
//intersectVal - �ཻ����ʼ�ڵ��ֵ������������ཻ�ڵ㣬��һֵΪ 0
//listA - ��һ������
//listB - �ڶ�������
//skipA - �� listA �У���ͷ�ڵ㿪ʼ����������ڵ�Ľڵ���
//skipB - �� listB �У���ͷ�ڵ㿪ʼ����������ڵ�Ľڵ���
//
//����ϵͳ��������Щ���봴����ʽ���ݽṹ����������ͷ�ڵ� headA �� headB ���ݸ���ĳ�����������ܹ���ȷ�����ཻ�ڵ㣬��ô��Ľ���������� ������ȷ�� ��
//
//
//
//ʾ�� 1��
//
//���룺intersectVal = 8, listA = [4, 1, 8, 4, 5], listB = [5, 6, 1, 8, 4, 5], skipA = 2, skipB = 3
//�����Intersected at '8'
//���ͣ��ཻ�ڵ��ֵΪ 8 ��ע�⣬������������ཻ����Ϊ 0����
//�Ӹ��Եı�ͷ��ʼ�������� A Ϊ[4, 1, 8, 4, 5]������ B Ϊ[5, 6, 1, 8, 4, 5]��
//�� A �У��ཻ�ڵ�ǰ�� 2 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 3 ���ڵ㡣
//�� ��ע���ཻ�ڵ��ֵ��Ϊ 1����Ϊ������ A ������ B ֮��ֵΪ 1 �Ľڵ�(A �еڶ����ڵ�� B �е������ڵ�) �ǲ�ͬ�Ľڵ㡣���仰˵���������ڴ���ָ��������ͬ��λ�ã������� A ������ B ��ֵΪ 8 �Ľڵ�(A �е������ڵ㣬B �е��ĸ��ڵ�) ���ڴ���ָ����ͬ��λ�á�
//
//
//
//ʾ�� 2��
//
//���룺intersectVal = 2, listA = [1, 9, 1, 2, 4], listB = [3, 2, 4], skipA = 3, skipB = 1
//�����Intersected at '2'
//���ͣ��ཻ�ڵ��ֵΪ 2 ��ע�⣬������������ཻ����Ϊ 0����
//�Ӹ��Եı�ͷ��ʼ�������� A Ϊ[1, 9, 1, 2, 4]������ B Ϊ[3, 2, 4]��
//�� A �У��ཻ�ڵ�ǰ�� 3 ���ڵ㣻�� B �У��ཻ�ڵ�ǰ�� 1 ���ڵ㡣
//
//ʾ�� 3��
//
//���룺intersectVal = 0, listA = [2, 6, 4], listB = [1, 5], skipA = 3, skipB = 2
//�����null
//���ͣ��Ӹ��Եı�ͷ��ʼ�������� A Ϊ[2, 6, 4]������ B Ϊ[1, 5]��
//���������������ཻ������ intersectVal ����Ϊ 0���� skipA �� skipB ����������ֵ��
//�����������ཻ����˷��� null ��
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/intersection-of-two-linked-lists
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* La = headA, * Lb = headB;
    int lena = 0, lenb = 0;
    while (La)
    {
        lena++;
        La = La->next;
    }
    while (Lb)
    {
        lenb++;
        Lb = Lb->next;
    }
    struct ListNode* longList = headA, * shortList = headB;
    if (lenb > lena)
    {
        longList = headB;
        shortList = headA;
    }
    int forwardstep = abs(lena - lenb);
    while (forwardstep--)
    {
        longList = longList->next;
    }
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return shortList;
}

