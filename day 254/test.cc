

// 1117. H2O 生成
// https://leetcode.cn/problems/building-h2o/
// 现在有两种线程，氧 oxygen 和氢 hydrogen，你的目标是组织这两种线程来产生水分子。

// 存在一个屏障（barrier）使得每个线程必须等候直到一个完整水分子能够被产生出来。

// 氢和氧线程会被分别给予 releaseHydrogen 和 releaseOxygen 方法来允许它们突破屏障。

// 这些线程应该三三成组突破屏障并能立即组合产生一个水分子。

// 你必须保证产生一个水分子所需线程的结合必须发生在下一个水分子产生之前。

// 换句话说:

// 如果一个氧线程到达屏障时没有氢线程到达，它必须等候直到两个氢线程到达。
// 如果一个氢线程到达屏障时没有其它线程到达，它必须等候直到一个氧线程和另一个氢线程到达。
// 书写满足这些限制条件的氢、氧线程同步代码。

 

// 示例 1:

// 输入: water = "HOH"
// 输出: "HHO"
// 解释: "HOH" 和 "OHH" 依然都是有效解。
// 示例 2:

// 输入: water = "OOHHHH"
// 输出: "HHOHHO"
// 解释: "HOHHHO", "OHHHHO", "HHOHOH", "HOHHOH", "OHHHOH", "HHOOHH", "HOHOHH" 和 "OHHOHH" 依然都是有效解。
 

// 提示：

// 3 * n == water.length
// 1 <= n <= 20
// water[i] == 'O' or 'H'
// 输入字符串 water 中的 'H' 总数将会是 2 * n 。
// 输入字符串 water 中的 'O' 总数将会是 n 。


#include <semaphore.h>

class H2O {
public:
    H2O():_H(0), _O(0) {
        pthread_mutex_init(&_mH, nullptr);
        pthread_mutex_init(&_mO, nullptr);
        sem_init(&_sH, 0, 2);
        sem_init(&_sO, 0, 1);
    }
    ~H2O()
    {
        pthread_mutex_destroy(&_mH);
        pthread_mutex_destroy(&_mO);
        sem_destroy(&_sH);
        sem_destroy(&_sO);
    }

    void P(sem_t& s)
    {
        sem_wait(&s);
    }

    void V(sem_t& s)
    {
        sem_post(&s);
    }

    void hydrogen(function<void()> releaseHydrogen) {
        P(_sH);
        pthread_mutex_lock(&_mH);

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        ++_H;
        if(_H == 2)
        {
            _H = 0;
            V(_sO);
        }
        
        
        pthread_mutex_unlock(&_mH);
    }

    void oxygen(function<void()> releaseOxygen) {
        P(_sO);
        pthread_mutex_lock(&_mO);

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        pthread_mutex_unlock(&_mO);
        V(_sH);
        V(_sH);
    }

private:
    pthread_mutex_t _mH;
    pthread_mutex_t _mO;

    sem_t _sH;
    sem_t _sO;

    int _H;
    int _O;
};

// mutex mtx;
// condition_variable_any cond;

// class H2O {
// public:
//     H2O():_H(0), _O(0) {}

//     void hydrogen(function<void()> releaseHydrogen) {
//         mtx.lock();
//         while(_H >= 2) cond.wait(mtx);
        
//         // releaseHydrogen() outputs "H". Do not change or remove this line.
//         releaseHydrogen();

//         ++_H;
//         if(_H + _O == 3) _H = _O = 0;

//         cond.notify_all();
//         mtx.unlock();
//     }

//     void oxygen(function<void()> releaseOxygen) {
//         mtx.lock();
//         while(_O >= 1) cond.wait(mtx);
//         // releaseOxygen() outputs "O". Do not change or remove this line.
//         releaseOxygen();

//         ++_O;
//         if(_H + _O == 3) _H = _O = 0;

//         cond.notify_all();
//         mtx.unlock();
//     }

// private:
//     int _H;
//     int _O;
// };
