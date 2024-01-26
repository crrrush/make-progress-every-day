

// 107. 二叉树的层序遍历 II
// https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/description/
// 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

 
// 示例 1：


// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[15,7],[9,20],[3]]
// 示例 2：

// 输入：root = [1]
// 输出：[[1]]
// 示例 3：

// 输入：root = []
// 输出：[]
 

// 提示：

// 树中节点数目在范围 [0, 2000] 内
// -1000 <= Node.val <= 1000


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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> v;
            vector<TreeNode*> vn;

            // 取一层
            while(!q.empty())
            {
                vn.push_back(q.front());
                q.pop();
            }
            // 存放数据并放入下一层
            for(const auto& e : vn)
            {
                if(e != nullptr)
                {
                    v.push_back(e->val);
                    q.push(e->left);
                    q.push(e->right);
                }
            }

            if(!v.empty()) vv.push_back(v);
        }

        reverse(vv.begin(), vv.end());

        return vv;
    }
};


// class Solution {
// public:
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> vv;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             vector<int> v;
//             vector<TreeNode*> vn;

//             // 取一层
//             while(!q.empty())
//             {
//                 vn.push_back(q.front());
//                 q.pop();
//             }
//             // 存放数据并放入下一层
//             for(const auto& e : vn)
//             {
//                 if(e != nullptr)
//                 {
//                     v.push_back(e->val);
//                     q.push(e->left);
//                     q.push(e->right);
//                 }
//             }

//             if(!v.empty()) vv.push_back(v);
//         }

//         vector<vector<int>> res;
//         for(auto rit = vv.rbegin();rit != vv.rend();++rit)
//         {
//             vector<int> tmp;
//             for(const auto& e : *rit) tmp.push_back(e);
//             res.push_back(tmp);
//         }

//         return res;
//     }
// };