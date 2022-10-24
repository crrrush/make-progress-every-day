#define _CRT_SECURE_NO_WARNINGS


//965. ��ֵ������
//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
//
//ʾ�� 1��
//
//���룺[1, 1, 1, 1, 1, null, 1]
//�����true
//
//ʾ�� 2��
//
//���룺[2, 2, 2, 5, 2]
//�����false
//
//
//
//��ʾ��
//
//�������Ľڵ�����Χ��[1, 100]��
//ÿ���ڵ��ֵ������������ΧΪ[0, 99] ��
//
//ͨ������74, 179
//�ύ����103, 601
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/univalued-binary-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root) {
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }

    if (root->left != NULL && root->right == NULL)
    {
        return (root->val == root->left->val) && isUnivalTree(root->left);
    }
    if (root->left == NULL && root->right != NULL)
    {
        return (root->val == root->right->val) && isUnivalTree(root->right);
    }

    return (root->val == root->left->val) && (root->val == root->right->val) && isUnivalTree(root->right) && isUnivalTree(root->left);
}
