/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-09-27 10:40:58
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-09-27 10:41:38
 * @FilePath: \every-little-progress\day 310\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 175. 计算二叉树的深度
// https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/description/
// 某公司架构以二叉树形式记录，请返回该公司的层级数。

 

// 示例 1：



// 输入：root = [1, 2, 2, 3, null, null, 5, 4, null, null, 4]
// 输出: 4
// 解释: 上面示例中的二叉树的最大深度是 4，沿着路径 1 -> 2 -> 3 -> 4 或 1 -> 2 -> 5 -> 4 到达叶节点的最长路径上有 4 个节点。
 

// 提示：

// 节点总数 <= 10000
// 注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

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
    int calculateDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = 0, right = 0;
        if(root->left) left = calculateDepth(root->left);
        if(root->right) right = calculateDepth(root->right);

        return left > right ? (1 + left) : (1 + right);
    }
};

// class Solution {
// public:
//     int calculateDepth(TreeNode* root) {
//         if(root == nullptr) return 0;

//         int left = calculateDepth(root->left);
//         int right = calculateDepth(root->right);

//         return left > right ? ++left : ++right;
//     }
// };