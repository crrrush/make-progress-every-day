

// LCR 055. 二叉搜索树迭代器
// https://leetcode.cn/problems/kTOapQ/
// 实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：

// BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
// boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
// int next()将指针向右移动，然后返回指针处的数字。
// 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。

// 可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。

 

// 示例：



// 输入
// inputs = ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
// inputs = [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
// 输出
// [null, 3, 7, true, 9, true, 15, true, 20, false]

// 解释
// BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
// bSTIterator.next();    // 返回 3
// bSTIterator.next();    // 返回 7
// bSTIterator.hasNext(); // 返回 True
// bSTIterator.next();    // 返回 9
// bSTIterator.hasNext(); // 返回 True
// bSTIterator.next();    // 返回 15
// bSTIterator.hasNext(); // 返回 True
// bSTIterator.next();    // 返回 20
// bSTIterator.hasNext(); // 返回 False
 

// 提示：

// 树中节点的数目在范围 [1, 105] 内
// 0 <= Node.val <= 106
// 最多调用 105 次 hasNext 和 next 操作
 

// 进阶：

// 你可以设计一个满足下述条件的解决方案吗？next() 和 hasNext() 操作均摊时间复杂度为 O(1) ，并使用 O(h) 内存。其中 h 是树的高度。
 

// 注意：本题与主站 173 题相同： https://leetcode-cn.com/problems/binary-search-tree-iterator/


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
class BSTIterator {
    TreeNode* _root;
    TreeNode* _node = nullptr;
    stack<TreeNode*> _st;// 进阶写法 时间复杂度O(1) 空间复杂度O(h)即O(log n)

    // 右树找最小
    TreeNode* min_right(TreeNode* root)
    {
        TreeNode* min_node = root->right;
        while(min_node->left)
        {
            _st.push(min_node);
            min_node = min_node->left;
        }

        return min_node;
    }
public:
    BSTIterator(TreeNode* root):_root(root) 
    {
        _node = root;
        while(_node->left)
        {
            _st.push(_node);
            _node = _node->left;
        }
    }
    
    int next() 
    {
        int ret = _node->val;

        if(_node->right)
        {
            _node = min_right(_node);
        }
        else if(_node->right == nullptr && !_st.empty())
        {
            _node = _st.top();
            _st.pop();
        }
        else
        {
            _node = nullptr;
        }

        return ret;
    }
    
    bool hasNext() { return _node != nullptr; }
};



// class BSTIterator {
//     TreeNode* _root;
//     TreeNode* _node = nullptr;
//      // 时间复杂度O(log n) 空间复杂度O(1)

//     // 右树找最小
//     TreeNode* min_right(TreeNode* root)
//     {
//         TreeNode* min_node = root->right;
//         while(min_node->left) min_node = min_node->left;

//         return min_node;
//     }
// public:
//     BSTIterator(TreeNode* root):_root(root) 
//     {
//         _node = root;
//         while(_node->left) _node = _node->left;
//     }
    
//     int next() 
//     {
//         // if(nullptr == _node) return -1;

//         int ret = _node->val;

//         if(_node->right)
//         {
//             _node = min_right(_node);
//             return ret;
//         }

//         TreeNode* cur = _root;
//         TreeNode* pa = nullptr;
//         TreeNode* gp = nullptr;

//         while(cur)
//         {
//             if(cur->val > _node->val)
//             {
//                 if(nullptr != pa)
//                 {
//                     gp = pa;
//                 }
                

//                 pa = cur;
//                 cur = cur->left;
//             }
//             else if(cur->val < _node->val)
//             {
//                 if(nullptr != pa && cur == pa->left)
//                 {
//                     gp = pa;
//                 }

//                 pa = cur;
//                 cur = cur->right;
//             }
//             else
//                 break;
//         }

//         if(nullptr == pa || cur == pa->left)
//         {
//             _node = pa;
//         }
//         else if(cur == pa->right)
//         {
//             _node = gp;
//         }

//         return ret;
//     }
    
//     bool hasNext() {
//         return _node != nullptr;
//     }
// };

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */