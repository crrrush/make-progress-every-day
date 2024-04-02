/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-02 13:27:09
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-02 13:27:34
 * @FilePath: \every-little-progress\day 494\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 179. 查找总价格为目标值的两个商品
// https://leetcode.cn/problems/he-wei-sde-liang-ge-shu-zi-lcof/description/

// 购物车内的商品价格按照升序记录于数组 price。请在购物车中找到两个商品的价格总和刚好是 target。若存在多种情况，返回任一结果即可。

// 示例 1：

// 输入：price = [3, 9, 12, 15], target = 18
// 输出：[3,15] 或者 [15,3]
// 示例 2：

// 输入：price = [8, 21, 27, 34, 52, 66], target = 61
// 输出：[27,34] 或者 [34,27]
 

// 提示：

// 1 <= price.length <= 10^5
// 1 <= price[i] <= 10^6
// 1 <= target <= 2*10^6


class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1;
        // vector<int> res;
        while(left < right)// 双指针相撞 O(n)
        {
            if(price[left] + price[right] > target)
                --right;
            else if(price[left] + price[right] < target)
                ++left;
            else
                return vector<int>({price[left], price[right]});// 列表初始化
            // else
            // {
            //     res.push_back(price[left]);
            //     res.push_back(price[right]);
            //     break;
            // }
        }

        return vector<int>();
        // return res;
    }
};