


// LCR 022. 环形链表 II
// https://leetcode.cn/problems/c32eOV/description/
// 给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。

// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

// 说明：不允许修改给定的链表。

 

// 示例 1：



// 输入：head = [3,2,0,-4], pos = 1
// 输出：返回索引为 1 的链表节点
// 解释：链表中有一个环，其尾部连接到第二个节点。
// 示例 2：



// 输入：head = [1,2], pos = 0
// 输出：返回索引为 0 的链表节点
// 解释：链表中有一个环，其尾部连接到第一个节点。
// 示例 3：



// 输入：head = [1], pos = -1
// 输出：返回 null
// 解释：链表中没有环。
 

// 提示：

// 链表中节点的数目范围在范围 [0, 104] 内
// -105 <= Node.val <= 105
// pos 的值为 -1 或者链表中的一个有效索引
 

// 进阶：是否可以使用 O(1) 空间解决此题？

 

// 注意：本题与主站 142 题相同： https://leetcode-cn.com/problems/linked-list-cycle-ii/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 空间复杂度O(1)
        if(nullptr == head) return head;

        // 快慢指针相交此时一定在环中
        ListNode* slow = head,* fast = head;
        do
        {
            slow = slow->next;
            fast = fast->next;
            if(nullptr == fast) return nullptr;
            fast = fast->next;
        }while(fast && slow != fast);
        if(nullptr == fast) return nullptr;

        ListNode* end = fast;
        slow = head;
        while(slow != end) // O(n)
        {
            if(slow == fast) return slow;

            fast = fast->next;
            slow = slow->next;
        }

        // while(slow != end) O(n^2)
        // {
        //     while(slow != fast && fast != end) fast = fast->next;
        //     if(end == fast) fast = end->next;
        //     else return slow;

        //     slow = slow->next;
        // }


        

        return end;
    }
};

// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         // 空间复杂度O(n)
//         unordered_set<ListNode*> us;
//         ListNode* cur = head;
//         while(cur)
//         {
//             if(us.find(cur) != us.end()) return cur;

//             us.insert(cur);
//             cur = cur->next;
//         }

//         return nullptr;
//     }
// };