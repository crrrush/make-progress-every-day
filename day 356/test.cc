

// 面试题 10.01. 合并排序的数组
// https://leetcode.cn/problems/sorted-merge-lcci/description/
// 给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 编写一个方法，将 B 合并入 A 并排序。

// 初始化 A 和 B 的元素数量分别为 m 和 n。

// 示例:

// 输入:
// A = [1,2,3,0,0,0], m = 3
// B = [2,5,6],       n = 3

// 输出: [1,2,2,3,5,6]
// 说明:

// A.length == n + m

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        if(0 == n) return;
        if(0 == m) return A.swap(B);
        vector<int> all;
        int a = 0, b = 0;
        while(a < m && b < n)
        {
            if(A[a] <= B[b]) all.push_back(A[a++]);
            else all.push_back(B[b++]);
        }
        while(a < m) all.push_back(A[a++]);
        while(b < n) all.push_back(B[b++]);
        A.swap(all);
    }
};

// class Solution {
// public:
//     void merge(vector<int>& A, int m, vector<int>& B, int n) {
//         if(0 == n) return;
//         if(0 == m) return A.swap(B);
//         for(int i = 0;i < n;++i) A[m + i] = B[i];
//         int left = 0, right = m;
//         while(left < right && right < m + n)
//         {
//             if(A[left] <= A[right]) ++left;
//             else if(A[left] > A[right])
//             {
//                 swap(A[left], A[right]);
//                 if(right != m + n -1) ++right;
//             }
//         }
//     }
// };