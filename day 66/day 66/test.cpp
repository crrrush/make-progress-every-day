#define _CRT_SECURE_NO_WARNINGS

//���������ε��ܳ������
//���ӣ�https ://www.nowcoder.com/questionTerminal/109a44d649a142d483314e8a57e2c710
//��Դ��ţ����
//
//���ݸ�����������3����a, b, c�����������ε��ܳ��������
//
//���ݷ�Χ�� 0 < a, b, c��100000 0 < a, b, c��100000
//
//	�������� :
//
//һ�У�������3���ߣ��ܹ��������Σ����м���һ���ո������
//
//
//
//�������:
//
//һ�У��������ܳ��������������λС�������м���һ���ո��������������ʽ������������
//
//ʾ��1
//����
//
//3 3 3
//
//���
//
//circumference = 9.00 area = 3.90


#include<stdio.h>

#include<math.h>
int main()
{
	double a = 0.0, b = 0.0, c = 0.0;

	double circumference = 0.0;
	double area = 0.0;

	//����
	scanf("%lf %lf %lf", &a, &b, &c);
	//����
	circumference = a + b + c;
	double p = circumference / 2;
	area = sqrt(p * (p - a) * (p - b) * (p - c));
	//���
	printf("circumference=%.2lf area=%.2lf", circumference, area);

	return 0;
}
