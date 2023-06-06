


// 404. 左叶子之和
// https://leetcode.cn/problems/sum-of-left-leaves/

// 给定二叉树的根节点 root ，返回所有左叶子之和。

 

// 示例 1：

// 输入: root = [3,9,20,null,null,15,7] 
// 输出: 24 
// 解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24

// 示例 2:

// 输入: root = [1]
// 输出: 0

 

// 提示:

//     节点数在 [1, 1000] 范围内
//     -1000 <= Node.val <= 1000


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isLeaves(TreeNode* node) {return (node->left == nullptr) && (node->right == nullptr);}
    int sumOfLeftLeaves_(TreeNode* root)
    {
        if(root == nullptr) return 0;

        int num = 0; 
        if(root->left && isLeaves(root->left)) num = root->left->val;

        return num + sumOfLeftLeaves_(root->left) + sumOfLeftLeaves_(root->right);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves_(root);
    }
};