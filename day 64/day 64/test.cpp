#define _CRT_SECURE_NO_WARNINGS


//ʱ��ת��
//���ӣ�https://www.nowcoder.com/questionTerminal/c4ae7bcac7f9491b8be82ee516a94899
//��Դ��ţ����
//
//�������� seconds ������ת����Сʱ�����Ӻ��롣
//
//���ݷ�Χ�� 0 < seconds < 100000000 0 < seconds < 100000000
//
//	�������� :
//
//	һ�У�����һ����������������������
//
//
//
//�������:
//
//һ�У�������������������Ϊ����������Ӧ��Сʱ����������������������Ϊ�㣩���м���һ���ո������
//
//ʾ��1
//����
//
//3661
//
//���
//
//1 1 1

#include<stdio.h>

int main()//�������� seconds ������ת����Сʱ�����Ӻ��롣 
{
	int sec = 0;

	scanf("%d", &sec);

	if (sec >= 3600)
	{
		printf("%d ", sec / 3603);
		sec %= 3600;
	}
	else
		printf("%d ", 0);


	if (sec >= 60)
	{
		printf("%d ", sec / 60);
		sec %= 60;
	}
	else
		printf("0 ");

	printf("%d", sec);

	return 0;
}