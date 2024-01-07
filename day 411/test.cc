

// 82. 删除排序链表中的重复元素 II
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/description/
// 给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。

 

// 示例 1：


// 输入：head = [1,2,3,3,4,4,5]
// 输出：[1,2,5]
// 示例 2：


// 输入：head = [1,1,1,2,3]
// 输出：[2,3]
 

// 提示：

// 链表中节点数目在范围 [0, 300] 内
// -100 <= Node.val <= 100
// 题目数据保证链表已经按升序 排列


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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* prev = head;
//         ListNode* cur = (head == nullptr ? nullptr : head->next);
//         while(cur != nullptr)
//         {
//             if(prev->val == cur->val)
//             {
//                 while(cur != nullptr && cur->val == prev->val) cur = cur->next;
                
//                 if(prev == head) head = cur;
//                 else prev->next = cur;

//                 prev = cur;
//             }
//             else if(prev->next->val == cur->val)
//             {
//                 while(cur != nullptr && cur->val == prev->next->val) cur = cur->next;

//                 prev->next = cur;
//             }

//             if(cur != nullptr) cur = cur->next;
//         }

//         return head;
//     }
// };


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_map<int, int> hash;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ++hash[cur->val];
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr && cur->next != nullptr)
        {
            if(hash[cur->val] > 1)
            {
                ListNode* tmp = cur->next;
                while(tmp != nullptr && hash[tmp->val] > 1) tmp = tmp->next;
                head = tmp;
                cur = head;
            }
            if(cur != nullptr && cur->next != nullptr && hash[cur->next->val] > 1)
            {
                ListNode* tmp = cur->next;
                while(tmp != nullptr && hash[tmp->val] > 1) tmp = tmp->next;
                cur->next = tmp;
            }
            if(cur != nullptr) cur = cur->next;
        }

        return head;
    }
};


// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         unordered_set<int> hash;
//         ListNode* cur = head;
//         while(cur != nullptr && cur->next != nullptr)
//         {
//             if(hash.find(cur->val) == hash.end()) hash.insert(cur->val);
//             if(hash.find(cur->next->val) != hash.end())
//             {
//                 ListNode* tmp = cur->next->next;
//                 cur->next = tmp;
//             }
//             cur = cur->next;
//         }

//         return head;
//     }
// };