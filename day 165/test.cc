

// 94. 二叉树的中序遍历

// https://leetcode.cn/problems/binary-tree-inorder-traversal/

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

//     树中节点数目在范围 [0, 100] 内
//     -100 <= Node.val <= 100

 

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
        vector<int> v;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur -> left;
            }

            TreeNode* node = st.top();
            st.pop();
            v.push_back(node->val);
            
            cur = node->right;
        }

        return v;
    }
};