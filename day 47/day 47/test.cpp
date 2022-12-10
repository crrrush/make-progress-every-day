<<<<<<< HEAD
#define _CRT_SECURE_NO_WARNINGS


//
//������ 16.15.��������
//https ://leetcode.cn/problems/master-mind-lcci/
//
//����������Ϸ��the game of master mind�����淨���¡�
//
//�������4���ۣ�ÿ���۷�һ������ɫ�����Ǻ�ɫ��R������ɫ��Y������ɫ��G������ɫ��B�������磬�����������RGGB 4�֣���1Ϊ��ɫ����2��3Ϊ��ɫ����4Ϊ��ɫ������Ϊ�û�������ͼ�³���ɫ��ϡ�����ȷ�������ܻ��YRGB��Ҫ�ǲ¶�ĳ���۵���ɫ������һ�Ρ����С���Ҫ��ֻ�¶���ɫ����λ�´��ˣ�����һ�Ρ�α���С���ע�⣬�����С��������롰α���С���
//
//����һ����ɫ���solution��һ���²�guess����дһ�����������ز��к�α���еĴ���answer������answer[0]Ϊ���еĴ�����answer[1]Ϊα���еĴ�����
//
//ʾ����
//
//���룺 solution = "RGBY", guess = "GGRR"
//�����[1, 1]
//���ͣ� ����1�Σ�α����1�Ρ�
//
//��ʾ��
//
//len(solution) = len(guess) = 4
//solution��guess������"R", "G", "B", "Y"��4���ַ�
//


int* masterMind(char* solution, char* guess, int* returnSize) {
    char mark[90] = "0";
    char* p = solution;
    while (*p)
    {
        mark[*p] = '1';
        p++;
    }

    int hit = 0;
    int had = 0;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (mark[guess[i]] == '1')
        {
            had++;
            if (guess[i] == solution[i])
                hit++;
        }
    }
    int* ret = (int*)malloc(sizeof(int) * 2);
    printf("%d %d\n", hit, had);
    ret[0] = hit;
    ret[1] = had - hit;
    *returnSize = 2;
    return ret;
}
*/


int* masterMind(char* solution, char* guess, int* returnSize) {
    char mark[90] = "0";
    char* p = solution;
    while (*p)
    {
        if (mark[*p] == 0)
            mark[*p] = '1';
        else
            mark[*p]++;
        p++;
    }

    int hit = 0;
    int had[90] = { 0 };
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (mark[guess[i]] != 0)
        {
            if (mark[guess[i]] > '0')
            {
                had[guess[i]]++;
                mark[guess[i]]--;
            }
            if (guess[i] == solution[i])
                hit++;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * 2);
    printf("%d\n", hit);
    printf("%d %d %d %d\n", had['G'], had['B'], had['Y'], had['R']);
    answer[0] = hit;
    answer[1] = had['G'] + had['B'] + had['Y'] + had['R'] - hit;
    *returnSize = 2;
    return answer;
}
=======
#define _CRT_SECURE_NO_WARNINGS


//
//������ 16.15.��������
//https ://leetcode.cn/problems/master-mind-lcci/
//
//����������Ϸ��the game of master mind�����淨���¡�
//
//�������4���ۣ�ÿ���۷�һ������ɫ�����Ǻ�ɫ��R������ɫ��Y������ɫ��G������ɫ��B�������磬�����������RGGB 4�֣���1Ϊ��ɫ����2��3Ϊ��ɫ����4Ϊ��ɫ������Ϊ�û�������ͼ�³���ɫ��ϡ�����ȷ�������ܻ��YRGB��Ҫ�ǲ¶�ĳ���۵���ɫ������һ�Ρ����С���Ҫ��ֻ�¶���ɫ����λ�´��ˣ�����һ�Ρ�α���С���ע�⣬�����С��������롰α���С���
//
//����һ����ɫ���solution��һ���²�guess����дһ�����������ز��к�α���еĴ���answer������answer[0]Ϊ���еĴ�����answer[1]Ϊα���еĴ�����
//
//ʾ����
//
//���룺 solution = "RGBY", guess = "GGRR"
//�����[1, 1]
//���ͣ� ����1�Σ�α����1�Ρ�
//
//��ʾ��
//
//len(solution) = len(guess) = 4
//solution��guess������"R", "G", "B", "Y"��4���ַ�
//


int* masterMind(char* solution, char* guess, int* returnSize) {
    char mark[90] = "0";
    char* p = solution;
    while (*p)
    {
        mark[*p] = '1';
        p++;
    }

    int hit = 0;
    int had = 0;
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (mark[guess[i]] == '1')
        {
            had++;
            if (guess[i] == solution[i])
                hit++;
        }
    }
    int* ret = (int*)malloc(sizeof(int) * 2);
    printf("%d %d\n", hit, had);
    ret[0] = hit;
    ret[1] = had - hit;
    *returnSize = 2;
    return ret;
}
*/


int* masterMind(char* solution, char* guess, int* returnSize) {
    char mark[90] = "0";
    char* p = solution;
    while (*p)
    {
        if (mark[*p] == 0)
            mark[*p] = '1';
        else
            mark[*p]++;
        p++;
    }

    int hit = 0;
    int had[90] = { 0 };
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        if (mark[guess[i]] != 0)
        {
            if (mark[guess[i]] > '0')
            {
                had[guess[i]]++;
                mark[guess[i]]--;
            }
            if (guess[i] == solution[i])
                hit++;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * 2);
    printf("%d\n", hit);
    printf("%d %d %d %d\n", had['G'], had['B'], had['Y'], had['R']);
    answer[0] = hit;
    answer[1] = had['G'] + had['B'] + had['Y'] + had['R'] - hit;
    *returnSize = 2;
    return answer;
}
>>>>>>> 55fb65a803a8cbd58ae50474c09a0a3033f55542
