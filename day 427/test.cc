/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-24 12:15:24
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-24 12:16:34
 * @FilePath: \every-little-progress\day 427\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1302. 层数最深叶子节点的和
// https://leetcode.cn/problems/deepest-leaves-sum/description/
// 给你一棵二叉树的根节点 root ，请你返回 层数最深的叶子节点的和 。

 

// 示例 1：



// 输入：root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// 输出：15
// 示例 2：

// 输入：root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// 输出：19
 

// 提示：

// 树中节点数目在范围 [1, 104] 之间。
// 1 <= Node.val <= 100

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
    int deepestLeavesSum(TreeNode* root) {
        // 层序遍历
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> tier;
        int sum = 0;
        while(!q.empty())
        {
            while(!q.empty())
            {
                tier.push_back(q.front());
                q.pop();
            }

            for(const auto& e : tier)
            {
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }

            if(q.empty()) for(const auto& e : tier) sum += e->val;

            tier.clear();
        }

        return sum;
    }
};