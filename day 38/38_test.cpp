#define _CRT_SECURE_NO_WARNINGS


//
//������ 05.06.����ת��
//https ://leetcode.cn/problems/convert-integer-lcci/description/
//
//����ת������дһ��������ȷ����Ҫ�ı伸��λ���ܽ�����Aת������B��
//
//ʾ��1 :
//
//���룺A = 29 ������0b11101��, B = 15������0b01111��
//�����2
//
//ʾ��2 :
//
//���룺A = 1��B = 2
//�����2
//
//��ʾ :
//
//A��B��Χ��[-2147483648, 2147483647]֮��
//


int convertInteger(int A, int B) {
    int count = 0;
    int n = 0;
    while (n < 31)
    {
        if ((A & (1 << n)) != (B & (1 << n)))
            count++;
        n++;
    }
    if ((A > 0 && B < 0) || (A < 0 && B > 0))
        count++;

    return count;
}