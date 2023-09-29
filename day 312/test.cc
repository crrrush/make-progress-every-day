/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-29 10:30:06
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-29 10:30:52
 * @FilePath: \every-little-progress\day 312\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2236. 判断根结点是否等于子结点之和
// https://leetcode.cn/problems/root-equals-sum-of-children/
// 给你一个 二叉树 的根结点 root，该二叉树由恰好 3 个结点组成：根结点、左子结点和右子结点。

// 如果根结点值等于两个子结点值之和，返回 true ，否则返回 false 。

 

// 示例 1：


// 输入：root = [10,4,6]
// 输出：true
// 解释：根结点、左子结点和右子结点的值分别是 10 、4 和 6 。
// 由于 10 等于 4 + 6 ，因此返回 true 。
// 示例 2：


// 输入：root = [5,3,1]
// 输出：false
// 解释：根结点、左子结点和右子结点的值分别是 5 、3 和 1 。
// 由于 5 不等于 3 + 1 ，因此返回 false 。
 

// 提示：

// 树只包含根结点、左子结点和右子结点
// -100 <= Node.val <= 100


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
    bool checkTree(TreeNode* root) {
        return root->val == (root->right->val + root->left->val);
    }
};