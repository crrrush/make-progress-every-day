#define _CRT_SECURE_NO_WARNINGS

//144. 二叉树的前序遍历
//
//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//
//示例 1：
//
//输入：root = [1, null, 2, 3]
//输出：[1, 2, 3]
//
//示例 2：
//
//输入：root = []
//输出：[]
//
//示例 3：
//
//输入：root = [1]
//输出：[1]
//
//示例 4：
//
//输入：root = [1, 2]
//输出：[1, 2]
//
//示例 5：
//
//输入：root = [1, null, 2]
//输出：[1, 2]
//
//
//
//提示：
//
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//
//
//
//进阶：递归算法很简单，你可以通过迭代算法完成吗？


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

  // 二叉树节点个数
int BinaryTreeSize(struct TreeNode* root)
{
	return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

// 二叉树前序遍历 
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
