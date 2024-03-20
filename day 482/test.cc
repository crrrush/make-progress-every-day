/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-20 17:01:05
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-20 17:01:35
 * @FilePath: \every-little-progress\day 482\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 056. 两数之和 IV - 输入二叉搜索树
// https://leetcode.cn/problems/opLdQZ/description/
// 给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k 。假设二叉搜索树中节点的值均唯一。

 

// 示例 1：

// 输入: root = [8,6,10,5,7,9,11], k = 12
// 输出: true
// 解释: 节点 5 和节点 7 之和等于 12
// 示例 2：

// 输入: root = [8,6,10,5,7,9,11], k = 22
// 输出: false
// 解释: 不存在两个节点值之和为 22 的节点
 

// 提示：

// 二叉树的节点个数的范围是  [1, 104].
// -104 <= Node.val <= 104
// root 为二叉搜索树
// -105 <= k <= 105
 

// 注意：本题与主站 653 题相同： https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

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
    TreeNode* _root = nullptr;

    bool find(TreeNode* root, const int& n, TreeNode*& self)
    {
        if(nullptr == root) return false;

        if(n < root->val) return find(root->left, n, self);
        else if(n > root->val) return find(root->right, n, self);
        else if(self != root && n == root->val) return true;

        return false;
    }

    bool sum_find(TreeNode* root, const int& k)
    {
        if(nullptr == root) return false;

        // cout<<root->val<<" ";
        if(find(_root, k - (root->val), root)) return true;

        return sum_find(root->left, k) || sum_find(root->right, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        if(nullptr == root) return false;

        _root = root;

        return sum_find(root, k);
    }
};
