

// LCR 078. 合并 K 个升序链表
// https://leetcode.cn/problems/vvXgSW/description/
// 给定一个链表数组，每个链表都已经按升序排列。

// 请将所有链表合并到一个升序链表中，返回合并后的链表。

 

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
 

// 注意：本题与主站 23 题相同： https://leetcode-cn.com/problems/merge-k-sorted-lists/


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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;

        ListNode* head = nullptr;
        int i = 0;
        while(i < lists.size() && nullptr == lists[i]) ++i;


        if(i < lists.size())
        {
            head = lists[i++];
        }
        // if(nullptr == head) return nullptr;

        for(;i < lists.size();++i)
        {
            ListNode* cur = lists[i];
            while(cur)
            {
                // cout<<cur->val<<" ";
                ListNode* next = cur->next;
                // 头插
                if(cur->val <= head->val)
                {
                    cur->next = head;
                    head = cur;
                    cur = next;
                    continue;
                }

                // 优化思路
                // 由于这里所有链表都是有序的
                // 所以并不需要一个一个地插入
                ListNode* tmp = head;
                while(tmp && tmp->next)
                {
                    if(tmp->next->val >= cur->val) break;
                    tmp = tmp->next;
                }
                cur->next = tmp->next;
                tmp->next = cur;
                cur = next;
            }
        }

        return head;
    }
};