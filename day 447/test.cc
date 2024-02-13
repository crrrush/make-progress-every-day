/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-02-13 15:29:11
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-02-13 15:30:17
 * @FilePath: \every-little-progress\day 447\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 03.02. 栈的最小值
// https://leetcode.cn/problems/min-stack-lcci/description/
// 请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。


// 示例：

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.


class MinStack {
    stack<int> st;
    stack<int> min;
public:
    /** initialize your data structure here. */
    // MinStack() {}
    
    void push(int x) {
        st.push(x);
        if(min.empty() || min.top() >= x) min.push(x);
    }
    
    void pop() {
        if(st.top() == min.top()) min.pop();
        st.pop();
    }
    
    int top() { return st.top(); }
    
    int getMin() { return min.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */