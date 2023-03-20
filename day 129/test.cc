


// 链表分割
// 链接：https://www.nowcoder.com/questionTerminal/0e27e0b064de4eacac178676ef9c9d70
// 来源：牛客网

// 现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。

// 说明：本题目包含复杂数据结构ListNode，点此查看相关信息



/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        struct ListNode* head = NULL, * cur = pHead;
        struct ListNode* end1 = pHead;
        struct ListNode* end2 = head;
        while (cur)
        {
            if (cur->val < x)
            {
                if (cur == pHead)
                {
                    if (end2 == NULL)
                    {
                        head = end2 = cur;
                    }
                    else
                    {
                        end2->next = cur;
                        end2 = end2->next;
                    }                
                    cur = cur->next;
                    end1 = pHead = cur;

                }
                else
                {
                    if (end2 == NULL)
                    {
                        head = end2 = cur;
                    }
                    else
                    {
                        end2->next = cur;
                        end2 = end2->next;
                    }
                    cur = cur->next;            
                    end1->next = cur;
                }
            }
            else
            {
                if (cur == pHead)
                {
                    cur = cur->next;
                }
                else
                {
                    cur = cur->next;
                    if (end1->next != cur)
                        end1 = end1->next;
                }
            }
        }
        if (end1 != NULL)
        {
            if (end1->next)
                end1->next = NULL;
        }
        
        if(head == NULL)
            head = pHead;
        else
            end2->next = pHead;
        
        return head;
        /*struct ListNode* head = NULL,*cur = pHead;
        struct ListNode* end1 = pHead;
        struct ListNode* end2 = head;
        if(pHead->val < x)
        {
            head = end2 = pHead;
            cur = cur->next;
            end1 = pHead = cur;
        }
        else
        {
            cur = cur->next;
        }
        while(cur)
        {
            if(cur->val < x)
            {
                end2->next = cur;
                cur = cur->next;
                end1->next = cur;
            }
        }*/
    }
};