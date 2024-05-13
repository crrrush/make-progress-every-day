

// 1419. 数青蛙
// https://leetcode.cn/problems/minimum-number-of-frogs-croaking/description/
// 给你一个字符串 croakOfFrogs，它表示不同青蛙发出的蛙鸣声（字符串 "croak" ）的组合。由于同一时间可以有多只青蛙呱呱作响，所以 croakOfFrogs 中会混合多个 “croak” 。

// 请你返回模拟字符串中所有蛙鸣所需不同青蛙的最少数目。

// 要想发出蛙鸣 "croak"，青蛙必须 依序 输出 ‘c’, ’r’, ’o’, ’a’, ’k’ 这 5 个字母。如果没有输出全部五个字母，那么它就不会发出声音。如果字符串 croakOfFrogs 不是由若干有效的 "croak" 字符混合而成，请返回 -1 。

 

// 示例 1：

// 输入：croakOfFrogs = "croakcroak"
// 输出：1 
// 解释：一只青蛙 “呱呱” 两次
// 示例 2：

// 输入：croakOfFrogs = "crcoakroak"
// 输出：2 
// 解释：最少需要两只青蛙，“呱呱” 声用黑体标注
// 第一只青蛙 "crcoakroak"
// 第二只青蛙 "crcoakroak"
// 示例 3：

// 输入：croakOfFrogs = "croakcrook"
// 输出：-1
// 解释：给出的字符串不是 "croak" 的有效组合。
 

// 提示：

// 1 <= croakOfFrogs.length <= 105
// 字符串中的字符只有 'c', 'r', 'o', 'a' 或者 'k'


class Solution {
    char prev(const char& ch)
    {
        switch(ch)
        {
        case 'k':
            return 'a';
            break;
        case 'a':
            return 'o';
            break;
        case 'o':
            return 'r';
            break;
        case 'r':
            return 'c';
            break;
        case 'c':
            return 'k';
            break;
        default:
            break;
        }
        return '0';
    }
public:
    // 另一种写法
    int minNumberOfFrogs(string croakOfFrogs) {
        if(croakOfFrogs.size() % 5 != 0) return -1;
        int hash[128] = {0};

        for(const auto& e : croakOfFrogs)
        {
            ++hash[e];

            char p = prev(e);

            if(e != 'c' && hash[p] == 0) return -1;

            if(hash[p] > 0) --hash[p];
        }
        // 如果前面任何一个不为空，返回-1
        if(hash['c'] || hash['r'] || hash['o'] || hash['a']) return -1;

        return hash['k'];
    }
};

// class Solution {
// public: // 一种写法
//     int minNumberOfFrogs(string croakOfFrogs) {
//         if(croakOfFrogs.size() % 5 != 0) return -1;
//         int hash[128] = {0};

//         int minFrogs = 0;
//         for(const auto& e : croakOfFrogs)
//         {
//             ++hash[e];
//             // 检查顺序是否有问题
//             switch(e)
//             {
//             case 'k':
//                 if(hash[e] > hash['a']) return -1;
//             case 'a':
//                 if(hash[e] > hash['o']) return -1;
//             case 'o':
//                 if(hash[e] > hash['r']) return -1;
//             case 'r':
//                 if(hash[e] > hash['c']) return -1;
//             }

//             if(e == 'k')
//             {
//                 minFrogs = max(hash['c'], minFrogs);
//                 --hash['c'];
//                 --hash['r'];
//                 --hash['o'];
//                 --hash['a'];
//                 --hash['k'];
//             }
//         }
//         // 检查叫声是否完整
//         if(hash['c'] != 0) return -1;

//         return minFrogs;
//     }
// };



