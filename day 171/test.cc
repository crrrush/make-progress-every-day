

// 面试题 02.05. 链表求和

// https://leetcode.cn/problems/sum-lists-lcci/

// 给定两个用链表表示的整数，每个节点包含一个数位。

// 这些数位是反向存放的，也就是个位排在链表首部。

// 编写函数对这两个整数求和，并用链表形式返回结果。

 

// 示例：

// 输入：(7 -> 1 -> 6) + (5 -> 9 -> 2)，即617 + 295
// 输出：2 -> 1 -> 9，即912

// 进阶：思考一下，假设这些数位是正向存放的，又该如何解决呢?

// 示例：

// 输入：(6 -> 1 -> 7) + (2 -> 9 -> 5)，即617 + 295
// 输出：9 -> 1 -> 2，即912



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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* head = new ListNode;
        ListNode* cur = head;
        while(cur1 || cur2 || carry)
        {
            //取值
            int num = 0;
            if(cur1 && cur2)
                num += cur1->val + cur2->val + carry;
            else if(cur1 && !cur2)
                num += cur1->val + carry;
            else if(!cur1 && cur2)
                num += cur2->val + carry;
            else
                num += carry;
            
            if(num >= 10)//进位
            {
                carry = 1;
                num -= 10;
            }
            else
                carry = 0;//置空
            
            //连接
            ListNode* tmp = new ListNode(num);
            if(head == cur)
            {
                head->next = tmp;
                cur = tmp;
            }
            else
            {
                cur->next = tmp;
                cur = cur->next;
            }

            //迭代
            if(cur1)
                cur1 = cur1->next;
            if(cur2)
                cur2 = cur2->next;
        }
        return head->next;
    }
};

