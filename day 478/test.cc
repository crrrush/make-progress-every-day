/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-16 12:49:05
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-16 12:49:41
 * @FilePath: \every-little-progress\day 478\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 075. 数组的相对排序
// https://leetcode.cn/problems/0H97ZC/
// 给定两个数组，arr1 和 arr2，

// arr2 中的元素各不相同
// arr2 中的每个元素都出现在 arr1 中
// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

// 示例：

// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// 输出：[2,2,2,1,4,3,3,9,6,7,19]
 

// 提示：

// 1 <= arr1.length, arr2.length <= 1000
// 0 <= arr1[i], arr2[i] <= 1000
// arr2 中的元素 arr2[i] 各不相同
// arr2 中的每个元素 arr2[i] 都出现在 arr1 中
 

// 注意：本题与主站 1122 题相同：https://leetcode-cn.com/problems/relative-sort-array/ 


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> hash;
        for(const auto& e : arr2) hash.insert(make_pair(e, 0));

        list<int> l;
        for(const auto& e : arr1)
        {
            auto it = hash.find(e);
            if(it != hash.end())
            {
                ++(it->second);
            }
            else
            {
                auto lit = l.begin();
                while(lit != l.end())
                {
                    if(*lit >= e) break;
                    ++lit;
                }
                l.insert(lit, e);
            }
        }

        arr1.clear();
        for(const auto& e : arr2)
        {
            while(hash[e]--) arr1.push_back(e);
        }

        for(const auto& e : l) arr1.push_back(e);

        return arr1;
    }
};