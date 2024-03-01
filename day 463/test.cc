/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-01 14:19:23
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-01 14:20:29
 * @FilePath: \every-little-progress\day 463\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 1457. 二叉树中的伪回文路径
// https://leetcode.cn/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
// 给你一棵二叉树，每个节点的值为 1 到 9 。我们称二叉树中的一条路径是 「伪回文」的，当它满足：路径经过的所有节点值的排列中，存在一个回文序列。

// 请你返回从根到叶子节点的所有路径中 伪回文 路径的数目。

 

// 示例 1：



// 输入：root = [2,3,1,3,1,null,1]
// 输出：2 
// 解释：上图为给定的二叉树。总共有 3 条从根到叶子的路径：红色路径 [2,3,3] ，绿色路径 [2,1,1] 和路径 [2,3,1] 。
//      在这些路径中，只有红色和绿色的路径是伪回文路径，因为红色路径 [2,3,3] 存在回文排列 [3,2,3] ，绿色路径 [2,1,1] 存在回文排列 [1,2,1] 。
// 示例 2：



// 输入：root = [2,1,1,1,3,null,null,null,null,null,1]
// 输出：1 
// 解释：上图为给定二叉树。总共有 3 条从根到叶子的路径：绿色路径 [2,1,1] ，路径 [2,1,3,1] 和路径 [2,1] 。
//      这些路径中只有绿色路径是伪回文路径，因为 [2,1,1] 存在回文排列 [1,2,1] 。
// 示例 3：

// 输入：root = [9]
// 输出：1
 

// 提示：

// 给定二叉树的节点数目在范围 [1, 105] 内
// 1 <= Node.val <= 9


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
    int paths(TreeNode* root, unordered_map<int, int>& hash)
    {
        ++hash[root->val];

        if(root->left && root->right)
        {
            int l = paths(root->left, hash);
            int r = paths(root->right, hash);
            --hash[root->val];
            return l + r;
        }
        else if(root->left)
        {
            int l = paths(root->left, hash);
            --hash[root->val];
            return l;
        }
        else if(root->right)
        {
            int r = paths(root->right, hash);
            --hash[root->val];
            return r;
        }
        else
        {
            size_t singel = 0;
            for(const auto& [x, y] : hash) if(y % 2) ++singel;
            --hash[root->val];
            if(singel > 1) return 0;
            else return 1;
        }

        return 0;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> hash;
        return paths(root, hash);
    }
};