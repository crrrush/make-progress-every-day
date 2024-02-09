

// LCR 174. 寻找二叉搜索树中的目标节点
// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
// 某公司组织架构以二叉搜索树形式记录，节点值为处于该职位的员工编号。请返回第 cnt 大的员工编号。

 

// 示例 1：



// 输入：root = [7, 3, 9, 1, 5], cnt = 2
//        7
//       / \
//      3   9
//     / \
//    1   5
// 输出：7
// 示例 2：



// 输入: root = [10, 5, 15, 2, 7, null, 20, 1, null, 6, 8], cnt = 4
//        10
//       / \
//      5   15
//     / \    \
//    2   7    20
//   /   / \ 
//  1   6   8
// 输出: 8
 

// 提示：

// 1 ≤ cnt ≤ 二叉搜索树元素个数

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
    int findTargetNode(TreeNode* root, int cnt) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        while(cur->right)
        {
            st.push(cur);
            cur = cur->right;
        }

        while(cnt)
        {
            if(0 == --cnt) return cur->val;

            if(cur->left)
            {
                TreeNode* tmp = cur->left;
                while(tmp)
                {
                    st.push(tmp);
                    tmp = tmp->right;
                }
            }

            cur = st.top();
            st.pop();
        }

        return -1;
    }
};


// class Solution {
//     void max_left(TreeNode* cur, stack<TreeNode*>& st)
//     {
//         while(cur)
//         {
//             st.push(cur);
//             cur = cur->right;
//         }
//     }
// public:
//     int findTargetNode(TreeNode* root, int cnt) {
//         TreeNode* cur = root;
//         stack<TreeNode*> st;
//         while(cur->right)
//         {
//             st.push(cur);
//             cur = cur->right;
//         }

//         while(cnt)
//         {
//             if(0 == --cnt) return cur->val;

//             if(cur->left) max_left(cur->left, st);

//             cur = st.top();
//             st.pop();
//         }

//         return -1;
//     }
// };

// class Solution {
// public:
//     int findTargetNode(TreeNode* root, int& cnt) {
//         if(root == nullptr) return -1;

//         int ret = findTargetNode(root->right, cnt);
//         if(-1 != ret) return ret;

//         --cnt;
//         if(0 == cnt) return root->val;

//         return findTargetNode(root->left, cnt);
//     }
// };

