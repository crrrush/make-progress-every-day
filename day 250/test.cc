


// 938. 二叉搜索树的范围和
// https://leetcode.cn/problems/range-sum-of-bst/description/
// 给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。

 

// 示例 1：


// 输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
// 输出：32
// 示例 2：


// 输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
// 输出：23
 

// 提示：

// 树中节点数目在范围 [1, 2 * 104] 内
// 1 <= Node.val <= 105
// 1 <= low <= high <= 105
// 所有 Node.val 互不相同


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
    // int find(TreeNode* root, int low, int high)
    // {
    //     if(root == nullptr) return 0;

    //     int ret = 0;
    //     if(root->val >= low && root->val <= high) ret = root->val;

    //     return find(root->left, low, high) + find(root->right, low, high) + ret;
    // }

    int find(TreeNode* root, int low, int high)
    {
        if(root == nullptr) return 0;

        int ret = root->val;
        if(ret < low)
            return find(root->right, low, high);
        else if(ret > high)
            return find(root->left, low, high);
        else if(ret == low)
            return find(root->right, low, high) + ret;
        else if(ret == high)
            return find(root->left, low, high) + ret;
        else
            return find(root->left, low, high) + find(root->right, low, high) + ret;

        
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return find(root, low, high);
    }
};