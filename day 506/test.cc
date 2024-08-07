/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-04-17 11:21:25
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-04-17 11:21:47
 * @FilePath: \every-little-progress\day 506\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 1704. 判断字符串的两半是否相似
// https://leetcode.cn/problems/determine-if-string-halves-are-alike/
// 给你一个偶数长度的字符串 s 。将其拆分成长度相同的两半，前一半为 a ，后一半为 b 。

// 两个字符串 相似 的前提是它们都含有相同数目的元音（'a'，'e'，'i'，'o'，'u'，'A'，'E'，'I'，'O'，'U'）。注意，s 可能同时含有大写和小写字母。

// 如果 a 和 b 相似，返回 true ；否则，返回 false 。

 

// 示例 1：

// 输入：s = "book"
// 输出：true
// 解释：a = "bo" 且 b = "ok" 。a 中有 1 个元音，b 也有 1 个元音。所以，a 和 b 相似。
// 示例 2：

// 输入：s = "textbook"
// 输出：false
// 解释：a = "text" 且 b = "book" 。a 中有 1 个元音，b 中有 2 个元音。因此，a 和 b 不相似。
// 注意，元音 o 在 b 中出现两次，记为 2 个。
 

// 提示：

// 2 <= s.length <= 1000
// s.length 是偶数
// s 由 大写和小写 字母组成


class Solution {
public:
    bool halvesAreAlike(string s) {
        // string ls = s.substr(0, s.length() / 2);
        // string rs = s.substr(s.length() / 2, s.length() / 2);
        int left = 0, right = s.length() / 2;

        char vowel[10] = {'a','e','i','o','u','A','E','I','O','U'};
        unordered_set<char> hash;
        for(const auto& e : vowel) hash.insert(e);

        int lv = 0, rv = 0;
        for(int i = left;i < right;++i) if(hash.find(s[i]) != hash.end()) ++lv;
        for(int i = right;i < s.size();++i) if(hash.find(s[i]) != hash.end()) ++rv;

        return lv == rv;
    }
};