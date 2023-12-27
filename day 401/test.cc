/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-27 18:43:07
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-27 18:43:33
 * @FilePath: \every-little-progress\day 401\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 199. 二叉树的右视图
// https://leetcode.cn/problems/binary-tree-right-side-view/description/
// 给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

 

// 示例 1:



// 输入: [1,2,3,null,5,null,4]
// 输出: [1,3,4]
// 示例 2:

// 输入: [1,null,3]
// 输出: [1,3]
// 示例 3:

// 输入: []
// 输出: []
 

// 提示:

// 二叉树的节点个数的范围是 [0,100]
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> nums;
        if(root) q.push(root);
        while(!q.empty())
        {
            vector<TreeNode*> nodes;
            while(!q.empty())
            {
                nodes.push_back(q.front());
                q.pop();
            }

            nums.push_back(nodes.back()->val);

            for(const auto& e : nodes)
            {
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }
        }

        return nums;
    }
};