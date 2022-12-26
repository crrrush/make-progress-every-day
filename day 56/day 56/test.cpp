#define _CRT_SECURE_NO_WARNINGS

//136. ֻ����һ�ε�����
//https ://leetcode.cn/problems/single-number/
//
//����һ�� �ǿ� �������� nums ������ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ�ء�
//
//�������Ʋ�ʵ������ʱ�临�Ӷȵ��㷨����������⣬�Ҹ��㷨ֻʹ�ó�������ռ䡣
//
//
//
//ʾ�� 1 ��
//
//���룺nums = [2, 2, 1]
//�����1
//
//ʾ�� 2 ��
//
//���룺nums = [4, 1, 2, 1, 2]
//�����4
//
//ʾ�� 3 ��
//
//���룺nums = [1]
//�����1
//
//
//
//��ʾ��
//
//1 <= nums.length <= 3 * 104
//- 3 * 104 <= nums[i] <= 3 * 104
//����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ��������Ρ�


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            num ^= nums[i];

        return num;
    }
};
