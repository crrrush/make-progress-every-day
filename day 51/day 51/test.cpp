#define _CRT_SECURE_NO_WARNINGS

//
//541. ��ת�ַ��� II
//https ://leetcode.cn/problems/reverse-string-ii/
//
//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//
//���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
//
//
//
//ʾ�� 1��
//
//���룺s = "abcdefg", k = 2
//�����"bacdfeg"
//
//ʾ�� 2��
//
//���룺s = "abcd", k = 2
//�����"bacd"
//
//
//
//��ʾ��
//
//1 <= s.length <= 104
//s ����СдӢ�����
//1 <= k <= 104
//




class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        for (i = 0; i < s.length(); i += 2 * k)
        {
            if (s.length() - i > k)
            {
                reverse(s.begin() + i, s.begin() + i + k);
                //reverse(s.begin(), s.end());
            }
            else
            {
                reverse(s.begin() + i, s.end());
                //reverse(s.begin(), s.begin() + k);
            }
        }
        return s;
    }
};