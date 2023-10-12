


// LCR 027. 回文链表
// https://leetcode.cn/problems/aMhZSa/description/

// 给定一个链表的 头节点 head ，请判断其是否为回文链表。

// 如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。

 

// 示例 1：



// 输入: head = [1,2,3,3,2,1]
// 输出: true
// 示例 2：



// 输入: head = [1,2]
// 输出: false
 

// 提示：

// 链表 L 的长度范围为 [1, 105]
// 0 <= node.val <= 9
 

// 进阶：能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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

// O(1)
class Solution
{
public:
    void reverseList(ListNode*& head)
    {
        if(head->next == nullptr) return;

        ListNode* prev = head->next;
        if(prev->next == nullptr) return;
        ListNode* cur = prev->next;

        prev->next = nullptr;
        while(cur != nullptr && cur->next != nullptr)
        {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        if(cur) cur->next = prev;

        head->next = cur;
    }

    bool isPalindrome(ListNode* head) {
        int num = 0;
        ListNode* cur = head;

        while(cur != nullptr)
        {
            ++num;
            cur = cur->next;
        }


        if(num % 2) num = num / 2 + 1;
        else num /= 2;

        ListNode* end1 = nullptr;
        cur = head;
        while(--num) cur = cur->next;
        end1 = cur;
        cout<<end1->val<<endl;
        reverseList(end1);

        ListNode* prev = head;
        cur = end1->next;
        cout<<end1->val<<endl;
        while(cur != nullptr)
        {
            cout<<prev->val<<' '<< cur->val<<endl;
            if(prev->val != cur->val) return false;

            prev = prev->next;
            cur = cur->next;
        }

        return true;
    }
};

// // 空间复杂度O(n)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> v;
//         ListNode* cur = head;

//         while(cur != nullptr)
//         {
//             v.push_back(cur->val);
//             cur = cur->next;
//         }

//         int left = 0, right = v.size() - 1;
//         while(left <= right) if(v[left++] != v[right--]) return false;

//         return true;
//     }
// };


// 空间复杂度O(n)
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         string s;
//         ListNode* cur = head;

//         while(cur != nullptr)
//         {
//             s += ('0' + cur->val);
//             cur = cur->next;
//         }

//         string rs(s);
//         reverse(rs.begin(), rs.end());

//         return rs == s;
//     }
// };