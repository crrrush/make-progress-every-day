

// 6. Z 字形变换
// https://leetcode.cn/problems/zigzag-conversion/description/
// 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

// 比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

// P   A   H   N
// A P L S I I G
// Y   I   R
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

// 请你实现这个将字符串进行指定行数变换的函数：

// string convert(string s, int numRows);
 

// 示例 1：

// 输入：s = "PAYPALISHIRING", numRows = 3
// 输出："PAHNAPLSIIGYIR"
// 示例 2：
// 输入：s = "PAYPALISHIRING", numRows = 4
// 输出："PINALSIGYAHRPI"
// 解释：
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
// 示例 3：

// 输入：s = "A", numRows = 1
// 输出："A"
 

// 提示：

// 1 <= s.length <= 1000
// s 由英文字母（小写和大写）、',' 和 '.' 组成
// 1 <= numRows <= 1000


class Solution {
public:
    string convert(string s, int numRows) {
        if(1 == numRows) return s;

        string ans;
        ans.reserve(s.size());
        int d = 2 * numRows - 2;

        // 先处理第一行
        for(int i = 0;i < s.size();i += d) ans += s[i];
        // 处理中间行
        for(int i = 1;i < numRows - 1;++i)
        {
            for(int j = i, n = 1;j < s.size();j += d)
            {
                ans.push_back(s[j]);
                if(n * d - i < s.size()) ans.push_back(s[n++ * d - i]);
            }
        }
        // 处理最后一行
        for(int i = numRows - 1;i < s.size();i += d) ans += s[i];

        return ans;
    }
};

// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if(1 == numRows) return s;

//         string ans;
//         ans.reserve(s.size());
//         int d = 2 * numRows - 2;
//         for(int i = 0;i < numRows;++i)
//         {
//             if(0 == i || numRows - 1 == i)
//             {
//                 for(int j = i;j < s.size();j += d) ans.push_back(s[j]);
//             }
//             else
//             {
//                 for(int j = i, n = 1;j < s.size();j += d)
//                 {
//                     ans.push_back(s[j]);
//                     if(n * d - i < s.size()) ans.push_back(s[n++ * d - i]);
//                 }
//             }
//         }

//         return ans;
//     }
// };



// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if(1 == numRows) return s;

//         vector<vector<char>> ZS;
//         int row = 0,col = 0;
//         for(int i = 0;i < s.size();++i)
//         {
//             if(col == 0) ZS.push_back(vector<char>(numRows, ' '));

//             if(row % (numRows - 1))
//             {
//                 ZS[row][numRows - (row % (numRows - 1)) - 1] = s[i];

//                 // ++i; // 字符迭代
//                 ++row; // 行迭代
//                 col = 0; // 列归0
//             }
//             else
//             {
//                 ZS[row][col++] = s[i];
//                 if(col == numRows)
//                 {
//                     ++row; // 行迭代
//                     col = 0; // 列迭代
//                 }
//                 // ++i; // 字符迭代
//             }
//         }
//         // for(const auto& e : ZS)
//         // {
//         //     for(const auto& r : e) cout<<r<<" ";
//         //     cout<<endl;
//         // }

//         s.clear();
//         for(int i = 0;i < numRows;++i)
//         {
//             for(int j = 0;j < ZS.size();++j) if(ZS[j][i] != ' ') s.push_back(ZS[j][i]);
//         }


//         return s;
//     }
// };

