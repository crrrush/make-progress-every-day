/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-25 13:50:44
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-25 13:51:11
 * @FilePath: \every-little-progress\day 338\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1046. 最后一块石头的重量
// https://leetcode.cn/problems/last-stone-weight/description/
// 有一堆石头，每块石头的重量都是正整数。

// 每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

// 如果 x == y，那么两块石头都会被完全粉碎；
// 如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
// 最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。

 

// 示例：

// 输入：[2,7,4,1,8,1]
// 输出：1
// 解释：
// 先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
// 再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
// 接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
// 最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
 

// 提示：

// 1 <= stones.length <= 30
// 1 <= stones[i] <= 1000

class Solution {
public:
    void smash(list<int>& ls)
    {
        auto xit = ls.begin();
        auto yit = ls.begin();
        auto it = ls.begin();
        
        int x = -1, y = -1;
        while(it != ls.end()) // 找y
        {
            if(*it > y)
            {
                yit = it;
                y = *it;
            }

            ++it;
        }

        it = ls.begin();
        while(it != ls.end()) // 找x
        {
            if(*it <= y && *it >= x && it != yit)
            {
                xit = it;
                x = *it;
            }

            ++it;
        }

        if(y > x) ls.push_back(y- x);

        ls.erase(xit);
        ls.erase(yit);

        
    }

    int lastStoneWeight(vector<int>& stones) {
        list<int> ls(stones.begin(), stones.end());
        while(ls.size() > 1) smash(ls);

        if(ls.empty())
            return 0;
        else 
            return ls.front();
    }

    void print(list<int>& l)
    {
        for(const auto& e : l) cout<<e<<" ";
        cout<<endl;
    }
};
