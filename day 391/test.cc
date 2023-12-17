/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-17 15:20:06
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-17 15:20:50
 * @FilePath: \every-little-progress\day 391\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 783. 二叉搜索树节点最小距离
// https://leetcode.cn/problems/minimum-distance-between-bst-nodes/description/
// 给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。

// 差值是一个正数，其数值等于两值之差的绝对值。

 

// 示例 1：


// 输入：root = [4,2,6,1,3]
// 输出：1
// 示例 2：


// 输入：root = [1,0,48,null,null,12,49]
// 输出：1
 

// 提示：

// 树中节点的数目范围是 [2, 100]
// 0 <= Node.val <= 105
 

// 注意：本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 相同

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
    void get_nums(TreeNode* root, vector<int>& nums)
    {
        if(root == nullptr) return;
        get_nums(root->left, nums);
        nums.push_back(root->val);
        get_nums(root->right, nums);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> nums;
        get_nums(root, nums);
        size_t dif = -1;
        for(int i = 0;i < nums.size() - 1;++i) if(nums[i + 1] - nums[i] < dif) dif = nums[i + 1] - nums[i];
        return dif;
    }
};