#define _CRT_SECURE_NO_WARNINGS



//ZJ16 ���еĺ� ţ��
//����
//
//���еĶ������£����еĵ�һ��Ϊn���Ժ����Ϊǰһ���ƽ�����������е�ǰm��ĺ͡�
//����������
//���������ж��飬ÿ��ռһ�У�����������n��n < 10000����m(m < 1000)��ɣ�n��m�ĺ�����ǰ������
//	���������
//	����ÿ���������ݣ���������еĺͣ�ÿ������ʵ��ռһ�У�Ҫ�󾫶ȱ���2λС����


#include<stdio.h>
#include<math.h>

int main()
{
    double n = 0;
    double m = 0;
    while (scanf("%lf %lf", &n, &m) != EOF)
    {
        double count = 0.0;
        while (m--)
        {
            count += n;
            n = pow(n, 0.5);
        }

        printf("%.2lf\n", count);
    }

    return 0;
}