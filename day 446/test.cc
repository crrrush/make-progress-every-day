/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-12 14:16:48
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-12 14:20:44
 * @FilePath: \every-little-progress\day 446\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 052. 递增顺序搜索树
// https://leetcode.cn/problems/NYBBNL/description/
// 给你一棵二叉搜索树，请 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

 

// 示例 1：



// 输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
// 输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
// 示例 2：



// 输入：root = [5,1,7]
// 输出：[1,null,5,null,7]
 

// 提示：

// 树中节点数的取值范围是 [1, 100]
// 0 <= Node.val <= 1000
 

// 注意：本题与主站 897 题相同： https://leetcode-cn.com/problems/increasing-order-search-tree/


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
    void to_list(TreeNode* root, TreeNode*& cur)
    {
        if(root == nullptr) return;

        to_list(root->left, cur);

        cur->right = root;
        root->left = nullptr;
        cur = cur->right;
        
        to_list(root->right, cur);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* head = new TreeNode;
        TreeNode* cur = head;
        to_list(root, cur);
        cur = head->right;
        cur->left = nullptr;
        return cur;
    }
};