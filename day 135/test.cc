

// 数字在升序数组中出现的次数
// 链接：https://www.nowcoder.com/questionTerminal/70610bf967994b22bb1c26f9ae901fa2
// 来源：牛客网

// 给定一个长度为 n 的非降序数组和一个非负数整数 k ，要求统计 k 在数组中出现的次数

// 数据范围：0≤n≤1000,0≤k≤1000≤n≤1000,0≤k≤100，数组中每个元素的值满足 0≤val≤1000≤val≤100
// 要求：空间复杂度 O(1)O(1)，时间复杂度 O(logn)O(logn)
// 示例1
// 输入

// [1,2,3,3,3,3,4,5],3

// 输出

// 4

// 示例2
// 输入

// [1,3,4,5],6

// 输出

// 0

/**
 * 
 * @param data int整型一维数组 
 * @param dataLen int data数组长度
 * @param k int整型 
 * @return int整型
 *
 * C语言声明定义全局变量请加上static，防止重复定义
 */

void FindK(int* a,int left, int right, int* n, int k)
{
    if(left > right)
        return;
    
    
    
    int mid = (left + right) / 2;
    if(a[mid] < k)
    {
        FindK(a,mid + 1 , right,n ,k);
        return;
    }
    else if(a[mid] > k)
    {
        FindK(a,left , mid - 1,n ,k);
        return;
    }
    else
    {
        (*n)++;
        int back = mid - 1;
        int forward = mid + 1;
        while(a[back] == k ||a[forward] == k)
        {
            if(a[back] == k)
            {
                (*n)++;
                back--;
            }
            if(a[forward] == k)
            {
                (*n)++;
                forward++;
            }
        }
    }
}

int GetNumberOfK(int* data, int dataLen, int k ) {
    int count = 0;
    
    FindK(data,0 , dataLen - 1, &count, k);
    
    return count;
}


/*
int GetNumberOfK(int* data, int dataLen, int k ) {
    int count = 0;
    for(int i = 0;i < dataLen;++i)
    {
        if(data[i] == k)
            ++count;
    }
    return count;
}*/