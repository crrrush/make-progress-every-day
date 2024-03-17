/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-03-17 12:08:04
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-03-17 12:08:26
 * @FilePath: \every-little-progress\day 479\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */



// LCR 034. 验证外星语词典
// https://leetcode.cn/problems/lwyVBB/description/
// 某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

// 给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

 

// 示例 1：

// 输入：words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// 输出：true
// 解释：在该语言的字母表中，'h' 位于 'l' 之前，所以单词序列是按字典序排列的。
// 示例 2：

// 输入：words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// 输出：false
// 解释：在该语言的字母表中，'d' 位于 'l' 之后，那么 words[0] > words[1]，因此单词序列不是按字典序排列的。
// 示例 3：

// 输入：words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// 输出：false
// 解释：当前三个字符 "app" 匹配时，第二个字符串相对短一些，然后根据词典编纂规则 "apple" > "app"，因为 'l' > '∅'，其中 '∅' 是空白字符，定义为比任何其他字符都小（更多信息）。
 

// 提示：

// 1 <= words.length <= 100
// 1 <= words[i].length <= 20
// order.length == 26
// 在 words[i] 和 order 中的所有字符都是英文小写字母。
 

// 注意：本题与主站 953 题相同： https://leetcode-cn.com/problems/verifying-an-alien-dictionary/

class Solution {
    bool cmp_less(const string& s1, const string& s2, unordered_map<char, int>& order)
    {
        auto it1 = s1.begin();
        auto it2 = s2.begin();
        while(it1 != s1.end() && it2 != s2.end())
        {
            if(*it1 != *it2) return order[*it1] < order[*it2];
            ++it1;
            ++it2;
        }
        if(it2 != s2.end()) return true;
        if(it1 == s1.end()) return true;

        return false;
    }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> hash;
        for(int i = 0;i < order.size();++i) hash[order[i]] = i;

        for(int i = 1;i < words.size();++i) if(!cmp_less(words[i - 1], words[i], hash)) return false;

        return true;
    }
};