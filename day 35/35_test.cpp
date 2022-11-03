#define _CRT_SECURE_NO_WARNINGS

//
//110. 平衡二叉树
//https://leetcode.cn/problems/balanced-binary-tree/description/
//给定一个二叉树，判断它是否是高度平衡的二叉树。
//本题中，一棵高度平衡二叉树定义为：
//一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
//
//示例 1：
//输入：root = [3, 9, 20, null, null, 15, 7]
//输出：true
//
//示例 2：
//输入：root = [1, 2, 2, 3, 3, null, null, 4, 4]
//输出：false
//
//示例 3：
//输入：root = []
//输出：true
//
//提示：
//树中的节点数在范围[0, 5000] 内
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

 //高度
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