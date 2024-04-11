/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-11 16:10:08
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-11 16:10:30
 * @FilePath: \every-little-progress\day 501\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 904. 水果成篮
// https://leetcode.cn/problems/fruit-into-baskets/description/
// 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

// 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

// 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
// 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
// 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
// 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

 

// 示例 1：

// 输入：fruits = [1,2,1]
// 输出：3
// 解释：可以采摘全部 3 棵树。
// 示例 2：

// 输入：fruits = [0,1,2,2]
// 输出：3
// 解释：可以采摘 [1,2,2] 这三棵树。
// 如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
// 示例 3：

// 输入：fruits = [1,2,3,2,2]
// 输出：4
// 解释：可以采摘 [2,3,2,2] 这四棵树。
// 如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
// 示例 4：

// 输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
// 输出：5
// 解释：可以采摘 [1,2,1,1,2] 这五棵树。
 

// 提示：

// 1 <= fruits.length <= 105
// 0 <= fruits[i] < fruits.length



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<tuple<int, int, int>> fmap(2, make_tuple(-1, -1, -1)); // 水果种类，[左边界，右边界]
        int left = 0, right = 0, maxL = -1, len = 0;
        while(right < fruits.size())
        {
            // 入窗口
            if(-1 == get<0>(fmap[0]))
            {
                get<0>(fmap[0]) = fruits[right];
                get<1>(fmap[0]) = get<2>(fmap[0]) = right;
            }
            else if(-1 == get<0>(fmap[1]) && fruits[right] != get<0>(fmap[0]))
            {
                get<0>(fmap[1]) = fruits[right];
                get<1>(fmap[1]) = get<2>(fmap[1]) = right;
            }
            else if(fruits[right] == get<0>(fmap[0]))
            {
                get<2>(fmap[0]) = right;
            }
            else if(fruits[right] == get<0>(fmap[1]))
            {
                get<2>(fmap[1]) = right;
            }
            else
            {
                // 旧水果出窗口，新水果入窗口
                if(get<2>(fmap[0]) < get<2>(fmap[1]))
                {
                    left = get<2>(fmap[0]) + 1;
                    get<0>(fmap[0]) = fruits[right];
                    get<1>(fmap[0]) = get<2>(fmap[0]) = right;
                }
                else
                {
                    left = get<2>(fmap[1]) + 1;
                    get<0>(fmap[1]) = fruits[right];
                    get<1>(fmap[1]) = get<2>(fmap[1]) = right;
                }
            }
            // cout<<get<0>(fmap[0])<<":"<<get<0>(fmap[1])<<"-";
            // cout<<left<<"~"<<right<<" ";
            ++right;
            len = right - left;

            if(maxL < len) maxL = len;
        }

        return maxL;
    }
};
