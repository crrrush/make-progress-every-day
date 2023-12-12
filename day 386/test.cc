/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-12 16:56:57
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-12 16:58:20
 * @FilePath: \every-little-progress\day 386\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 143. 子结构判断
// https://leetcode.cn/problems/shu-de-zi-jie-gou-lcof/description/
// \给定两棵二叉树 tree1 和 tree2，判断 tree2 是否以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。
// 注意，空树 不会是以 tree1 的某个节点为根的子树具有 相同的结构和节点值 。

 

// 示例 1：


// 输入：tree1 = [1,7,5], tree2 = [6,1]
// 输出：false
// 解释：tree2 与 tree1 的一个子树没有相同的结构和节点值。
// 示例 2：



// 输入：tree1 = [3,6,7,1,8], tree2 = [6,1]
// 输出：true
// 解释：tree2 与 tree1 的一个子树拥有相同的结构和节点值。即 6 - > 1。
 

// 提示：

// 0 <= 节点个数 <= 10000


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
    bool is_similarity(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr || A->val != B->val) return false;
        bool sm = true;
        if(B->left) sm &= is_similarity(A->left, B->left);
        if(B->right) sm &= is_similarity(A->right, B->right);
        return sm;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(A == nullptr || B == nullptr) return false;

        if(A->val == B->val && is_similarity(A, B)) return true;
        if(isSubStructure(A->left, B)) return true;
        if(isSubStructure(A->right, B)) return true;

        return false;
    }
};