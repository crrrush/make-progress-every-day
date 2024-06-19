/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-19 10:23:42
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-19 10:24:10
 * @FilePath: \every-little-progress\day 567\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 230. 二叉搜索树中第K小的元素
// https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/
// 给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。

 

// 示例 1：


// 输入：root = [3,1,4,null,2], k = 1
// 输出：1
// 示例 2：


// 输入：root = [5,3,6,2,4,null,null,1], k = 3
// 输出：3
 

 

// 提示：

// 树中的节点数为 n 。
// 1 <= k <= n <= 104
// 0 <= Node.val <= 104
 

// 进阶：如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化算法？

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
    int cnt;
    int ret;
    // 写法更新 回溯 剪枝
    void find_k(TreeNode* root)
    {
        if(root == nullptr) return;
        find_k(root->left);
        if(0 == cnt) return;
        if(--cnt == 0)
        {
            ret = root->val;
            return;
        }
        return find_k(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        cnt = k;
        find_k(root); 
        return ret;
    }
};

// class Solution {
//     int find_k(TreeNode* root, int& k)
//     {
//         if(root == nullptr) return -1;
//         int r = find_k(root->left, k);
//         if(r != -1) return r;
//         if(--k == 0) return root->val;
//         return find_k(root->right, k);
//     }
// public:
//     int kthSmallest(TreeNode* root, int k) { return find_k(root, k); }
// };


// class Solution {
//     void get_nums(TreeNode* root, vector<int>& nums)
//     {
//         if(root == nullptr) return;
//         get_nums(root->left, nums);
//         nums.push_back(root->val);
//         get_nums(root->right, nums);
//     }
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int> nums;
//         get_nums(root, nums);
//         return nums[k - 1];
//     }
// };
