

// 公务员面试

// 链接：https://www.nowcoder.com/questionTerminal/f3a134908d5b41869f14f58307008a97
// 来源：牛客网

// 公务员面试现场打分。有7位考官，从键盘输入若干组成绩，每组7个分数（百分制），去掉一个最高分和一个最低分，输出每组的平均成绩。
// （注：本题有多组输入）

// 输入描述:

// 每一行，输入7个整数（0~100），代表7个成绩，用空格分隔。



// 输出描述:

// 每一行，输出去掉最高分和最低分的平均成绩，小数点后保留2位，每行输出后换行。

// 示例1
// 输入

// 99 45 78 67 72 88 60

// 输出

// 73.00


#include<stdio.h>

int main()
{
	int arr[7] = { 0 };


	int i = 0, j = 0;

	while (scanf("%d",&arr[j++]) != EOF)
	{
    	int Max = 0, Min = 101;
        
		if (j < 7)
			continue;

		//获取最大值与最小值
		for (i = 0; i < 7; i++)
		{
			if (Max < arr[i])
				Max = arr[i];
		}
		for (i = 0; i < 7; i++)
		{
			if (Min > arr[i])
				Min = arr[i];
		}

		float Sum = 0.0;
		for (i = 0; i < 7; i++)//获取总数
		{
			Sum += arr[i];
		}

		printf("%.2f\n", (Sum - Max - Min) / 5.0);

		j = 0;
	}

	
	return 0;
}