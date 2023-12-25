/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-25 14:02:45
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-25 14:03:15
 * @FilePath: \every-little-progress\day 399\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 2022. 将一维数组转变成二维数组
// https://leetcode.cn/problems/convert-1d-array-into-2d-array/description/
// 给你一个下标从 0 开始的一维整数数组 original 和两个整数 m 和  n 。你需要使用 original 中 所有 元素创建一个 m 行 n 列的二维数组。

// original 中下标从 0 到 n - 1 （都 包含 ）的元素构成二维数组的第一行，下标从 n 到 2 * n - 1 （都 包含 ）的元素构成二维数组的第二行，依此类推。

// 请你根据上述过程返回一个 m x n 的二维数组。如果无法构成这样的二维数组，请你返回一个空的二维数组。

 

// 示例 1：


// 输入：original = [1,2,3,4], m = 2, n = 2
// 输出：[[1,2],[3,4]]
// 解释：
// 构造出的二维数组应该包含 2 行 2 列。
// original 中第一个 n=2 的部分为 [1,2] ，构成二维数组的第一行。
// original 中第二个 n=2 的部分为 [3,4] ，构成二维数组的第二行。
// 示例 2：

// 输入：original = [1,2,3], m = 1, n = 3
// 输出：[[1,2,3]]
// 解释：
// 构造出的二维数组应该包含 1 行 3 列。
// 将 original 中所有三个元素放入第一行中，构成要求的二维数组。
// 示例 3：

// 输入：original = [1,2], m = 1, n = 1
// 输出：[]
// 解释：
// original 中有 2 个元素。
// 无法将 2 个元素放入到一个 1x1 的二维数组中，所以返回一个空的二维数组。
// 示例 4：

// 输入：original = [3], m = 1, n = 2
// 输出：[]
// 解释：
// original 中只有 1 个元素。
// 无法将 1 个元素放满一个 1x2 的二维数组，所以返回一个空的二维数组。
 

// 提示：

// 1 <= original.length <= 5 * 104
// 1 <= original[i] <= 105
// 1 <= m, n <= 4 * 104


class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));
        int pos = 0, i = 0;
        for(;i < m && pos < original.size();++i)
        {
            for(int j = 0;j < n;++j)
            {
                if(pos < original.size())
                    res[i][j] = original[pos++];
                else
                    return vector<vector<int>>();
            }
        }
        if(i < m || pos < original.size()) return vector<vector<int>>();
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
//         vector<vector<int>> res;
//         int pos = 0;
//         for(int i = 0;i < m && pos < original.size();++i)
//         {
//             vector<int> tmp;
//             for(int j = 0;j < n;++j) if(pos < original.size()) tmp.push_back(original[pos++]);
//             if(tmp.size() < n) return vector<vector<int>>();
//             res.push_back(tmp);
//         }
//         if(res.size() < m || pos < original.size()) return vector<vector<int>>();
//         return res;
//     }
// };