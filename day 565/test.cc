/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-17 14:12:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-17 14:13:44
 * @FilePath: \every-little-progress\day 565\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 814. 二叉树剪枝
// https://leetcode.cn/problems/binary-tree-pruning/description/
// 给你二叉树的根结点 root ，此外树的每个结点的值要么是 0 ，要么是 1 。

// 返回移除了所有不包含 1 的子树的原二叉树。

// 节点 node 的子树为 node 本身加上所有 node 的后代。

 

// 示例 1：


// 输入：root = [1,null,0,0,1]
// 输出：[1,null,0,null,1]
// 解释：
// 只有红色节点满足条件“所有不包含 1 的子树”。 右图为返回的答案。
// 示例 2：


// 输入：root = [1,0,1,0,0,0,1]
// 输出：[1,null,1,null,1]
// 示例 3：


// 输入：root = [1,1,0,1,1,0,1,0]
// 输出：[1,1,0,1,1,null,1]
 

// 提示：

// 树中节点的数目在范围 [1, 200] 内
// Node.val 为 0 或 1


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
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(nullptr == root) return root;

        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        if(1 == root->val) return root;

        // return (nullptr == root->left && nullptr == root->right) ? nullptr : root;
        if(nullptr == root->left && nullptr == root->right)
        {
            // delete root; // 防止内存泄漏
            root = nullptr;
        }
        return root;
    }
};

