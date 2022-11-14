#define _CRT_SECURE_NO_WARNINGS

//101. 对称二叉树
//
//给你一个二叉树的根节点 root ， 检查它是否轴对称。
//
//示例 1：
//
//输入：root = [1, 2, 2, 3, 4, 4, 3]
//输出：true
//
//示例 2：
//
//输入：root = [1, 2, 2, null, 3, null, 3]
//输出：false
//
//
//
//提示：
//
//树中节点数目在范围[1, 1000] 内
//- 100 <= Node.val <= 100
//
//
//
//进阶：你可以运用递归和迭代两种方法解决这个问题吗？
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/symmetric-tree
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

 /*bool Subtree_Symmetry(struct TreeNode* p,struct TreeNode* q)
 {
     if(p->left == NULL && q->right == NULL)
     {
         return true;
     }
     else if(p->left == NULL || q->right==NULL)
     {
         return false;
     }

     return (p->left->val == q->right->val)
             && (p->right->val == q->left->val)
             && Subtree_Symmetry(p->right, q->left)
             && Subtree_Symmetry(p->left, q->right);
 }
 */

struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL)
    {
        return NULL;
    }

    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

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

bool isSymmetric(struct TreeNode* root) {
    invertTree(root->right);
    return isSameTree(root->left, root->right);
