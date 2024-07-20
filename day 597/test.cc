/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-20 12:08:52
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-20 12:09:18
 * @FilePath: \every-little-progress\day 597\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 103. 二叉树的锯齿形层序遍历
// https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
// 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

 

// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[20,9],[15,7]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数目在范围 [0, 2000] 内
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(nullptr == root) return vector<vector<int>>();
        queue<TreeNode*> q;
        vector<vector<int>> ret;
        q.push(root);
        int flag = 0;
        while(!q.empty())
        {
            stack<TreeNode*> st;
            vector<int> tmp;
            while(!q.empty())
            {
                st.push(q.front());
                q.pop();
            }
            if(flag % 2)
            {
                while(!st.empty())
                {
                    tmp.push_back(st.top()->val);
                    if(st.top()->right) q.push(st.top()->right);
                    if(st.top()->left) q.push(st.top()->left);
                    st.pop();
                }
            }
            else
            {
                while(!st.empty())
                {
                    tmp.push_back(st.top()->val);
                    if(st.top()->left) q.push(st.top()->left);
                    if(st.top()->right) q.push(st.top()->right);
                    st.pop();
                }
            }

            ret.push_back(tmp);
            ++flag;
        }

        return ret;
    }
};
