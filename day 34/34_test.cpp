#define _CRT_SECURE_NO_WARNINGS


//
//572. 另一棵树的子树
//简单
//842
//相关企业
//
//给你两棵二叉树 root 和 subRoot 。检验 root 中是否包含和 subRoot 具有相同结构和节点值的子树。如果存在，返回 true ；否则，返回 false 。
//
//二叉树 tree 的一棵子树包括 tree 的某个节点和这个节点的所有后代节点。tree 也可以看做它自身的一棵子树。
//
//
//
//示例 1：
//
//输入：root = [3, 4, 5, 1, 2], subRoot = [4, 1, 2]
//输出：true
//
//示例 2：
//
//输入：root = [3, 4, 5, 1, 2, null, null, null, null, 0], subRoot = [4, 1, 2]
//输出：false
//
//
//
//提示：
//
//root 树上的节点数量范围是[1, 2000]
//subRoot 树上的节点数量范围是[1, 1000]
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