/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-08 13:09:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-08 13:10:13
 * @FilePath: \every-little-progress\day 352\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 145. 判断对称二叉树
// https://leetcode.cn/problems/dui-cheng-de-er-cha-shu-lcof/description/
// 请设计一个函数判断一棵二叉树是否 轴对称 。

 

// 示例 1：



// 输入：root = [6,7,7,8,9,9,8]
// 输出：true
// 解释：从图中可看出树是轴对称的。
// 示例 2：



// 输入：root = [1,2,2,null,3,null,3]
// 输出：false
// 解释：从图中可看出最后一层的节点不对称。
 

// 提示：

// 0 <= 节点个数 <= 1000

// 注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/

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
    bool is_symmetry(const vector<TreeNode*>& v)
    {
        int left = 0, right = v.size() - 1;
        while(left < right)
        {
            if(v[left] != nullptr && v[right] != nullptr) { if(v[left]->val != v[right]->val) return false; }
            else if(v[left] == nullptr && v[right] == nullptr){}
            else return false;

            ++left;
            --right;
        }

        return true;
    }
public:
    bool checkSymmetricTree(TreeNode* root) {
        queue<TreeNode*> layer;
        layer.push(root);
        while(!layer.empty())
        {
            vector<TreeNode*> tmp;
            while(!layer.empty())
            {
                tmp.push_back(layer.front());
                layer.pop();
            }
            cout<<endl;

            if(!is_symmetry(tmp)) return false;

            for(auto& e : tmp)
            {
                if(e != nullptr)
                {
                    layer.push(e->left);
                    layer.push(e->right);
                }
            }
        }

        return true;
    }
};