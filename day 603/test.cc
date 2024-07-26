/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-07-26 12:52:28
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-07-26 12:54:36
 * @FilePath: \every-little-progress\day 603\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 295. 数据流的中位数
// https://leetcode.cn/problems/find-median-from-data-stream/description/
// 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。

// 例如 arr = [2,3,4] 的中位数是 3 。
// 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
// 实现 MedianFinder 类:

// MedianFinder() 初始化 MedianFinder 对象。

// void addNum(int num) 将数据流中的整数 num 添加到数据结构中。

// double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。

// 示例 1：

// 输入
// ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
// [[], [1], [2], [], [3], []]
// 输出
// [null, null, null, 1.5, null, 2.0]

// 解释
// MedianFinder medianFinder = new MedianFinder();
// medianFinder.addNum(1);    // arr = [1]
// medianFinder.addNum(2);    // arr = [1, 2]
// medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
// medianFinder.addNum(3);    // arr[1, 2, 3]
// medianFinder.findMedian(); // return 2.0
// 提示:

// -105 <= num <= 105
// 在调用 findMedian 之前，数据结构中至少有一个元素
// 最多 5 * 104 次调用 addNum 和 findMedian


class MedianFinder {
    int sz = 0;
    priority_queue<int, vector<int>, greater<int>> l_heap;
    priority_queue<int> b_heap;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        ++sz;
        if(!b_heap.empty() && num < b_heap.top())
        {
            b_heap.push(num);
            if(b_heap.size() > l_heap.size() + 1)
            {
                l_heap.push(b_heap.top());
                b_heap.pop();
            }
        }
        else
        {
            l_heap.push(num);
            if(l_heap.size() > b_heap.size() + 1)
            {
                b_heap.push(l_heap.top());
                l_heap.pop();
            }
        }
    }
    
    double findMedian() {
        if(sz % 2)
        {
            return l_heap.size() > b_heap.size() ? l_heap.top() : b_heap.top();
        }
        else
        {
            return (l_heap.top() + b_heap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

