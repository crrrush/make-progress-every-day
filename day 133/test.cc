
// 旋转数组的最小数字

// 链接：https://www.nowcoder.com/questionTerminal/9f3231a991af4f55b95579b44b7a01ba
// 来源：牛客网

// 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。

// 数据范围：1≤n≤100001≤n≤10000，数组中任意元素的值: 0≤val≤100000≤val≤10000
// 要求：空间复杂度：O(1)O(1) ，时间复杂度：O(logn)O(logn)
// 示例1
// 输入

// [3,4,5,1,2]

// 输出

// 1

// 示例2
// 输入

// [3,100,200,3]

// 输出

// 3

/**
 * 
 * @param rotateArray int整型一维数组 
 * @param rotateArrayLen int rotateArray数组长度
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */
int minNumberInRotateArray(int* rotateArray, int rotateArrayLen ) {
    int left = 0;
    int right = rotateArrayLen - 1;
    while(left < right)
    {
        int mid = (left + right)/2;
         if(mid == left || mid == right)
        {
                break;
        }
        while(rotateArray[mid] == rotateArray[right])
        {
            right--;
            mid = (left + right)/2;
        }
        if(rotateArray[mid] > rotateArray[right])
        {
            left = mid;
            mid = (left + right)/2;
            if(mid == left || mid == right)
            {
                break;
            }
        }
        else if(rotateArray[mid] < rotateArray[right])
        {
            right = mid;
            mid = (left + right)/2;
            if(mid == left || mid == right)
            {
                break;
            }
        }
    }
    if(rotateArray[left] < rotateArray[right])
        return rotateArray[left];
    else
        return rotateArray[right];
    /*int prev = 0,cur = 1;
    while(cur < rotateArrayLen)
    {
        if(rotateArray[prev] <= rotateArray[cur])
        {
            ++cur;
            ++prev;
        }
        else
        {
            return rotateArray[cur];
        }
    }
    return rotateArray[0];*/
    
}