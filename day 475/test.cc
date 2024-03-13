/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-13 15:06:50
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-13 15:07:18
 * @FilePath: \every-little-progress\day 475\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 041. 数据流中的移动平均值
// https://leetcode.cn/problems/qIsx9U/
// 给定一个窗口大小和一个整数数据流，根据该滑动窗口的大小，计算滑动窗口里所有数字的平均值。

// 实现 MovingAverage 类：

// MovingAverage(int size) 用窗口大小 size 初始化对象。
// double next(int val) 成员函数 next 每次调用的时候都会往滑动窗口增加一个整数，请计算并返回数据流中最后 size 个值的移动平均值，即滑动窗口里所有数字的平均值。
 

// 示例：

// 输入：
// inputs = ["MovingAverage", "next", "next", "next", "next"]
// inputs = [[3], [1], [10], [3], [5]]
// 输出：
// [null, 1.0, 5.5, 4.66667, 6.0]

// 解释：
// MovingAverage movingAverage = new MovingAverage(3);
// movingAverage.next(1); // 返回 1.0 = 1 / 1
// movingAverage.next(10); // 返回 5.5 = (1 + 10) / 2
// movingAverage.next(3); // 返回 4.66667 = (1 + 10 + 3) / 3
// movingAverage.next(5); // 返回 6.0 = (10 + 3 + 5) / 3
 

// 提示：

// 1 <= size <= 1000
// -105 <= val <= 105
// 最多调用 next 方法 104 次
 

// 注意：本题与主站 346 题相同： https://leetcode-cn.com/problems/moving-average-from-data-stream/

class MovingAverage {
    list<int> _win;
    double sum = 0.0;
    int _sz;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):_sz(size) {}
    
    double next(int val) {
        _win.push_back(val);
        sum += val;
        if(_win.size() > _sz)
        {
            sum -= _win.front();
            _win.pop_front();
        }

        return sum / _win.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */