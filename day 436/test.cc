

// 94. 二叉树的中序遍历
// https://leetcode.cn/problems/binary-tree-inorder-traversal/description/
// 给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

// 示例 1：


// 输入：root = [1,null,2,3]
// 输出：[1,3,2]
// 示例 2：

// 输入：root = []
// 输出：[]
// 示例 3：

// 输入：root = [1]
// 输出：[1]
 

// 提示：

// 树中节点数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
 

// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>();
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;
        while(!st.empty() || cur)
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st.top();
            st.pop();

            res.push_back(top->val);

            cur = top->right;
        }

        return res;
    }
};

// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         if(root == nullptr) return vector<int>();
//         stack<TreeNode*> st;
//         st.push(root);
//         vector<int> res;
//         while(!st.empty())
//         {
//             TreeNode* tmp = st.top();
//             if(tmp->left)
//             {
//                 st.push(tmp->left);
//                 tmp->left = nullptr;
//             }
//             else if(tmp->right && !tmp->left)
//             {
//                 res.push_back(tmp->val);
//                 st.pop();
//                 st.push(tmp->right);
//             }
//             else if(!tmp->left && !tmp->right)
//             {
//                 res.push_back(tmp->val);
//                 st.pop();
//             }

//         }

//         return res;
//     }
// };