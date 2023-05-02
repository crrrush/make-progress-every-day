
// 1171. 从链表中删去总和值为零的连续节点

// https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

// 给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。

// 删除完毕后，请你返回最终结果链表的头节点。

 

// 你可以返回任何满足题目要求的答案。

// （注意，下面示例中的所有序列，都是对 ListNode 对象序列化的表示。）

// 示例 1：

// 输入：head = [1,2,-3,3,1]
// 输出：[3,1]
// 提示：答案 [1,2,1] 也是正确的。

// 示例 2：

// 输入：head = [1,2,3,-3,4]
// 输出：[1,2,4]

// 示例 3：

// 输入：head = [1,2,3,-3,-2]
// 输出：[1]

 

// 提示：

//     给你的链表中可能有 1 到 1000 个节点。
//     对于链表中的每个节点，节点的值：-1000 <= node.val <= 1000.



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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* Ph = new ListNode();
        Ph->next = head;
        ListNode* prev = Ph;
        while(prev)
        {
            int sum = 0;
            ListNode* cur = prev->next;
            int flag = 0;
            while(cur)
            {
                sum += cur->val;
                cur = cur->next;
                if(sum == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if(sum == 0 && flag)
            {
                ListNode* del = prev->next;
                while(del != cur)
                {
                    ListNode* tmp = del;
                    del = del->next;
                    //delete tmp;
                }
                if(Ph == prev)
                    Ph->next = cur;
                
                prev->next = cur;
            }
            else
                prev = prev->next;
        }
        return Ph->next;
    }
};
