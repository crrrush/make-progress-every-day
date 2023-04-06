

// 求1+2+3+...+n
// 链接：https://www.nowcoder.com/questionTerminal/7a0da8fc483247ff8800059e12d7caf1
// 来源：牛客网

// 求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// 数据范围： 0<n≤2000<n≤200
// 进阶： 空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)
// 示例1
// 输入

// 5

// 输出

// 15

// 示例2
// 输入

// 1

// 输出

// 1



class Solution {
public:
    class N
    {
    public:
        N()
        {
            sum += num++;
        }
    };


    int Sum_Solution(int n) 
    {
        N answer[n];
        return sum;
    }

private:
    static int num;
    static int sum;
};


int Solution:: num = 1;
int Solution:: sum = 0;