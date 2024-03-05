/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-05 14:33:20
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-05 14:33:48
 * @FilePath: \every-little-progress\day 467\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 123. 图书整理 I
// https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/description/
// 书店店员有一张链表形式的书单，每个节点代表一本书，节点中的值表示书的编号。为更方便整理书架，店员需要将书单倒过来排列，就可以从最后一本书开始整理，逐一将书放回到书架上。请倒序返回这个书单链表。

 

// 示例 1：

// 输入：head = [3,6,4,1]

// 输出：[1,4,6,3]
 

// 提示：

// 0 <= 链表长度 <= 10000


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
    vector<int> reverseBookList(ListNode* head) {
        ListNode* cur = head;
        stack<int> st;
        while(cur)
        {
            st.push(cur->val);
            cur = cur->next;
        }

        vector<int> res;
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};