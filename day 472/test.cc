


// 147. 对链表进行插入排序
// https://leetcode.cn/problems/insertion-sort-list/description/
// 给定单个链表的头 head ，使用 插入排序 对链表进行排序，并返回 排序后链表的头 。

// 插入排序 算法的步骤:

// 插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
// 每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
// 重复直到所有输入数据插入完为止。
// 下面是插入排序算法的一个图形示例。部分排序的列表(黑色)最初只包含列表中的第一个元素。每次迭代时，从输入数据中删除一个元素(红色)，并就地插入已排序的列表中。

// 对链表进行插入排序。



 

// 示例 1：



// 输入: head = [4,2,1,3]
// 输出: [1,2,3,4]
// 示例 2：



// 输入: head = [-1,5,3,4,0]
// 输出: [-1,0,3,4,5]
 

// 提示：

// 列表中的节点数在 [1, 5000]范围内
// -5000 <= Node.val <= 5000


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
    ListNode* insertionSortList(ListNode* head) {
        map<int, vector<ListNode*> > hash;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            hash[cur->val].push_back(cur);
            cur = cur->next;
        }

        ListNode* newhead = nullptr;
        ListNode* lastnode = nullptr;
        for(auto& [x, y] : hash)
        {
            if(lastnode)
            {
                lastnode->next = y.front();
                for(int i = 0;i < y.size() - 1;++i)
                {
                    y[i]->next = y[i + 1];
                }
                lastnode = y.back();
            }
            else
            {
                newhead = y.front();
                for(int i = 0;i < y.size() - 1;++i)
                {
                    y[i]->next = y[i + 1];
                }
                lastnode = y.back();
            }
        }

        lastnode->next = nullptr;
        return newhead;
    }
};

// class Solution {
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         ListNode* end = head;
//         while(end)
//         {
//             ListNode* cur = end;
//             ListNode* tmp = cur;
//             while(cur != nullptr)
//             {
//                 if(cur->val < tmp->val) tmp = cur;
//                 cur = cur->next;
//             }
//             swap(end->val, tmp->val);
//             end = end->next;
//         }

//         return head;
//     }
// };