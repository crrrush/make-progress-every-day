#define _CRT_SECURE_NO_WARNINGS

//144. ��������ǰ�����
//
//����������ĸ��ڵ� root ���������ڵ�ֵ�� ǰ�� ������
//
//ʾ�� 1��
//
//���룺root = [1, null, 2, 3]
//�����[1, 2, 3]
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
//ʾ�� 4��
//
//���룺root = [1, 2]
//�����[1, 2]
//
//ʾ�� 5��
//
//���룺root = [1, null, 2]
//�����[1, 2]
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
//���ף��ݹ��㷨�ܼ򵥣������ͨ�������㷨�����


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
void BinaryTreePrevOrder(struct TreeNode* root, int* arr, int* n)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	arr[*n] = root->val;
	(*n)++;
	BinaryTreePrevOrder(root->left, arr, n);
	BinaryTreePrevOrder(root->right, arr, n);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int size = BinaryTreeSize(root);
	int* ret = (int*)malloc(size * sizeof(int));
	*returnSize = 0;
	BinaryTreePrevOrder(root, ret, returnSize);
	return ret;
}
