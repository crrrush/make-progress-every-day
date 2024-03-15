/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-15 11:24:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-15 11:25:01
 * @FilePath: \every-little-progress\day 477\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 176. 判断是否为平衡二叉树
// https://leetcode.cn/problems/ping-heng-er-cha-shu-lcof/description/
// 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

 

// 示例 1:

// 输入：root = [3,9,20,null,null,15,7]
// 输出：true 
// 解释：如下图


// 示例 2:

// 输入：root = [1,2,2,3,3,null,null,4,4]
// 输出：false
// 解释：如下图

 

// 提示：

// 0 <= 树的结点个数 <= 10000
// 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/

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
    int depth(TreeNode* root)
    {
        if(nullptr == root) return 0;

        int l = depth(root->left);
        int r = depth(root->right);

        return l > r ? l + 1 : r + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(nullptr == root) return true;

        int l = depth(root->left);
        int r = depth(root->right);

        if(abs(l - r) > 1) return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};
