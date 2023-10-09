/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-10-09 18:48:52
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-10-09 18:49:20
 * @FilePath: \every-little-progress\day 322\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 914. 卡牌分组
// https://leetcode.cn/problems/x-of-a-kind-in-a-deck-of-cards/description/
// 给定一副牌，每张牌上都写着一个整数。

// 此时，你需要选定一个数字 X，使我们可以将整副牌按下述规则分成 1 组或更多组：

// 每组都有 X 张牌。
// 组内所有的牌上都写着相同的整数。
// 仅当你可选的 X >= 2 时返回 true。

 

// 示例 1：

// 输入：deck = [1,2,3,4,4,3,2,1]
// 输出：true
// 解释：可行的分组是 [1,1]，[2,2]，[3,3]，[4,4]
// 示例 2：

// 输入：deck = [1,1,1,2,2,2,3,3]
// 输出：false
// 解释：没有满足要求的分组。

// 提示：

// 1 <= deck.length <= 104
// 0 <= deck[i] < 104


class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> hash;
        int max = 0;
        for(const auto& e : deck)
        {
            ++hash[e];
            if(hash[e] > max) max = hash[e];
        }

        int num = hash.begin()->second;
        if(num < 2) return false;

        for(int i = 2;i <= max;++i)
        {
            bool flag = true;
            for(const auto& [x, y] : hash) if(y % i) flag = false;

            if(flag) return true;
        }

        return false;
    }
};