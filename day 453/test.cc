/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-19 18:15:33
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-19 18:16:05
 * @FilePath: \every-little-progress\day 453\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 623. 在二叉树中增加一行
// https://leetcode.cn/problems/add-one-row-to-tree/description/
// 给定一个二叉树的根 root 和两个整数 val 和 depth ，在给定的深度 depth 处添加一个值为 val 的节点行。

// 注意，根节点 root 位于深度 1 。

// 加法规则如下:

// 给定整数 depth，对于深度为 depth - 1 的每个非空树节点 cur ，创建两个值为 val 的树节点作为 cur 的左子树根和右子树根。
// cur 原来的左子树应该是新的左子树根的左子树。
// cur 原来的右子树应该是新的右子树根的右子树。
// 如果 depth == 1 意味着 depth - 1 根本没有深度，那么创建一个树节点，值 val 作为整个原始树的新根，而原始树就是新根的左子树。
 

// 示例 1:



// 输入: root = [4,2,6,3,1,5], val = 1, depth = 2
// 输出: [4,1,1,2,null,null,6,3,1,5]
// 示例 2:



// 输入: root = [4,2,null,3,1], val = 1, depth = 3
// 输出:  [4,2,null,1,1,3,null,null,1]
 

// 提示:

// 节点数在 [1, 104] 范围内
// 树的深度在 [1, 104]范围内
// -100 <= Node.val <= 100
// -105 <= val <= 105
// 1 <= depth <= the depth of tree + 1


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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* tmp = new TreeNode(val);
            tmp->left = root;
            return tmp;
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> layer;
        while(--depth && !q.empty())
        {
            while(!q.empty())
            {
                layer.push_back(q.front());
                q.pop();
            }

            for(const auto& e : layer)
            {
                if(e->left) q.push(e->left);
                if(e->right) q.push(e->right);
            }

            if(depth != 1) layer.clear();
        }

        for(auto& e : layer)
        {
            TreeNode* tmp = new TreeNode(val);
            tmp->left = e->left;
            e->left = tmp;

            tmp = new TreeNode(val);
            tmp->right = e->right;
            e->right = tmp;
        }

        return root;
    }
};