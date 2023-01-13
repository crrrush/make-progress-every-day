#define _CRT_SECURE_NO_WARNINGS

//大小写转换
//链接：https ://www.nowcoder.com/questionTerminal/4e089ee8966a4ed4b306f64e68d45264
//来源：牛客网
//
//实现字母的大小写转换。多组输入输出。
//
//输入描述 :
//
//多组输入，每一行输入大写字母。
//
//
//
//输出描述:
//
//针对每组输入输出对应的小写字母。
//
//示例1
//输入
//
//A
//B
//
//输出
//
//a
//b
//
//
//备注 :
//
//多组输入过程中要注意“回车”也是字母，所以要“吸收”(getchar())掉该字母。


#include<stdio.h>


int main()
{
	char ap = 0;

	while ((ap = getchar()) != EOF)
	{
		putchar(ap + 32);
		getchar();
		printf("\n");
	}


	return 0;
}
