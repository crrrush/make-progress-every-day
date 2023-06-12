

// 234. 回文链表
// https://leetcode.cn/problems/palindrome-linked-list/

// 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：head = [1,2,2,1]
// 输出：true

// 示例 2：

// 输入：head = [1,2]
// 输出：false

 

// 提示：

//     链表中节点数目在范围[1, 105] 内
//     0 <= Node.val <= 9

 

// 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？


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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* cur = head;
        while(cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }

        cur = head;
        while(!st.empty())
        {
            if(cur->val != st.top()) return false;

            cur = cur->next;
            st.pop();
        }

        return true;
    }
};