/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-25 12:31:00
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-25 12:31:28
 * @FilePath: \every-little-progress\day 428\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 606. 根据二叉树创建字符串
// https://leetcode.cn/problems/construct-string-from-binary-tree/description/
// 给你二叉树的根节点 root ，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。

// 空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

 

// 示例 1：


// 输入：root = [1,2,3,4]
// 输出："1(2(4))(3)"
// 解释：初步转化后得到 "1(2(4)())(3()())" ，但省略所有不必要的空括号对后，字符串应该是"1(2(4))(3)" 。
// 示例 2：


// 输入：root = [1,2,3,null,4]
// 输出："1(2()(4))(3)"
// 解释：和第一个示例类似，但是无法省略第一个空括号对，否则会破坏输入与输出一一映射的关系。
 

// 提示：

// 树中节点的数目范围是 [1, 104]
// -1000 <= Node.val <= 1000

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
    string tree2str(TreeNode* root) {
        if(root == nullptr) return "";

        string ret = to_string(root->val);
        if(root->left && root->right)
            return (ret + "(" + tree2str(root->left) + ")" + "(" + tree2str(root->right) + ")");
        else if(root->left)
            return (ret + "(" + tree2str(root->left) + ")");
        else if(root->right)
            return (ret + "()" + "(" + tree2str(root->right) + ")");
        else
            return ret;
    }
};


// class Solution {
//     string preorder(TreeNode* root)
//     {
//         if(root == nullptr) return "";

//         string ret = to_string(root->val);
//         if(root->left && root->right)
//             return ("(" + ret + preorder(root->left) + preorder(root->right) + ")");
//         else if(root->left)
//             return ("(" + ret + preorder(root->left) + ")");
//         else if(root->right)
//             return ("(" + ret + "()" + preorder(root->right) + ")");
//         else
//             return ("(" + ret + ")");
//     }
// public:
//     string tree2str(TreeNode* root) {
//         if(root == nullptr) return "";

//         string ret = to_string(root->val);
//         if(root->left && root->right)
//             return (ret + preorder(root->left) + preorder(root->right));
//         else if(root->left)
//             return (ret + preorder(root->left));
//         else if(root->right)
//             return (ret + "()" + preorder(root->right));
//         else
//             return ret;
//     }
// };