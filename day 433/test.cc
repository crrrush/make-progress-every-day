/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-30 13:44:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-30 13:55:31
 * @FilePath: \every-little-progress\day 433\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 106. 从中序与后序遍历序列构造二叉树
// https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

// 给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

 

// 示例 1:


// 输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
// 输出：[3,9,20,null,null,15,7]
// 示例 2:

// 输入：inorder = [-1], postorder = [-1]
// 输出：[-1]
 

// 提示:

// 1 <= inorder.length <= 3000
// postorder.length == inorder.length
// -3000 <= inorder[i], postorder[i] <= 3000
// inorder 和 postorder 都由 不同 的值组成
// postorder 中每一个值都在 inorder 中
// inorder 保证是树的中序遍历
// postorder 保证是树的后序遍历

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
    void construct_tree(TreeNode*& root, vector<int>& inorder, int in_begin, int in_end, vector<int>& postorder, int& pos)
    {
        if(in_begin < 0 || in_end > inorder.size() || in_begin >= in_end || pos >= postorder.size()) return;
        root = new TreeNode(postorder[pos]);

        int end = 0;
        for(int i = in_begin;i < in_end;++i)
        {
            if(inorder[i] == postorder[pos])
            {
                end = i;
                break;
            }
        }

        if(end + 1 < in_end) construct_tree(root->right, inorder, end + 1, in_end, postorder, --pos);

        if(in_begin < end) construct_tree(root->left, inorder, in_begin, end, postorder, --pos);

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode* root = nullptr;
        int pos = postorder.size() - 1;
        construct_tree(root, inorder, 0, inorder.size(), postorder, pos);
        return root;
    }
};