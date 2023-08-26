/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-08-26 20:57:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-08-26 20:58:52
 * @FilePath: \every-little-progress\day 280\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1688. 比赛中的配对次数
// https://leetcode.cn/problems/count-of-matches-in-tournament/
// 给你一个整数 n ，表示比赛中的队伍数。比赛遵循一种独特的赛制：

// 如果当前队伍数是 偶数 ，那么每支队伍都会与另一支队伍配对。总共进行 n / 2 场比赛，且产生 n / 2 支队伍进入下一轮。
// 如果当前队伍数为 奇数 ，那么将会随机轮空并晋级一支队伍，其余的队伍配对。总共进行 (n - 1) / 2 场比赛，且产生 (n - 1) / 2 + 1 支队伍进入下一轮。
// 返回在比赛中进行的配对次数，直到决出获胜队伍为止。

 

// 示例 1：

// 输入：n = 7
// 输出：6
// 解释：比赛详情：
// - 第 1 轮：队伍数 = 7 ，配对次数 = 3 ，4 支队伍晋级。
// - 第 2 轮：队伍数 = 4 ，配对次数 = 2 ，2 支队伍晋级。
// - 第 3 轮：队伍数 = 2 ，配对次数 = 1 ，决出 1 支获胜队伍。
// 总配对次数 = 3 + 2 + 1 = 6
// 示例 2：

// 输入：n = 14
// 输出：13
// 解释：比赛详情：
// - 第 1 轮：队伍数 = 14 ，配对次数 = 7 ，7 支队伍晋级。
// - 第 2 轮：队伍数 = 7 ，配对次数 = 3 ，4 支队伍晋级。 
// - 第 3 轮：队伍数 = 4 ，配对次数 = 2 ，2 支队伍晋级。
// - 第 4 轮：队伍数 = 2 ，配对次数 = 1 ，决出 1 支获胜队伍。
// 总配对次数 = 7 + 3 + 2 + 1 = 13
 

// 提示：

// 1 <= n <= 200

class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while(n > 1)
        {
            if(n % 2)
            {
                cnt += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
            else
            {
                cnt += n / 2;
                n = n / 2;
            }
        }

        return cnt;
    }
};