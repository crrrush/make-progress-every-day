
// 326. 3 的幂
// https://leetcode.cn/problems/power-of-three/

// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

// 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x

 

// 示例 1：

// 输入：n = 27
// 输出：true

// 示例 2：

// 输入：n = 0
// 输出：false

// 示例 3：

// 输入：n = 9
// 输出：true

// 示例 4：

// 输入：n = 45
// 输出：false

 

// 提示：

//     -231 <= n <= 231 - 1

 

// 进阶：你能不使用循环或者递归来完成本题吗？


class Solution {
public:
    bool isPowerOfThree(int n) {
        size_t num = n;
        if(num == 0) return false;
        bool flag = false;
        while(num)
        {
            if(num % 3 > 1) return false;
            else if(num % 3 == 1 && flag == false) flag = true;
            else if(num % 3 == 1 && flag == true) return false;

            num /= 3;
        }

        return flag;
    }
};

// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         size_t num = n;
//         while(num)
//         {
//             int mod = num % 3;
//             if(mod)
//             {
//                 cout <<num<<endl;
//                 num /= 3;
//                 cout <<num<<endl;


//                 if(num > 1) return false;
//                 else return true;
//             }

//             num /= 3;

//         }

//         return false;
//     }
// };