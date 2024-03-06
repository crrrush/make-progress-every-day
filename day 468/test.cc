


// 1539. 第 k 个缺失的正整数
// https://leetcode.cn/problems/kth-missing-positive-number/description/
// 给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。

// 请你找到这个数组里第 k 个缺失的正整数。

 

// 示例 1：

// 输入：arr = [2,3,4,7,11], k = 5
// 输出：9
// 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。
// 示例 2：

// 输入：arr = [1,2,3,4], k = 2
// 输出：6
// 解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。
 

// 提示：

// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j] 
 

// 进阶：

// 你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？


class Solution {
public:
    // 二分
    int refind(vector<int>& arr, int left, int right, int k)
    {
        // cout<<"in?\n";
        int d = (arr[right] - arr[left] - 1) - (right - left - 1);
        // while(d >= k && right >= left)
        while(d >= k)
        {
            --right;
            d = (arr[right] - arr[left] - 1) - (right - left - 1);
        }
        return arr[right] + (k - d);
    }

    int findKthPositive(vector<int>& arr, int k) {
        if(k < arr[0]) return k;
        k -= (arr[0] - 1);
        int all_d =(arr.back() - arr.front()) - (arr.size() - 1);
        if(all_d < k) return arr.back() + k - all_d;

        int left = 0, right = arr.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2 + 1;
            // int ld = (arr[mid] - arr[left] - 1) - (mid - left - 1);// 两数之间相隔的数字数 - 两数位置之间的间隔数
            int ld = (arr[mid] - arr[left]) - (mid - left);// 两数之间相隔的数字数 - 两数位置之间的间隔数
            // cout<<"ld:"<<ld<<endl;
            if(ld >= k)
            {
                // cout<<left<<" "<<mid<<endl;
                return refind(arr, left, mid, k);
            }
            else
            {
                k -= ld;
                left = mid;
            }
        }

        return arr.back() + k;
    }
};

// class Solution {
// public:
//     // O(n)
//     int findKthPositive(vector<int>& arr, int k) {
//         int num = 1;
//         for(const auto& e : arr)
//         {
//             if(e - num > 0)
//             {
//                 // cout<<e<<"-"<<num<<endl;
//                 if(k > e - num) 
//                     k -= (e - num);
//                 else 
//                     return num + k - 1;
//             }

//             num = e + 1;
//         }

//         return arr.back() + k;
//     }
// };