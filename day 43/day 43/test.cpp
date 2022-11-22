#define _CRT_SECURE_NO_WARNINGS
//
//728. 自除数
//https ://leetcode.cn/problems/self-dividing-numbers/description/
//自除数 是指可以被它包含的每一位数整除的数。
//
//例如，128 是一个 自除数 ，因为 128 % 1 == 0，128 % 2 == 0，128 % 8 == 0。
//
//自除数 不允许包含 0 。
//
//给定两个整数 left 和 right ，返回一个列表，列表的元素是范围 [left, right] 内所有的 自除数 。
//
//
//
//示例 1：
//
//输入：left = 1, right = 22
//输出：[1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
//
//示例 2:
//
//输入：left = 47, right = 85
//输出：[48, 55, 66, 77]
//
//
//
//提示：
//
//1 <= left <= right <= 104
//
//

int my_pow(int n, int i)
{
    int ret = 1;
    while (i--)
    {
        ret *= n;
    }
    return ret;
}

int is_selfDivid(int num)
{
    int i = 0, n = 0;
    int flag = 1;
    while (my_pow(10, n) <= num)
    {
        i = (num / my_pow(10, n)) % 10;
        if (i == 0)
            return 0;

        if (num % i != 0)
            flag = 0;

        n++;
    }
    return flag;
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* ret = malloc(sizeof(int) * (right - left));
    *returnSize = 0;
    for (int i = left; i <= right; i++)
    {
        if (is_selfDivid(i))
        {
            ret[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return ret;
}