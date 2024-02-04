#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

long long table[31][31];

int main()
{
    for (int i = 0; i < 31; i++)
    {
        table[0][i] = 1;
        table[i][i] = 1;
        table[1][i] = i;
    }

    for (int i = 2; i < 31; i++)
    {
        for (int j = i; j < 31; j++)
        {
            table[i][j] = table[i][j - 1] + table[i - 1][j - 1];
        }
    }

    long long t, n, m;
    scanf("%lld", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &n);
        scanf("%lld", &m);
        printf("%lld\n", table[n][m]);
    }
}
