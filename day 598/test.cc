/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-21 16:52:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-21 16:53:13
 * @FilePath: \every-little-progress\day 598\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 662. 二叉树最大宽度
// https://leetcode.cn/problems/maximum-width-of-binary-tree/description/
// 给你一棵二叉树的根节点 root ，返回树的 最大宽度 。

// 树的 最大宽度 是所有层中最大的 宽度 。

// 每一层的 宽度 被定义为该层最左和最右的非空节点（即，两个端点）之间的长度。将这个二叉树视作与满二叉树结构相同，两端点间会出现一些延伸到这一层的 null 节点，这些 null 节点也计入长度。

// 题目数据保证答案将会在  32 位 带符号整数范围内。

 

// 示例 1：


// 输入：root = [1,3,2,5,3,null,9]
// 输出：4
// 解释：最大宽度出现在树的第 3 层，宽度为 4 (5,3,null,9) 。
// 示例 2：


// 输入：root = [1,3,2,5,null,null,9,6,null,7]
// 输出：7
// 解释：最大宽度出现在树的第 4 层，宽度为 7 (6,null,null,null,null,null,7) 。
// 示例 3：


// 输入：root = [1,3,2,5]
// 输出：2
// 解释：最大宽度出现在树的第 2 层，宽度为 2 (3,2) 。
 

// 提示：

// 树中节点的数目范围是 [1, 3000]
// -100 <= Node.val <= 100


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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long ret = 0;
        vector<pair<TreeNode*, unsigned long long>> q;
        q.push_back(make_pair(root, 1));
        while(!q.empty())
        {
            ret = max(ret, q.back().second - q.front().second + 1);
            vector<pair<TreeNode*, unsigned long long>> tmp;
            for(auto& [x, y] : q)
            {
                if(x->left) tmp.push_back(make_pair(x->left, 2 * y - 1));
                if(x->right) tmp.push_back(make_pair(x->right, 2 * y));
            }
            q.swap(tmp);
        }

        return ret;
    }
};


// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//         int ret = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty())
//         {
//             vector<TreeNode*> tmp;
//             bool null = true;
//             int width = 0;
//             while(!q.empty())
//             {
//                 tmp.push_back(q.front());
//                 q.pop();
//             }
//             while(!tmp.empty() && nullptr == tmp.back()) tmp.pop_back();
//             for(auto& e : tmp)
//             {
//                 if(e)
//                 {
//                     null = false;
//                     q.push(e->left);
//                     q.push(e->right);
//                 }
//                 else
//                 {
//                     q.push(nullptr);
//                     q.push(nullptr);
//                 }
//                 if(!null) ++width;
//             }

//             ret = max(ret, width);
//             if(null) break;
//         }

//         return ret;
//     }
// };
