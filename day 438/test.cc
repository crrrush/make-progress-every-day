/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-04 22:30:39
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-04 22:31:07
 * @FilePath: \every-little-progress\day 438\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 530. 二叉搜索树的最小绝对差
// https://leetcode.cn/problems/minimum-absolute-difference-in-bst/description/
// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

// 差值是一个正数，其数值等于两值之差的绝对值。

 

// 示例 1：


// 输入：root = [4,2,6,1,3]
// 输出：1
// 示例 2：


// 输入：root = [1,0,48,null,null,12,49]
// 输出：1
 

// 提示：

// 树中节点的数目范围是 [2, 104]
// 0 <= Node.val <= 105
 

// 注意：本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 相同

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
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* last = nullptr;
        size_t min = -1;
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

            if(last && (top->val - last->val < min)) min = top->val - last->val;
            last = top;

            cur = top->right;
        }

        return min;
    }
};

// class Solution {
//     TreeNode* last = nullptr;
//     size_t min_dif = -1;

//     void get_min_diff(TreeNode* root)
//     {
//         if(root == nullptr) return;

//         get_min_diff(root->left);

//         if(last && (root->val - last->val) < min_dif)
//             min_dif = (root->val - last->val);
//         last = root;

//         get_min_diff(root->right); 
//     }
// public:
//     int getMinimumDifference(TreeNode* root) {
//         get_min_diff(root);
//         return min_dif;
//     }
// };