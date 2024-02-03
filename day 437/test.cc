


// 145. 二叉树的后序遍历
// https://leetcode.cn/problems/binary-tree-postorder-traversal/description/
// 给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

 

// 示例 1：


// 输入：root = [1,null,2,3]
// 输出：[3,2,1]
// 示例 2：

// 输入：root = []
// 输出：[]
// 示例 3：

// 输入：root = [1]
// 输出：[1]
 

// 提示：

// 树中节点的数目在范围 [0, 100] 内
// -100 <= Node.val <= 100
 

// 进阶：递归算法很简单，你可以通过迭代算法完成吗？

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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return vector<int>();

        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* cur = root;
        while(!st.empty() || cur)
        {
            while(cur)
            {
                st.push(cur);
                if(cur->left) cur = cur->left;
                else if(cur->right && !cur->left) cur = cur->right;
                else break;
            }

            TreeNode* top = st.top();
            st.pop();
            res.push_back(top->val);


            if(!st.empty() && top == st.top()->left)
                cur = st.top()->right;
            else
                cur = nullptr;
        }

        return res;
    }
};

// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         if(root == nullptr) return vector<int>();
//         stack<TreeNode*> st;
//         st.push(root);
//         vector<int> res;
//         while(!st.empty())
//         {
//             TreeNode* tmp = st.top();
//             if(tmp->left && tmp->right)
//             {
//                 st.push(tmp->right);
//                 st.push(tmp->left);
//             }
//             else if(tmp->left && !tmp->right)
//             {
//                 st.push(tmp->left);
//             }
//             else if(tmp->right && !tmp->left)
//             {
//                 st.push(tmp->right);
//             }
//             else if(!tmp->left && !tmp->right)
//             {
//                 st.pop();
//                 res.push_back(tmp->val);
//             }

//             tmp->left = tmp->right = nullptr;
//         }

//         return res;
//     }
// };