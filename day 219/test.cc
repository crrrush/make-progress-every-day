

// 482. 密钥格式化
// https://leetcode.cn/problems/license-key-formatting/
// 给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。

// 我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。

// 返回 重新格式化的许可密钥 。

 

// 示例 1：

// 输入：S = "5F3Z-2e-9-w", k = 4
// 输出："5F3Z-2E9W"
// 解释：字符串 S 被分成了两个部分，每部分 4 个字符；
//      注意，两个额外的破折号需要删掉。

// 示例 2：

// 输入：S = "2-5g-3-J", k = 2
// 输出："2-5G-3J"
// 解释：字符串 S 被分成了 3 个部分，按照前面的规则描述，第一部分的字符可以少于给定的数量，其余部分皆为 2 个字符。

 

// 提示:

//     1 <= s.length <= 105
//     s 只包含字母、数字和破折号 '-'.
//     1 <= k <= 104


class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res;
        int cnt = 0;
        auto rit = s.rbegin();
        while(rit != s.rend())
        {
            if(*rit != '-')
            {
                if(*rit <= '9') res += *rit;
                else if(*rit >= 'a') res += (*rit - 32);
                else res += *rit;

                ++cnt;
                if(cnt == k)
                {
                    cnt = 0;
                    res += '-';
                } 
            }

            ++rit;
        }
        if(res.back() == '-') res.pop_back();

        reverse(res.begin(),res.end());

        return res;
    }
};