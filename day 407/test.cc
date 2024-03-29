/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-01-03 18:36:35
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-01-03 18:37:00
 * @FilePath: \every-little-progress\day 407\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1669. 合并两个链表
// https://leetcode.cn/problems/merge-in-between-linked-lists/description/
// 给你两个链表 list1 和 list2 ，它们包含的元素分别为 n 个和 m 个。

// 请你将 list1 中下标从 a 到 b 的全部节点都删除，并将list2 接在被删除节点的位置。

// 下图中蓝色边和节点展示了操作后的结果：


// 请你返回结果链表的头指针。

 

// 示例 1：



// 输入：list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
// 输出：[0,1,2,1000000,1000001,1000002,5]
// 解释：我们删除 list1 中下标为 3 和 4 的两个节点，并将 list2 接在该位置。上图中蓝色的边和节点为答案链表。
// 示例 2：


// 输入：list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
// 输出：[0,1,1000000,1000001,1000002,1000003,1000004,6]
// 解释：上图中蓝色的边和节点为答案链表。
 

// 提示：

// 3 <= list1.length <= 104
// 1 <= a <= b < list1.length - 1
// 1 <= list2.length <= 104


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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<ListNode*> v;
        ListNode* cur = list1;
        while(cur != nullptr)
        {
            v.push_back(cur);
            cur = cur->next;
        }
        cur = v[a - 1]->next = list2;
        while(cur->next != nullptr) cur = cur->next;
        cur->next = v[b + 1];

        return list1;
    }
};


// class Solution {
// public:
//     ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
//         ListNode* cur = list1;
//         ListNode* prev = nullptr;
//         ListNode* next = nullptr;

//         for(int i = 0;i <= b + 1;++i)
//         {
//             if(i == a - 1) prev = cur;
//             if(i == b + 1) next = cur;
//             // if(i >= a && i <= b) delete node
//             cur = cur->next;
//         }

//         prev->next = list2;
//         cur = list2;
//         while(cur->next != nullptr) cur = cur->next;
//         cur->next = next;
//         return list1;
//     }
// };