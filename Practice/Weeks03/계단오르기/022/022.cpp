#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int stair[300] = { 0, };
int score[300][2];

int main()
{
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &stair[i]);
    }

    // 0은 아래 칸을 건너뛴 것, 1은 밟은 것
    // 0: 건너뛰었으니까 [i - 2][0] [i - 2][1] 중 max를 구하면 됨
    // 1: 아래를 밟았으니까 2칸 아래도 밟은 것은 못함, 즉 무조건 [i - 1][0]

    score[0][0] = stair[0];
    score[0][1] = stair[0];
    score[1][0] = stair[1];            
    score[1][1] = stair[0] + stair[1];

    for (int i = 2; i < N; i++)
    {
        score[i][0] = max(score[i - 2][1], score[i - 2][0]) + stair[i];
        score[i][1] = score[i - 1][0] + stair[i];
    }

    int res = max(score[N - 1][0], score[N - 1][1]);
    printf("%d", res);
}
