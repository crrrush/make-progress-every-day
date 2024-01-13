


// LCR 025. 两数相加 II
// https://leetcode.cn/problems/lMSNwu/description/
// 给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

// 可以假设除了数字 0 之外，这两个数字都不会以零开头。

// 示例1：

// 输入：l1 = [7,2,4,3], l2 = [5,6,4]
// 输出：[7,8,0,7]
// 示例2：

// 输入：l1 = [2,4,3], l2 = [5,6,4]
// 输出：[8,0,7]
// 示例3：

// 输入：l1 = [0], l2 = [0]
// 输出：[0]
 

// 提示：

// 链表的长度范围为 [1, 100]
// 0 <= node.val <= 9
// 输入数据保证链表代表的数字无前导 0
 

// 进阶：如果输入链表不能修改该如何处理？换句话说，不能对列表中的节点进行翻转。

 

// 注意：本题与主站 445 题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        stack<int> st1;
        stack<int> st2;
        ListNode* cur1 = l1; 
        ListNode* cur2 = l2;
        while(cur1 != nullptr)
        {
            st1.push(cur1->val);
            cur1 = cur1->next;
        }
        while(cur2 != nullptr)
        {
            st2.push(cur2->val);
            cur2 = cur2->next;
        }

        vector<ListNode*> res;
        while(!st1.empty() && !st2.empty())
        {
            int tmp = st1.top() + st2.top();
            if(tmp + carry > 9)
            {
                res.push_back(new ListNode((tmp + carry) % 10));
                carry = 1;
            }
            else
            {
                res.push_back(new ListNode(tmp + carry));
                carry = 0;
            }
            st1.pop();
            st2.pop();
            cout<<tmp<<" ";
        }
        while(!st1.empty())
        {
            if(st1.top() + carry > 9)
            {
                res.push_back(new ListNode((st1.top() + carry) % 10));
                carry = 1;
            }
            else
            {
                res.push_back(new ListNode(st1.top() + carry));
                carry = 0;
            }
            st1.pop();
        }
        while(!st2.empty())
        {
            if(st2.top() + carry > 9)
            {
                res.push_back(new ListNode((st2.top() + carry) % 10));
                carry = 1;
            }
            else
            {
                res.push_back(new ListNode(st2.top() + carry));
                carry = 0;
            }
            st2.pop();
        }
        if(carry) res.push_back(new ListNode(1));
        
        for(int i = res.size() - 1;i > 0;--i)
        {
            res[i]->next = res[i - 1];
        }
        return res.back();
    }
};


// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         int carry = 0;
//         vector<int> n1;
//         vector<int> n2;
//         ListNode* cur1 = l1; 
//         ListNode* cur2 = l2;
//         while(cur1 != nullptr)
//         {
//             n1.push_back(cur1->val);
//             cur1 = cur1->next;
//         }
//         while(cur2 != nullptr)
//         {
//             n1.push_back(cur2->val);
//             cur2 = cur2->next;
//         }

//         vector<ListNode*> res;
//         auto rit1 = n1.rbegin();
//         auto rit2 = n2.rbegin();

//         while(rit1 != n1.rend() && rit2 != n2.rend())
//         {
//             int tmp = *rit1 + *rit2;
//             if(tmp + carry > 9)
//             {
//                 res.push_back(new ListNode(tmp + carry - 9));
//                 carry = 1;
//             }
//             else
//             {
//                 res.push_back(new ListNode(tmp + carry));
//                 carry = 0;
//             }
//             ++rit1;
//             ++rit2;
//             cout<<tmp<<" ";
//         }
        
//         while(rit1 != n1.rend())
//         {
//             if(*rit1 + carry > 9)
//             {
//                 res.push_back(new ListNode(*rit1 + carry - 9));
//                 carry = 1;
//             }
//             else
//             {
//                 res.push_back(new ListNode(*rit1 + carry));
//                 carry = 0;
//             }
//             ++rit1;
//         }
//         while(rit2 != n2.rend())
//         {
//             if(*rit2 + carry > 9)
//             {
//                 res.push_back(new ListNode(*rit2 + carry - 9));
//                 carry = 1;
//             }
//             else
//             {
//                 res.push_back(new ListNode(*rit2 + carry));
//                 carry = 0;
//             }
//             ++rit2;
//         }
        
//         for(int i = res.size() - 1;i > 0;--i)
//         {
//             res[i]->next = res[i - 1];
//         }
//         return res.back();
//     }
// };