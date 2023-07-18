

// 501. 二叉搜索树中的众数
// https://leetcode.cn/problems/find-mode-in-binary-search-tree/
// 给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。

// 如果树中有不止一个众数，可以按 任意顺序 返回。

// 假定 BST 满足如下定义：

//     结点左子树中所含节点的值 小于等于 当前节点的值
//     结点右子树中所含节点的值 大于等于 当前节点的值
//     左子树和右子树都是二叉搜索树

 

// 示例 1：

// 输入：root = [1,null,2,2]
// 输出：[2]

// 示例 2：

// 输入：root = [0]
// 输出：[0]

 

// 提示：

//     树中节点的数目在范围 [1, 104] 内
//     -105 <= Node.val <= 105

 

// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）



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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        map<int, int> hash;
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();

            ++hash[tmp->val];

            if(tmp->left) q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }

        auto rit = hash.rbegin();
        int max = rit->second;
        while(rit != hash.rend())
        {
            if(rit->second > max)
            {
                res.clear();
                max = rit->second;
            }

            if(rit->second == max) res.push_back(rit->first);
            ++rit;
        }

        return res;
    }
};