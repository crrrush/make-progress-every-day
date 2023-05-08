

// 1022. 从根到叶的二进制数之和

// https://leetcode.cn/problems/sum-of-root-to-leaf-binary-numbers/description/
// 给出一棵二叉树，其上每个结点的值都是 0 或 1 。每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。

//     例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。

// 对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。

// 返回这些数字之和。题目数据保证答案是一个 32 位 整数。

 

// 示例 1：

// 输入：root = [1,0,1,0,1,0,1]
// 输出：22
// 解释：(100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

// 示例 2：

// 输入：root = [0]
// 输出：0

 

// 提示：

//     树中的节点数在 [1, 1000] 范围内
//     Node.val 仅为 0 或 1 



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
    int _sumRootToLeaf(TreeNode* root, vector<int> v)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            v.push_back(root->val);
            int n = 1;
            int ret = 0;
            auto rit = v.rbegin();
            while(rit != v.rend())
            {
                if(*rit)
                    ret += n;
                
                n *= 2;
                ++rit;
            }
            cout << ret << " ";
            return ret;
        }
        else
            v.push_back(root->val);
        
        if(root->left && root->right == nullptr)
            return _sumRootToLeaf(root->left, v);
        else if(root->right && root->left == nullptr)
            return _sumRootToLeaf(root->right, v);
        else
            return _sumRootToLeaf(root->left, v) + _sumRootToLeaf(root->right, v);
    }
    int sumRootToLeaf(TreeNode* root) {
        vector<int> v;
        return _sumRootToLeaf(root, v);
    }
};