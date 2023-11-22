#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define dfMAX 9223372036854775806
long long mins[100][100];

int main()
{
    int N, M; 
    scanf("%d", &N);
    scanf("%d", &M);
    fill_n(&mins[0][0], 10000, dfMAX);
    for (int i = 0; i < 100; i++)
        mins[i][i] = 0;
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        if (mins[a - 1][b - 1] > c) mins[a - 1][b - 1] = c;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if(mins[j][i] != dfMAX && mins[i][k] != dfMAX)
                    mins[j][k] = min(mins[j][k], mins[j][i] + mins[i][k]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mins[i][j] != dfMAX)
                printf("%lld ", mins[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

