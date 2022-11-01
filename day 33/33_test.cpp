#define _CRT_SECURE_NO_WARNINGS

//101. �Գƶ�����
//
//����һ���������ĸ��ڵ� root �� ������Ƿ���Գơ�
//
//ʾ�� 1��
//
//���룺root = [1, 2, 2, 3, 4, 4, 3]
//�����true
//
//ʾ�� 2��
//
//���룺root = [1, 2, 2, null, 3, null, 3]
//�����false
//
//
//
//��ʾ��
//
//���нڵ���Ŀ�ڷ�Χ[1, 1000] ��
//- 100 <= Node.val <= 100
//
//
//
//���ף���������õݹ�͵������ַ���������������
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/symmetric-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /*bool Subtree_Symmetry(struct TreeNode* p,struct TreeNode* q)
 {
     if(p->left == NULL && q->right == NULL)
     {
         return true;
     }
     else if(p->left == NULL || q->right==NULL)
     {
         return false;
     }

     return (p->left->val == q->right->val)
             && (p->right->val == q->left->val)
             && Subtree_Symmetry(p->right, q->left)
             && Subtree_Symmetry(p->left, q->right);
 }
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

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL || q == NULL)
    {
        return false;
    }

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSymmetric(struct TreeNode* root) {
    invertTree(root->right);
    return isSameTree(root->left, root->right);
