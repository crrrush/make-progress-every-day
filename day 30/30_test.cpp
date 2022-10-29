#define _CRT_SECURE_NO_WARNINGS

//
//104. ��������������
//
//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
//
//ʾ����
//����������[3, 9, 20, null, null, 15, 7]��
//
//3
/// \
//9  20
/// \
//15   7
//
//�������������� 3 
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/maximum-depth-of-binary-tree
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
    {
        return 0;
    }

    int depthL = maxDepth(root->left);
    int depthR = maxDepth(root->right);

    if (depthL > depthR)
    {
        return 1 + depthL;
    }
    else
    {
        return 1 + depthR;
    }

}