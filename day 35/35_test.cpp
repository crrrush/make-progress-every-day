#define _CRT_SECURE_NO_WARNINGS

//
//110. ƽ�������
//https://leetcode.cn/problems/balanced-binary-tree/description/
//����һ�����������ж����Ƿ��Ǹ߶�ƽ��Ķ�������
//�����У�һ�ø߶�ƽ�����������Ϊ��
//һ��������ÿ���ڵ� ���������������ĸ߶Ȳ�ľ���ֵ������ 1 ��
//
//ʾ�� 1��
//���룺root = [3, 9, 20, null, null, 15, 7]
//�����true
//
//ʾ�� 2��
//���룺root = [1, 2, 2, 3, 3, null, null, 4, 4]
//�����false
//
//ʾ�� 3��
//���룺root = []
//�����true
//
//��ʾ��
//���еĽڵ����ڷ�Χ[0, 5000] ��
//- 104 <= Node.val <= 104
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 //�߶�
int BinaryTreeHeight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int HeightL = BinaryTreeHeight(root->left);
    int HeightR = BinaryTreeHeight(root->right);


    return 1 + (HeightL > HeightR ? HeightL : HeightR);
}


bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;

    if (abs(BinaryTreeHeight(root->left) - BinaryTreeHeight(root->right)) > 1)
        return false;

    return isBalanced(root->left) && isBalanced(root->right);
}