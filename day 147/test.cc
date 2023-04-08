
// 数组中出现次数超过一半的数字


// 链接：https://www.nowcoder.com/questionTerminal/e8a1b01a2df14cb2b228b30ee6a92163
// 来源：牛客网

// 给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

// 数据范围：n≤50000n≤50000，数组中元素的值 0≤val≤100000≤val≤10000
// 要求：空间复杂度：O(1)O(1)，时间复杂度 O(n)O(n)

// 输入描述:

// 保证数组输入非空，且保证有解


// 示例1
// 输入

// [1,2,3,2,2,2,5,4,2]

// 输出

// 2

// 示例2
// 输入

// [3,3,3,3,2,2,2]

// 输出

// 3

// 示例3
// 输入

// [1]

// 输出

// 1


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int i = 0;
        int max = numbers[0], min = numbers[0];
        for(i = 1;i < numbers.size();++i)
        {
            if(max < numbers[i])
                max = numbers[i];
            if(min > numbers[i])
                min = numbers[i];
        }
        vector<int> v;
        v.resize(max - min + 1);

        for(i = 0;i < numbers.size();++i)
        {
            cout << (numbers[i] - min) << " ";
            ++v[numbers[i] - min];
        }

        cout << endl;
        for(i = 0;i < v.size();++i)
        {
            cout << v[i] << " ";
            if(v[i] > (numbers.size() / 2))
                return i + min;
        }

        return numbers[0];
    }
};