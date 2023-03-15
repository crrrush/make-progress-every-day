

// 打印从1到最大的n位数
// 链接：https://www.nowcoder.com/questionTerminal/4436c93e568c48f6b28ff436173b997f
// 来源：牛客网

// 输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
// 1. 用返回一个整数列表来代替打印
// 2. n 为正整数，0 < n <= 5
// 示例1
// 输入

// 1

// 输出

// [1,2,3,4,5,6,7,8,9]

int* printNumbers(int n, int* returnSize ) {
    // write code here
    static int arr[100000] = { 0 };
    int num = 1;
    int i = 0;
    for(i = 0;i < n;i++)
    {
        num *= 10;
    }
     
    for(i = 0;i < num - 1;i++)
    {
        (*returnSize)++;
        arr[i] = i+1;
    }
    return arr;
}