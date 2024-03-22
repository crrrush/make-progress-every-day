/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-22 15:30:00
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-22 15:30:35
 * @FilePath: \every-little-progress\day 483\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 140. 训练计划 II
// https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/description/
// 给定一个头节点为 head 的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第 cnt 个训练项目编号。

 

// 示例 1：

// 输入：head = [2,4,7,8], cnt = 1
// 输出：8
 

// 提示：

// 1 <= head.length <= 100
// 0 <= head[i] <= 100
// 1 <= cnt <= head.length

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
    ListNode* trainingPlan(ListNode* head, int cnt) {
        // 快慢指针 相隔cnt步
        ListNode* prev = head;
        ListNode* cur = head;
        for(int i = 0;i < cnt && cur;++i) cur = cur->next;

        while(cur)
        {
            cur = cur->next;
            prev = prev->next;
        }

        return prev;
    }
};