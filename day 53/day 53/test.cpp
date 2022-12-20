#define _CRT_SECURE_NO_WARNINGS

//
//344. ��ת�ַ���
//https ://leetcode.cn/problems/reverse-string/
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
//
//
//
//ʾ�� 1��
//
//���룺s = ["h", "e", "l", "l", "o"]
//�����["o", "l", "l", "e", "h"]
//
//ʾ�� 2��
//
//���룺s = ["H", "a", "n", "n", "a", "h"]
//�����["h", "a", "n", "n", "a", "H"]
//
//
//
//��ʾ��
//
//1 <= s.length <= 105
//s[i] ���� ASCII ����еĿɴ�ӡ�ַ�
//




class Solution {
public:
    void reverseString(vector<char>& s) {
        //reverse(s.begin(), s.end());
        auto begin = s.begin();
        auto end = s.end() - 1;
        while (begin < end)
        {
            char tmp = *begin;
            *begin = *end;
            *end = tmp;
            ++begin;
            --end;
        }
    }
};

