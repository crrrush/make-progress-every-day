

// 111. 二叉树的最小深度
// https://leetcode.cn/problems/minimum-depth-of-binary-tree/
// 给定一个二叉树，找出其最小深度。

// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

// 说明：叶子节点是指没有子节点的节点。

 

// 示例 1：

// 输入：root = [3,9,20,null,null,15,7]
// 输出：2

// 示例 2：

// 输入：root = [2,null,3,null,4,null,5,null,6]
// 输出：5

 

// 提示：

//     树中节点数的范围在 [0, 105] 内
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
    int minDepth_(TreeNode* root)
    {
        if(root == nullptr)
            return 0;
        

        int depthL = 0;
        int depthR = 0;
        depthL = minDepth_(root->left);
        depthR = minDepth_(root->right);

        if(!root->left && root->right) return depthR + 1; 
        if(root->left && !root->right) return depthL + 1; 

        if(depthL < depthR) return depthL + 1;
        else                return depthR + 1;
    }
public:
    int minDepth(TreeNode* root) {
        return minDepth_(root);
    }
};