#define _CRT_SECURE_NO_WARNINGS


//
//572. ��һ����������
//��
//842
//�����ҵ
//
//�������ö����� root �� subRoot ������ root ���Ƿ������ subRoot ������ͬ�ṹ�ͽڵ�ֵ��������������ڣ����� true �����򣬷��� false ��
//
//������ tree ��һ���������� tree ��ĳ���ڵ������ڵ�����к���ڵ㡣tree Ҳ���Կ����������һ��������
//
//
//
//ʾ�� 1��
//
//���룺root = [3, 4, 5, 1, 2], subRoot = [4, 1, 2]
//�����true
//
//ʾ�� 2��
//
//���룺root = [3, 4, 5, 1, 2, null, null, null, null, 0], subRoot = [4, 1, 2]
//�����false
//
//
//
//��ʾ��
//
//root ���ϵĽڵ�������Χ��[1, 2000]
//subRoot ���ϵĽڵ�������Χ��[1, 1000]
//- 104 <= root.val <= 104
//- 104 <= subRoot.val <= 104
//
//https://leetcode.cn/problems/subtree-of-another-tree/description/
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

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


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL)
        return false;

    if (isSameTree(root, subRoot))
        return true;

    return  isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}