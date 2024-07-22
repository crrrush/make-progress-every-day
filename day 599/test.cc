/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-22 22:09:34
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-22 22:15:42
 * @FilePath: \every-little-progress\day 599\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 515. 在每个树行中找最大值
// https://leetcode.cn/problems/find-largest-value-in-each-tree-row/description/
// 给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

 

// 示例1：



// 输入: root = [1,3,2,5,3,null,9]
// 输出: [1,3,9]
// 示例2：

// 输入: root = [1,2,3]
// 输出: [1,3]
 

// 提示：

// 二叉树的节点个数的范围是 [0,104]
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
public:
    vector<int> largestValues(TreeNode* root) {
        if(nullptr == root) return vector<int>();
        queue<TreeNode*> q;
        vector<int> ret;
        q.push(root);
        while(!q.empty())
        {
            queue<TreeNode*> tmp;
            int num = INT_MIN;
            while(!q.empty())
            {
                num = max(num, q.front()->val);
                if(q.front()->left) tmp.push(q.front()->left);
                if(q.front()->right) tmp.push(q.front()->right);
                q.pop();
            }
            ret.push_back(num);
            q.swap(tmp);
        }

        return ret;
    }
};
