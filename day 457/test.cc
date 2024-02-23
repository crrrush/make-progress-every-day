/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-23 11:31:57
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-23 11:32:27
 * @FilePath: \every-little-progress\day 457\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2265. 统计值等于子树平均值的节点数
// https://leetcode.cn/problems/count-nodes-equal-to-average-of-subtree/description/
// 给你一棵二叉树的根节点 root ，找出并返回满足要求的节点数，要求节点的值等于其 子树 中值的 平均值 。

// 注意：

// n 个元素的平均值可以由 n 个元素 求和 然后再除以 n ，并 向下舍入 到最近的整数。
// root 的 子树 由 root 和它的所有后代组成。
 

// 示例 1：


// 输入：root = [4,8,5,0,1,null,6]
// 输出：5
// 解释：
// 对值为 4 的节点：子树的平均值 (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4 。
// 对值为 5 的节点：子树的平均值 (5 + 6) / 2 = 11 / 2 = 5 。
// 对值为 0 的节点：子树的平均值 0 / 1 = 0 。
// 对值为 1 的节点：子树的平均值 1 / 1 = 1 。
// 对值为 6 的节点：子树的平均值 6 / 1 = 6 。
// 示例 2：


// 输入：root = [1]
// 输出：1
// 解释：对值为 1 的节点：子树的平均值 1 / 1 = 1。
 

// 提示：

// 树中节点数目在范围 [1, 1000] 内
// 0 <= Node.val <= 1000


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
    int _avg(TreeNode* root, int& n, int& sum)
    {
        if(root == nullptr) return 0;

        int ln = 0;
        int lsum = 0;
        int lnode = _avg(root->left, ln, lsum);

        int rn = 0;
        int rsum = 0;
        int rnode = _avg(root->right, rn, rsum);

        n = ln + rn + 1;
        sum = lsum + rsum + root->val;

        if(root->val == (sum / n)) return 1 + lnode + rnode;
        else return lnode + rnode;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int n = 0;
        int sum = 0;
        return _avg(root, n, sum);
    }
};