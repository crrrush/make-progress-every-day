/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-06-10 23:35:53
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-06-10 23:37:51
 * @FilePath: \every-little-progress\day 559\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 面试题 08.06. 汉诺塔问题
// https://leetcode.cn/problems/hanota-lcci/description/
// 在经典汉诺塔问题中，有 3 根柱子及 N 个不同大小的穿孔圆盘，盘子可以滑入任意一根柱子。一开始，所有盘子自上而下按升序依次套在第一根柱子上(即每一个盘子只能放在更大的盘子上面)。移动圆盘时受到以下限制:
// (1) 每次只能移动一个盘子;
// (2) 盘子只能从柱子顶端滑出移到下一根柱子;
// (3) 盘子只能叠在比它大的盘子上。

// 请编写程序，用栈将所有盘子从第一根柱子移到最后一根柱子。

// 你需要原地修改栈。

// 示例1:

//  输入：A = [2, 1, 0], B = [], C = []
//  输出：C = [2, 1, 0]
// 示例2:

//  输入：A = [1, 0], B = [], C = []
//  输出：C = [1, 0]
// 提示:

// A中盘子的数目不大于14个。


class Solution {
    void dfs(vector<int>& x, vector<int>& y, vector<int>& z, const int n)
    {
        if(1 == n)
        {
            z.push_back(x.back());
            x.pop_back();
            return;
        }

        dfs(x, z, y, n - 1);
        z.push_back(x.back());
        x.pop_back();
        dfs(y, x, z, n - 1);
    }
public:
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        dfs(A, B, C, A.size());
    }
};
