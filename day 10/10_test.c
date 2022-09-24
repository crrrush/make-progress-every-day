#define _CRT_SECURE_NO_WARNINGS


//给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
//
//
//
//示例 1:
//
//输入: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
//输出 : [5, 6, 7, 1, 2, 3, 4]
//解释 :
//    向右轮转 1 步 : [7, 1, 2, 3, 4, 5, 6]
//    向右轮转 2 步 : [6, 7, 1, 2, 3, 4, 5]
//    向右轮转 3 步 : [5, 6, 7, 1, 2, 3, 4]
//
//    示例 2 :
//
//    输入：nums = [-1, -100, 3, 99], k = 2
//    输出：[3, 99, -1, -100]
//    解释 :
//    向右轮转 1 步 : [99, -1, -100, 3]
//    向右轮转 2 步 : [3, 99, -1, -100]
//
//    来源：力扣（LeetCode）
//    链接：https ://leetcode.cn/problems/rotate-array
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


void reverse(int* pa, int sz)
{
    assert(pa);
    int sta = 0;
    int end = sz - 1;
    while (sta < end)
    {
        int tmp = pa[sta];
        pa[sta] = pa[end];
        pa[end] = tmp;
        sta++;
        end--;
    }
}



void rotate(int* nums, int numsSize, int k) {
    /*
    //方法一：
    k %= numsSize;
    while(k--)
    {
        int tmp = nums[numsSize - 1];
        for(int i = numsSize - 1;i > 0;--i)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = tmp;
    }
    //超出时间限制
    */

    /*
    k %= numsSize;//方法二：   可优化空间复杂度
    int* tmp = malloc(numsSize * sizeof(int));
    if(tmp == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    int i = 0;
    for(i = 0;i < numsSize;++i)
    {
        if(i < k)
        {
            tmp[i] = nums[numsSize - k + i];
        }
        else
        {
            tmp[i] = nums[i - k];
        }
    }
    for(i = 0;i < numsSize;++i)
    {
        nums[i] = tmp[i];
    }
    free(tmp);
    tmp = NULL;
    */

    //方法三  
    k %= numsSize;
    reverse(nums + numsSize - k, k);
    reverse(nums, numsSize - k);
    reverse(nums, numsSize);

}
