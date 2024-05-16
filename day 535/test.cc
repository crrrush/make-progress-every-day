

// LCR 159. 库存管理 III
// https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
// 仓库管理员以数组 stock 形式记录商品库存表，其中 stock[i] 表示对应商品库存余量。请返回库存余量最少的 cnt 个商品余量，返回 顺序不限。

 

// 示例 1：

// 输入：stock = [2,5,7,4], cnt = 1
// 输出：[2]
// 示例 2：

// 输入：stock = [0,2,3,6], cnt = 2
// 输出：[0,2] 或 [2,0]
 

// 提示：

// 0 <= cnt <= stock.length <= 10000

// 	0 <= stock[i] <= 10000

class Solution {
    int get_key(vector<int>& nums, const int& l, const int& r) // 左闭右闭 
    {
        return nums[rand() % (r - l + 1) + l];
    }

    void qsort(vector<int>& nums, const int l, const int r, int k)
    {
        if(l >= r) return;

        int key = get_key(nums, l, r);
        int left = l - 1, right = r + 1, i = l;

        while(i < right)
        {
            if(nums[i] < key)
                swap(nums[++left], nums[i++]);
            else if(nums[i] > key)
                swap(nums[--right], nums[i]);
            else
                ++i;
        }

        int a = left - l + 1;
        int b = right - left - 1;
        
        // cout<<key<<"-";for(const auto& e : nums) cout<<e<<" ";cout<<endl;

        if(a + b < k)
            return qsort(nums, right, r, k - a - b);
        else if(a > k)
            return qsort(nums, l, left, k);
        else
            return;
    }

public:
    // 快速选择排序
    vector<int> inventoryManagement(vector<int>& stock, int cnt) {
        if(0 == cnt) return vector<int>();
        srand((size_t)time(nullptr) ^ stock.size());
        qsort(stock, 0, stock.size() - 1, cnt);
        return vector<int>(stock.begin(), stock.begin() + cnt);
        // vector<int> ans(stock.begin(), stock.begin() + end_pos);
        // while(end_pos < cnt) ans.push_back(stock[end_pos++]); // 第 sz - cnt大的数的最左侧往右插入，直至足够cnt
        // return ans;
    }
}; 


// class Solution {
//     int get_key(vector<int>& nums, const int& l, const int& r) // 左闭右闭 
//     {
//         return nums[rand() % (r - l + 1) + l];
//     }

//     int qsort(vector<int>& nums, const int l, const int r, int k)
//     {
//         if(l >= r) return l;

//         int key = get_key(nums, l, r);
//         int left = l - 1, right = r + 1, i = l;

//         while(i < right)
//         {
//             if(nums[i] < key)
//                 swap(nums[++left], nums[i++]);
//             else if(nums[i] > key)
//                 swap(nums[--right], nums[i]);
//             else
//                 ++i;
//         }

//         int a = left - l + 1;
//         int b = right - left - 1;
        
//         // cout<<key<<"-";for(const auto& e : nums) cout<<e<<" ";cout<<endl;

//         if(c >= k)
//             return qsort(nums, right, r, k);
//         else if(b + c < k)
//             return qsort(nums, l, left, k - b - c);
//         else
//             return left + 1;
//     }

// public:
//     // 快速选择排序
//     vector<int> inventoryManagement(vector<int>& stock, int cnt) {
//         if(0 == cnt) return vector<int>();
//         srand((size_t)time(nullptr) ^ stock.size());
//         int end_pos = qsort(stock, 0, stock.size() - 1, stock.size() - cnt);

//         vector<int> ans(stock.begin(), stock.begin() + end_pos);
//         while(end_pos < cnt) ans.push_back(stock[end_pos++]); // 第 sz - cnt大的数的最左侧往右插入，直至足够cnt

//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<int> inventoryManagement(vector<int>& stock, int cnt) {
//         if(0 == cnt) return vector<int>();

//         priority_queue<int> pq(stock.begin(), stock.begin() + cnt);

//         for(int i = cnt;i < stock.size();++i)
//         {
//             if(stock[i] < pq.top())
//             {
//                 pq.pop();
//                 pq.push(stock[i]);
//             }
//         }

//         vector<int> ans;
//         ans.reserve(cnt);
//         while(!pq.empty())
//         {
//             ans.push_back(pq.top());
//             pq.pop();
//         }

//         return ans;
//     }
// };

