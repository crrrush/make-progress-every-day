#define _CRT_SECURE_NO_WARNINGS


//94. 二叉树的中序遍历
//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//
//
//示例 1：
//
//输入：root = [1, null, 2, 3]
//输出：[1, 3, 2]
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
//
//
//提示：
//
//树中节点数目在范围[0, 100] 内
//- 100 <= Node.val <= 100
//
//
//
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/binary-tree-inorder-traversal
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


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