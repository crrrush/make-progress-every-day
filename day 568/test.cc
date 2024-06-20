/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-20 19:43:03
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-20 19:43:32
 * @FilePath: \every-little-progress\day 568\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 257. 二叉树的所有路径
// https://leetcode.cn/problems/binary-tree-paths/description/
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。

 
// 示例 1：


// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]
// 示例 2：

// 输入：root = [1]
// 输出：["1"]
 

// 提示：

// 树中节点的数目在范围 [1, 100] 内
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
    vector<string> vs;

    void binaryTreePaths_(TreeNode* root, string s)
    {
        s += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr) return vs.push_back(s);

        s += "->";
        if(root->left) binaryTreePaths_(root->left, s);
        if(root->right) binaryTreePaths_(root->right, s);
    }
public:
    // 更新
    // 全局变量
    // 回溯 恢复现场
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s;
        binaryTreePaths_(root, s);

        return vs;
    }
};

