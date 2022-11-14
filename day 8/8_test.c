#define _CRT_SECURE_NO_WARNINGS

//面试题 16.15.珠玑妙算
//
//珠玑妙算游戏（the game of master mind）的玩法如下。
//
//计算机有4个槽，每个槽放一个球，颜色可能是红色（R）、黄色（Y）、绿色（G）或蓝色（B）。
// 例如，计算机可能有RGGB 4种（槽1为红色，槽2、3为绿色，槽4为蓝色）。
//作为用户，你试图猜出颜色组合。打个比方，你可能会猜YRGB。要是猜对某个槽的颜色，则算一次“猜中”；
//要是只猜对颜色但槽位猜错了，则算一次“伪猜中”。注意，“猜中”不能算入“伪猜中”。
//
//给定一种颜色组合solution和一个猜测guess，编写一个方法，
// 返回猜中和伪猜中的次数answer，其中answer[0]为猜中的次数，answer[1]为伪猜中的次数。
//
//来源：力扣（LeetCode）
//链接：https ://leetcode.cn/problems/master-mind-lcci
//著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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