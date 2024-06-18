/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-18 16:06:09
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-18 16:06:42
 * @FilePath: \every-little-progress\day 566\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 98. 验证二叉搜索树
// https://leetcode.cn/problems/validate-binary-search-tree/description/
// 给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

// 有效 二叉搜索树定义如下：

// 节点的左
// 子树
// 只包含 小于 当前节点的数。
// 节点的右子树只包含 大于 当前节点的数。
// 所有左子树和右子树自身必须也是二叉搜索树。
 

// 示例 1：


// 输入：root = [2,1,3]
// 输出：true
// 示例 2：


// 输入：root = [5,1,4,null,null,3,6]
// 输出：false
// 解释：根节点的值是 5 ，但是右子节点的值是 4 。
 

// 提示：

// 树中节点数目范围在[1, 104] 内
// -231 <= Node.val <= 231 - 1


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
    long prev = LONG_MIN;
public:
    // 中序遍历
    bool isValidBST(TreeNode* root) {
        if(nullptr == root) return true;

        if(!isValidBST(root->left)) return false;

        if(root->val <= prev) return false;
        prev = root->val;

        return isValidBST(root->right);
    }
};


// class Solution {
//     TreeNode* prev = nullptr;
// public:
//     // 中序遍历
//     bool isValidBST(TreeNode* root) {
//         if(nullptr == root) return true;

//         if(!isValidBST(root->left)) return false;

//         if(nullptr != prev && root->val <= prev->val) return false;
//         prev = root;

//         return isValidBST(root->right);
//     }
// };


// class Solution {
//     bool dfs(TreeNode* root, TreeNode* min, TreeNode* max)
//     {
//         if(nullptr == root) return true;

//         if(nullptr != min && root->val <= min->val) return false;
//         if(nullptr != max && root->val >= max->val) return false;

//         return dfs(root->left, min, root) && dfs(root->right, root, max);
//     }
// public:
//     bool isValidBST(TreeNode* root) {
//         return dfs(root, nullptr, nullptr);
//     }
// };


