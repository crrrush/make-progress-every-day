/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-23 11:07:26
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-23 11:08:02
 * @FilePath: \every-little-progress\day 336\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 508. 出现次数最多的子树元素和
// https://leetcode.cn/problems/most-frequent-subtree-sum/description/
// 给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。

// 一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

 

// 示例 1：



// 输入: root = [5,2,-3]
// 输出: [2,-3,4]
// 示例 2：



// 输入: root = [5,2,-5]
// 输出: [2]
 

// 提示:

// 节点数在 [1, 104] 范围内
// -105 <= Node.val <= 105

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
    int childsum(unordered_map<TreeNode*, int>& hash, TreeNode* root)
    {
        if(root == nullptr) return 0;

        int sum = root->val;
        sum += childsum(hash, root->left);
        sum += childsum(hash, root->right);

        hash[root] = sum;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<TreeNode*, int> hash;
        vector<int> res;
        childsum(hash, root);

        unordered_map<int, int> map;
        for(const auto& [x, y] : hash) ++map[y];

        for(const auto& [x, y] : map) cout << x<<" : "<<y<<endl;

        int maxcnt = -1;
        for(const auto& [x, y] : map)
        {
            if(res.empty())
            {
                res.push_back(x);
                maxcnt = y;
                continue;
            }

            if(y == maxcnt)
                res.push_back(x);
            else if(y > maxcnt)
            {
                res.clear();
                maxcnt = y;
                res.push_back(x);
            }
        }

        return res;
    }
};