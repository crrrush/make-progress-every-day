/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-08 16:40:48
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-08 16:41:22
 * @FilePath: \every-little-progress\day 382\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 671. 二叉树中第二小的节点
// https://leetcode.cn/problems/second-minimum-node-in-a-binary-tree/description/
// 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或 0。如果一个节点有两个子节点的话，那么该节点的值等于两个子节点中较小的一个。

// 更正式地说，即 root.val = min(root.left.val, root.right.val) 总成立。

// 给出这样的一个二叉树，你需要输出所有节点中的 第二小的值 。

// 如果第二小的值不存在的话，输出 -1 。

 

// 示例 1：


// 输入：root = [2,2,5,null,null,5,7]
// 输出：5
// 解释：最小的值是 2 ，第二小的值是 5 。
// 示例 2：


// 输入：root = [2,2,2]
// 输出：-1
// 解释：最小的值是 2, 但是不存在第二小的值。
 

// 提示：

// 树中节点数目在范围 [1, 25] 内
// 1 <= Node.val <= 231 - 1
// 对于树中每个节点 root.val == min(root.left.val, root.right.val)

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
    int findSecondMinimumValue(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr) return -1;
        if(root->left->val == root->right->val)
        {
            int left = findSecondMinimumValue(root->left);
            int right = findSecondMinimumValue(root->right);
            if(right == -1 && left == -1) return -1;
            if(left == -1) return right;
            if(right == -1) return left;
            return left < right ? left : right;
        }
        if(root->left->val == root->val)
        {
            int left = findSecondMinimumValue(root->left);
            if(left != -1) return left < root->right->val ? left : root->right->val;
            return root->right->val;
        }
        else
        {
            int right = findSecondMinimumValue(root->right);
            if(right != -1) return right < root->left->val ? right : root->left->val;
            return root->left->val;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findSecondMinimumValue(TreeNode* root) {
//         if(root->left == nullptr && root->right == nullptr) return -1;
//         if(root->left->val == root->right->val)
//         {
//             int left = findSecondMinimumValue(root->left);
//             int right = findSecondMinimumValue(root->right);
//             if(right == -1 && left == -1) return -1;
//             if(left == -1) return right;
//             if(right == -1) return left;
//             return left < right ? right : left;
//         }
//         if(root->left->val == root->val)
//         {
//             int left = findSecondMinimumValue(root->left);
//             if(left != -1) return left < root->right->val ? left : root->right->val;
//         }
//         else
//         {
//             int right = findSecondMinimumValue(root->right);
//             if(right != -1) return right < root->left->val ? right : root->left->val;
//         }
//         return root->left->val < root->right->val ? root->right->val : root->left->val;
//     }
// };