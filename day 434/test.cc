

// 236. 二叉树的最近公共祖先
// https://leetcode.cn/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/description/
// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

 

// 示例 1：


// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出：3
// 解释：节点 5 和节点 1 的最近公共祖先是节点 3 。
// 示例 2：


// 输入：root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出：5
// 解释：节点 5 和节点 4 的最近公共祖先是节点 5 。因为根据定义最近公共祖先节点可以为节点本身。
// 示例 3：

// 输入：root = [1,2], p = 1, q = 2
// 输出：1
 

// 提示：

// 树中节点数目在范围 [2, 105] 内。
// -109 <= Node.val <= 109
// 所有 Node.val 互不相同 。
// p != q
// p 和 q 均存在于给定的二叉树中。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* findAnce(TreeNode* root, TreeNode*& p, TreeNode*& q, bool& fp, bool& fq)
    {
        if(root == nullptr) return nullptr;

        TreeNode* ret = findAnce(root->left, p, q, fp, fq);
        if(ret == nullptr)
        {
            bool ban = false;
            if(fp) ret = findAnce(root->right, p, q, ban, fq);
            else if(fq) ret = findAnce(root->right, p, q, fp, ban);
            else ret = findAnce(root->right, p, q, fp, fq);
        }

        if(p == root) fp = true;
        if(q == root) fq = true;

        if(fp && fq) return (ret == nullptr ? root : ret);

        return nullptr;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool fp = false, fq = false;
        return findAnce(root, p, q, fp, fq);
    }
};


// stack O(n) 回溯
// class Solution {
//     bool findAnce(TreeNode* root, TreeNode*& node, stack<TreeNode*>& st)
//     {
//         if(root == nullptr) return false;
//         st.push(root);

//         if(root == node) return true;

//         if(findAnce(root->left, node, st)) return true;

//         if(findAnce(root->right, node, st)) return true;

//         st.pop();

//         return false;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         stack<TreeNode*> stp;
//         stack<TreeNode*> stq;

//         findAnce(root, p, stp);
//         findAnce(root, q, stq);

//         while(stp.size() > stq.size()) stp.pop();
//         while(stp.size() < stq.size()) stq.pop();

//         while(stp.top() != stq.top())
//         {
//             stp.pop();
//             stq.pop();
//         }

//         return stp.top();
//     }
// };