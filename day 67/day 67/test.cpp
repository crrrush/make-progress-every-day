#define _CRT_SECURE_NO_WARNINGS

//��Сдת��
//���ӣ�https ://www.nowcoder.com/questionTerminal/4e089ee8966a4ed4b306f64e68d45264
//��Դ��ţ����
//
//ʵ����ĸ�Ĵ�Сдת�����������������
//
//�������� :
//
//�������룬ÿһ�������д��ĸ��
//
//
//
//�������:
//
//���ÿ�����������Ӧ��Сд��ĸ��
//
//ʾ��1
//����
//
//A
//B
//
//���
//
//a
//b
//
//
//��ע :
//
//�������������Ҫע�⡰�س���Ҳ����ĸ������Ҫ�����ա�(getchar())������ĸ��


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
