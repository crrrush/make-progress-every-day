#define _CRT_SECURE_NO_WARNINGS
//
//125. ��֤���Ĵ�
//https ://leetcode.cn/problems/valid-palindrome/description/
//
//����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�� ���Ĵ� ��
//
//��ĸ�����ֶ�������ĸ�����ַ���
//
//����һ���ַ��� s��������� ���Ĵ� ������ true �����򣬷��� false ��
//
//
//
//ʾ�� 1��
//
//���� : s = "A man, a plan, a canal: Panama"
//�����true
//���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ���
//
//ʾ�� 2��
//
//���룺s = "race a car"
//�����false
//���ͣ�"raceacar" ���ǻ��Ĵ���
//
//ʾ�� 3��
//
//���룺s = " "
//�����true
//���ͣ����Ƴ�����ĸ�����ַ�֮��s ��һ�����ַ��� "" ��
//���ڿ��ַ������ŷ��Ŷ���һ���������ǻ��Ĵ���
//
//
//
//��ʾ��
//
//1 <= s.length <= 2 * 105
//s ���ɿɴ�ӡ�� ASCII �ַ����



class Solution {
    void remove(string& s)
    {
        for (int i = 0; i < s.length(); ++i)
        {
            while ((s[i] < '0' || s[i] > '9') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && i < s.length())
                s.erase(i, 1);
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
    }
public:
    bool isPalindrome(string s)
    {
        remove(s);
        string rs(s);
        cout << rs << endl;
        reverse(s.begin(), s.end());
        cout << s << endl;
        if (strcmp(s.c_str(), rs.c_str()) == 0)
            return true;
        else
            return false;
    }
};