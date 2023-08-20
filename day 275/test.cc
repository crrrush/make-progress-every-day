/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-20 19:52:22
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-20 19:52:26
 * @FilePath: \every-little-progress\day 275\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 589. N 叉树的前序遍历
// https://leetcode.cn/problems/n-ary-tree-preorder-traversal/

// 给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。

// n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。


// 示例 1：



// 输入：root = [1,null,3,2,4,null,5,6]
// 输出：[1,3,5,6,2,4]
// 示例 2：



// 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// 输出：[1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

// 提示：

// 节点总数在范围 [0, 104]内
// 0 <= Node.val <= 104
// n 叉树的高度小于或等于 1000
 

// 进阶：递归法很简单，你可以使用迭代法完成此题吗?

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void preorder__(Node* root, vector<int>& v)
    {
        if(root == nullptr) return;

        v.push_back(root->val);
        for(auto& e : root->children) preorder__(e, v);
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder__(root, res);
        return res;
    }
};

