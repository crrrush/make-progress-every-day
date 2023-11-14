/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-11-14 12:46:01
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-11-14 13:01:07
 * @FilePath: \every-little-progress\day 358\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// 148. 排序链表
// https://leetcode.cn/problems/sort-list/description/
// 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

 

// 示例 1：


// 输入：head = [4,2,1,3]
// 输出：[1,2,3,4]
// 示例 2：


// 输入：head = [-1,5,3,4,0]
// 输出：[-1,0,3,4,5]
// 示例 3：

// 输入：head = []
// 输出：[]
 

// 提示：

// 链表中节点的数目在范围 [0, 5 * 104] 内
// -105 <= Node.val <= 105
 

// 进阶：你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            nums.push_back(cur->val);
            cur = cur->next;
        }
        
        sort(nums.begin(), nums.end());
        cur = head;
        // for(int i = 0;cur != nullptr && i < nums.size();++i)
        for(int i = 0;i < nums.size();++i)
        {
            cur->val = nums[i];
            cur = cur->next;
        }

        return head;
    }
};