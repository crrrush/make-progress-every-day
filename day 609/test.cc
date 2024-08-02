/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-08-02 11:20:17
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-08-02 11:20:46
 * @FilePath: \every-little-progress\day 609\test.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


// 433. 最小基因变化
// https://leetcode.cn/problems/minimum-genetic-mutation/description/
// 基因序列可以表示为一条由 8 个字符组成的字符串，其中每个字符都是 'A'、'C'、'G' 和 'T' 之一。

// 假设我们需要调查从基因序列 start 变为 end 所发生的基因变化。一次基因变化就意味着这个基因序列中的一个字符发生了变化。

// 例如，"AACCGGTT" --> "AACCGGTA" 就是一次基因变化。
// 另有一个基因库 bank 记录了所有有效的基因变化，只有基因库中的基因才是有效的基因序列。（变化后的基因必须位于基因库 bank 中）

// 给你两个基因序列 start 和 end ，以及一个基因库 bank ，请你找出并返回能够使 start 变化为 end 所需的最少变化次数。如果无法完成此基因变化，返回 -1 。

// 注意：起始基因序列 start 默认是有效的，但是它并不一定会出现在基因库中。

 

// 示例 1：

// 输入：start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
// 输出：1
// 示例 2：

// 输入：start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
// 输出：2
// 示例 3：

// 输入：start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
// 输出：3
 

// 提示：

// start.length == 8
// end.length == 8
// 0 <= bank.length <= 10
// bank[i].length == 8
// start、end 和 bank[i] 仅由字符 ['A', 'C', 'G', 'T'] 组成

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(bank.empty()) return -1;
        unordered_map<string, bool> hash;
        for(const auto& e : bank) hash[e] = false;

        if(hash.end() == hash.find(endGene)) return -1;
        char gene[4] = { 'A', 'C', 'G', 'T'};
        queue<string> q;
        q.push(startGene);
        int cnt = 0;
        while(!q.empty())
        {
            ++cnt;
            int sz = q.size();
            for(int j = 0;j < sz;++j)
            {
                string tmp = q.front();
                q.pop();
                for(int i = 0;i < 8;++i)
                {
                    for(int k = 0;k < 4;++k)
                    {
                        if(tmp[i] == gene[k]) continue;

                        char org = tmp[i];
                        tmp[i] = gene[k];
                        if(tmp == endGene) return cnt;
                        // cout<<tmp<<" ";
                        if(hash.end() != hash.find(tmp) && !hash[tmp])
                        {
                            // cout<<tmp<<" in?\n";
                            q.push(tmp);
                            hash[tmp] = true;
                        }
                        tmp[i] = org;
                    }
                }
            }

        }

        return -1;
    }
};
