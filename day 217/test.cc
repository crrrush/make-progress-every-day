

// 257. 二叉树的所有路径
// https://leetcode.cn/problems/binary-tree-paths/
// 给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。

// 叶子节点 是指没有子节点的节点。
 

// 示例 1：

// 输入：root = [1,2,3,null,5]
// 输出：["1->2->5","1->3"]

// 示例 2：

// 输入：root = [1]
// 输出：["1"]

 

// 提示：

//     树中节点的数目在范围 [1, 100] 内
//     -100 <= Node.val <= 100



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
    string itos(int val)
    {
        string num;
        bool flag = false;
        if(val < 0)
        {
            val = -val;
            flag = true;
        }
        while(val)
        {
            num += ('0' + val % 10);
            val /= 10;
        }
        if(flag) num += '-';
        reverse(num.begin(), num.end());
        return num;
    }

    void binaryTreePaths_(TreeNode* root, vector<string>& vs, string s)
    {
        if(root == nullptr) return;

        if(root->left == nullptr && root->right == nullptr)
        {
            s += itos(root->val);
            vs.push_back(s);
        }
        else if(root->left != nullptr && root->right == nullptr)
        {
            s += itos(root->val);
            s += "->";
            binaryTreePaths_(root->left, vs, s);
        }
        else if(root->left == nullptr && root->right != nullptr)
        {
            s += itos(root->val);
            s += "->";
            binaryTreePaths_(root->right, vs, s);            
        }
        else
        {
            s += itos(root->val);
            s += "->";
            binaryTreePaths_(root->left, vs, s);
            binaryTreePaths_(root->right, vs, s);            
        }

    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vs;
        string s;
        binaryTreePaths_(root, vs, s);

        return vs;
    }
};