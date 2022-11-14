#define _CRT_SECURE_NO_WARNINGS

//226. ��ת������
//
//����һ�ö������ĸ��ڵ� root ����ת��ö�����������������ڵ㡣
//
//ʾ�� 1��
//
//���룺root = [4, 2, 7, 1, 3, 6, 9]
//�����[4, 7, 2, 9, 6, 3, 1]
//
//ʾ�� 2��
//
//���룺root = [2, 1, 3]
//�����[2, 3, 1]
//
//ʾ�� 3��
//
//���룺root = []
//�����[]
//
//
//
//��ʾ��
//
//���нڵ���Ŀ��Χ��[0, 100] ��
//- 100 <= Node.val <= 100
//
//
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/invert-binary-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return NULL;
    }

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}