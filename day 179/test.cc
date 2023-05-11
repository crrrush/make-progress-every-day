
// 1122. 数组的相对排序


// https://leetcode.cn/problems/relative-sort-array/
// 给你两个数组，arr1 和 arr2，arr2 中的元素各不相同，arr2 中的每个元素都出现在 arr1 中。

// 对 arr1 中的元素进行排序，使 arr1 中项的相对顺序和 arr2 中的相对顺序相同。未在 arr2 中出现过的元素需要按照升序放在 arr1 的末尾。

 

// 示例 1：

// 输入：arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
// 输出：[2,2,2,1,4,3,3,9,6,7,19]

// 示例  2:

// 输入：arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
// 输出：[22,28,8,6,17,44]

 

// 提示：

//     1 <= arr1.length, arr2.length <= 1000
//     0 <= arr1[i], arr2[i] <= 1000
//     arr2 中的元素 arr2[i]  各不相同 
//     arr2 中的每个元素 arr2[i] 都出现在 arr1 中



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> res;
        vector<int> hash;
        hash.resize(1001);

        for(auto& e : arr1)
            ++hash[e];
        
        for(auto& e : arr2)
        {
            while(hash[e] > 1)
            {
                res.push_back(e);
                --hash[e];
            }
            --hash[e];
            res.push_back(e);
        }

        for(int i = 0;i < hash.size();++i)
        {
            while(hash[i]-- > 0)
                res.push_back(i);
        }

        return res;
    }
};