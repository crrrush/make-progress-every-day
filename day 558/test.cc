

// 429. N 叉树的层序遍历
// https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
// 给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。

// 树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

 

// 示例 1：



// 输入：root = [1,null,3,2,4,null,5,6]
// 输出：[[1],[3,2,4],[5,6]]
// 示例 2：



// 输入：root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// 输出：[[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

// 提示：

// 树的高度不会超过 1000
// 树的节点总数在 [0, 104] 之间


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
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> vv;
        queue<Node*> q;
        if(nullptr != root) q.push(root);
        while(!q.empty())
        {
            vector<int> vtmp;
            int sz = q.size();
            for(int i = 0;i < sz;++i)
            {
                vtmp.push_back(q.front()->val);
                for(auto& r : q.front()->children) if(r) q.push(r);

                q.pop();
            }
            vv.push_back(vtmp);
        }

        return vv;
    }
};


// /*
// // Definition for a Node.
// class Node {
// public:
//     int val;
//     vector<Node*> children;

//     Node() {}

//     Node(int _val) {
//         val = _val;
//     }

//     Node(int _val, vector<Node*> _children) {
//         val = _val;
//         children = _children;
//     }
// };
// */

// class Solution {
// public:
//     vector<vector<int>> levelOrder(Node* root) {
//         vector<vector<int>> vv;
//         queue<Node*> q;
//         if(nullptr != root) q.push(root);
//         vector<Node*> vnodes;
//         while(!q.empty())
//         {
//             while(!q.empty())
//             {
//                 vnodes.push_back(q.front());
//                 q.pop();
//             }

//             vector<int> vtmp;
//             for(auto& e : vnodes)
//             {
//                 vtmp.push_back(e->val);
//                 for(auto& r : e->children) if(r) q.push(r);
//             }
//             vv.push_back(vtmp);

//             vnodes.clear();
//         }

//         return vv;
//     }
// };

