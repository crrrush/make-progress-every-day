#define _CRT_SECURE_NO_WARNINGS


//94. ���������������
//����һ���������ĸ��ڵ� root ������ ���� ���� ���� ��
//
//
//
//ʾ�� 1��
//
//���룺root = [1, null, 2, 3]
//�����[1, 3, 2]
//
//ʾ�� 2��
//
//���룺root = []
//�����[]
//
//ʾ�� 3��
//
//���룺root = [1]
//�����[1]
//
//
//
//��ʾ��
//
//���нڵ���Ŀ�ڷ�Χ[0, 100] ��
//- 100 <= Node.val <= 100
//
//
//
//����: �ݹ��㷨�ܼ򵥣������ͨ�������㷨�����
//
//��Դ�����ۣ�LeetCode��
//���ӣ�https ://leetcode.cn/problems/binary-tree-inorder-traversal
//����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


 /**
  * Note: The returned array must be malloced, assume caller calls free().
  */

  // �������ڵ����
int BinaryTreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// ������ǰ����� 
void BinaryTreeInOrder(struct TreeNode* root, int* arr, int* n)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	BinaryTreeInOrder(root->left, arr, n);
	arr[*n] = root->val;
	(*n)++;
	BinaryTreeInOrder(root->right, arr, n);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = BinaryTreeSize(root);
	int* ret = (int*)malloc(size * sizeof(int));
	*returnSize = 0;
	BinaryTreeInOrder(root, ret, returnSize);
	return ret;
}