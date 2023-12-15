/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2023-12-15 16:55:10
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2023-12-15 16:55:52
 * @FilePath: \every-little-progress\day 389\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 128. 库存管理 I
// https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/description/
// 仓库管理员以数组 stock 形式记录商品库存表。stock[i] 表示商品 id，可能存在重复。原库存表按商品 id 升序排列。现因突发情况需要进行商品紧急调拨，管理员将这批商品 id 提前依次整理至库存表最后。请你找到并返回库存表中编号的 最小的元素 以便及时记录本次调拨。

 

// 示例 1：

// 输入：stock = [4,5,8,3,4]
// 输出：3
// 示例 2：

// 输入：stock = [5,7,9,1,2]
// 输出：1
 

// 提示：

// 1 <= stock.length <= 5000
// -5000 <= stock[i] <= 5000
 

// 注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/


class Solution {
public:
    // 可以用二分，更快
    int stockManagement(vector<int>& stock) {
        int pos = 0;
        for(int i = 0;i < stock.size() - 1;++i) if(stock[i] > stock[i + 1]) pos = i + 1;
        return stock[0] < stock[pos] ? stock[0] : stock[pos];
    }
};