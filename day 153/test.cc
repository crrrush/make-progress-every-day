

// 链表内指定区间反转
// 链接：https://www.nowcoder.com/questionTerminal/b58434e200a648c589ca2063f1faf58c
// 来源：牛客网

// 将一个节点数为 size 链表 m 位置到 n 位置之间的区间反转，要求时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)。
// 例如：
// 给出的链表为 1→2→3→4→5→NULL1→2→3→4→5→NULL, m=2,n=4m=2,n=4,
// 返回 1→4→3→2→5→NULL1→4→3→2→5→NULL.

// 数据范围： 链表长度 0<size≤10000<size≤1000，0<m≤n≤size0<m≤n≤size，链表中每个节点的值满足 ∣val∣≤1000∣val∣≤1000
// 要求：时间复杂度 O(n)O(n) ，空间复杂度 O(n)O(n)
// 进阶：时间复杂度 O(n)O(n)，空间复杂度 O(1)O(1)
// 示例1
// 输入

// {1,2,3,4,5},2,4

// 输出

// {1,4,3,2,5}

// 示例2
// 输入

// {5},1,1

// 输出

// {5}


/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* preNode = nullptr, *aftNode = nullptr;//记录第m-1和第m个节点的位置
        ListNode* prev = nullptr, *cur = head;
        for(int i = 1;i <= n + 1;++i)
        {
            if(i < m)
                preNode = cur;
            else if(i == m)
                aftNode = cur;
            else if(i > m && i < n + 1)
            {
                ListNode* tmp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = tmp;
                continue;
            }
            else if(i == n + 1)
            {
                if(preNode)
                    preNode->next = prev;
                aftNode->next = cur;
                if(m == 1)
                    head = prev;
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        return head;
    }
};