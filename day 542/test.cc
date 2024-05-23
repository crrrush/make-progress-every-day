

// 23. 合并 K 个升序链表
// https://leetcode.cn/problems/merge-k-sorted-lists/description/
// 给你一个链表数组，每个链表都已经按升序排列。

// 请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

// 示例 1：

// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
// 输出：[1,1,2,3,4,4,5,6]
// 解释：链表数组如下：
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// 将它们合并到一个有序链表中得到。
// 1->1->2->3->4->4->5->6
// 示例 2：

// 输入：lists = []
// 输出：[]
// 示例 3：

// 输入：lists = [[]]
// 输出：[]
 

// 提示：

// k == lists.length
// 0 <= k <= 10^4
// 0 <= lists[i].length <= 500
// -10^4 <= lists[i][j] <= 10^4
// lists[i] 按 升序 排列
// lists[i].length 的总和不超过 10^4


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

// 递归分治
class Solution {
    ListNode* head;
    void merge(ListNode* cur, ListNode* L, ListNode* R)
    {
        while(L && R)
        {
            if(L->val <= R->val)
            {
                cur->next = L;
                L = L->next;
            }
            else
            {
                cur->next = R;
                R = R->next;
            }

            cur = cur->next;
        }
        if(L) cur->next = L;
        if(R) cur->next = R;
    }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) // 左闭右闭
    {
        if(left > right)
        {
            return nullptr;
        } 
        else if(left == right)
        {
            return lists[left];
        }
        else if(left + 1 == right)
        {
            merge(head, lists[left], lists[right]);
        }
        else
        {
            int mid = left + (right - left) / 2;
            merge(head, merge(lists, left, mid), merge(lists, mid + 1, right));
        }


        ListNode* ret = head->next;
        head->next = nullptr;
        return ret;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        head = new ListNode;
        ListNode* ret = merge(lists, 0, lists.size() - 1);
        delete head;
        // return merge(lists, 0, lists.size() - 1);
        return ret;
    }
};


// 小根堆
// class Solution {
//     struct cmp{ bool operator()(const ListNode* const& x, const ListNode* const& y) const { return x->val > y->val;} };
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* retl = new ListNode;
//         ListNode* cur = retl;
//         priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

//         for(auto& e : lists) if(e) pq.push(e);

//         while(!pq.empty())
//         {
//             cur->next = pq.top();
//             cur = cur->next;
//             pq.pop();
//             if(cur->next) pq.push(cur->next);
//         }

//         ListNode* head = retl->next;
//         delete retl;

//         return head;
//     }
// };


// 暴力
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* retl = new ListNode;
//         for(int i = 0;i < lists.size();++i)
//         {
//             if(retl->next == nullptr)
//             {
//                 retl->next = lists[i];
//                 continue;
//             }
//             ListNode* cur1 = retl->next;
//             ListNode* cur2 = lists[i];
//             // 头插
//             if(cur2 && cur2->val < cur1->val)
//             {
//                 ListNode* head = cur2;
//                 while(cur2->next && cur2->next->val < cur1->val) cur2 = cur2->next;
//                 ListNode* next = cur2->next;
//                 retl->next = head;
//                 cur2->next = cur1;
//                 cur2 = next;
//             }

//             while(cur1->next && cur2)
//             {
//                 if(cur1->next->val > cur2->val)
//                 {
//                     ListNode* head = cur2;
//                     ListNode* tail = cur1->next;
//                     // cout<<"in?\n";
//                     // 这里可以直接插入一个区间的节点
//                     while(cur2->next && cur2->next->val <= tail->val) cur2 = cur2->next;
//                     ListNode* next = cur2->next;
//                     cur2->next = tail;
//                     cur1->next = head;
//                     cur1 = cur2;
//                     cur2 = next;
//                 }
//                 // if(cur1) cur1 = cur1->next;
//                 if(cur1->next) cur1 = cur1->next;
//             }
//             if(cur2) cur1->next = cur2;
//         }

//         ListNode* ret = retl->next;
//         delete retl;
//         // return retl->next;
//         return ret;
//     }
// };

