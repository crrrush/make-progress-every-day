/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-18 23:34:29
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-18 23:35:34
 * @FilePath: \every-little-progress\day 537\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// LCR 170. 交易逆序对的总数
// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/description/
// 在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」。请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数。

 

// 示例 1:

// 输入：record = [9, 7, 5, 4, 6]
// 输出：8
// 解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)。
 

// 限制：

// 0 <= record.length <= 50000


class Solution {
    // vector<int> tmp;
    static int tmp[50010];

    int merge(vector<int>& nums, int l, int r) // 左闭右闭 逆序排列
    {
        if(l >= r) return 0;

        // int mid = l + (r - l) / 2;
        int mid = (l + r) >> 1;
        int cnt = merge(nums, l, mid);
        cnt += merge(nums, mid + 1, r);

        int p1 = l, p2 = mid + 1, i = 0;
        while(p1 <= mid && p2 <= r)
        {
            if(nums[p1] > nums[p2])
            {
                cnt += r - p2 + 1;
                tmp[i++] = nums[p1++];
            }
            else
            {
                tmp[i++] = nums[p2++];
            }
        }
        while(p1 <= mid) tmp[i++] = nums[p1++];
        while(p2 <= r) tmp[i++] = nums[p2++];
        i = 0;
        for(int j = l;j <= r;++j) nums[j] = tmp[i++];

        return cnt;
    }
public:
    // 1.暴力解法 超时
    // 2.归并排序
    int reversePairs(vector<int>& record) {
        // tmp.resize(record.size());
        return merge(record, 0, record.size() - 1);
    }
};

int Solution::tmp[50010];


