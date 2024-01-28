/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-28 14:22:03
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-28 14:22:38
 * @FilePath: \every-little-progress\day 431\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 105. 从前序与中序遍历序列构造二叉树
// https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

 

// 示例 1:


// 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// 输出: [3,9,20,null,null,15,7]
// 示例 2:

// 输入: preorder = [-1], inorder = [-1]
// 输出: [-1]
 

// 提示:

// 1 <= preorder.length <= 3000
// inorder.length == preorder.length
// -3000 <= preorder[i], inorder[i] <= 3000
// preorder 和 inorder 均 无重复 元素
// inorder 均出现在 preorder
// preorder 保证 为二叉树的前序遍历序列
// inorder 保证 为二叉树的中序遍历序列


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
    void construct_tree(TreeNode*& root, vector<int>& preorder, int& pos, vector<int>& inorder, int in_begin, int in_end)
    {
        if(in_begin < 0 || in_end > inorder.size() || in_begin >= in_end || pos >= preorder.size()) return;

        root = new TreeNode(preorder[pos]);

        int lend = 0;
        for(int i = in_begin;i < in_end;++i)
        {
            if(inorder[i] == preorder[pos])
            {
                lend = i;
                break;
            }
        }
        

        if(lend > in_begin) construct_tree(root->left, preorder, ++pos, inorder, in_begin, lend);

        if(lend + 1 < in_end) construct_tree(root->right, preorder, ++pos, inorder, lend + 1, in_end);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = nullptr;
        int pos = 0;
        construct_tree(root, preorder, pos, inorder, 0, inorder.size());
        return root;
    }
};