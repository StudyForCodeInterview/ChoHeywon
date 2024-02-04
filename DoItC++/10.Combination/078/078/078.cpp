#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int table[15][15];

int main()
{
    for (int j = 1; j < 15; j++)
    {
        table[0][j] = j;
    }

    for (int i = 1; i < 15; i++)
    {
        table[i][1] = table[i - 1][1];
        for (int j = 2; j < 15; j++)
        {
            table[i][j] = table[i][j - 1] + table[i - 1][j];
        }
    }

    int t, k, n, res;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
    {
        scanf("%d", &k);
        scanf("%d", &n);
        printf("%d\n", table[k][n]);
    }
}
