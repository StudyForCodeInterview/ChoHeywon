/*
BAEKJOON 11659

문제:
수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력:
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 
둘째 줄에는 N개의 수가 주어진다. 수는 1,000보다 작거나 같은 자연수이다. 
셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력:
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int num_cnt = 0;
    int sum_cnt = 0;
    scanf("%d", &num_cnt);
    scanf("%d", &sum_cnt);

    num_cnt++;
    int num = 0;
    int* sumArray = new int[num_cnt];
    sumArray[0] = 0;
    for (int i = 1; i < num_cnt; i++)
    {
        scanf("%d", &num);
        sumArray[i] = sumArray[i - 1] + num;
    }

    int* startArray = new int[sum_cnt];
    int* endArray = new int[sum_cnt];
    for (int i = 0; i < sum_cnt; i++)
    {
        scanf("%d", &startArray[i]);
        scanf("%d", &endArray[i]);
    }

    for (int i = 0; i < sum_cnt; i++)
    {
        printf("%d\n", 
            sumArray[endArray[i]] - sumArray[startArray[i] - 1]);
    }
}

