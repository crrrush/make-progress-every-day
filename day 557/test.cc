/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-08 20:21:41
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-08 20:22:10
 * @FilePath: \every-little-progress\day 557\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

// 946. 验证栈序列
// https://leetcode.cn/problems/validate-stack-sequences/description/
// 给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

 

// 示例 1：

// 输入：pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
// 输出：true
// 解释：我们可以按以下顺序执行：
// push(1), push(2), push(3), push(4), pop() -> 4,
// push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1
// 示例 2：

// 输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
// 输出：false
// 解释：1 不能在 2 之前弹出。
 

// 提示：

// 1 <= pushed.length <= 1000
// 0 <= pushed[i] <= 1000
// pushed 的所有元素 互不相同
// popped.length == pushed.length
// popped 是 pushed 的一个排列

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int len = pushed.size();
        int in = 0, out = 0;
        while(out < len)
        {
            if(in < len) st.push(pushed[in++]);
            else if(st.top() != popped[out]) return false;

            // if(in >= len && st.top() != popped[out]) return false;
            // cout<<st.top()<<"---"<<popped[out]<<endl;
            // if(st.empty() || (in >= len && st.top() != popped[out])) return false;

            while(!st.empty() && st.top() == popped[out])
            {
                // cout<<st.top()<<" in?\n";
                ++out;
                st.pop();
            }
        }

        return st.empty();
    }
};
