/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-10 13:32:55
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-10 13:33:37
 * @FilePath: \every-little-progress\day 384\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 04.08. 首个共同祖先
// https://leetcode.cn/problems/first-common-ancestor-lcci/description/
// 设计并实现一个算法，找出二叉树中某两个节点的第一个共同祖先。不得将其他的节点存储在另外的数据结构中。注意：这不一定是二叉搜索树。

// 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4]

//     3
//    / \
//   5   1
//  / \ / \
// 6  2 0  8
//   / \
//  7   4
// 示例 1:

// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 示例 2:

// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出: 5
// 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
// 说明:

// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool find(TreeNode* root, TreeNode* node)
    {
        if(root == nullptr) return false;
        if(root == node) return true;
        return find(root->left, node) || find(root->right, node);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;

        bool lp = find(root->left, p);
        bool rq = find(root->right, q);
        bool rp = find(root->right, p);
        bool lq = find(root->left, q);
        // 1.在两侧，则此节点为首个祖先
        if((lp && rq) || (rp && lq)) return root;
        
        // 2.在一侧，继续找
        if(lp && lq) return lowestCommonAncestor(root->left, p, q);
        else if(rp && rq) return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};