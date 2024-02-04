#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int table[1001][1001];

int main()
{
    int n, k, res;
    scanf_s("%d", &n);
    scanf_s("%d", &k);

    for (int i = 0; i <= n; i++)
    {
        table[i][1] = i;
        table[i][0] = 1;
        table[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
            table[i][j] %= 10007;
        }
    }

    printf("%d", table[n][k]);
}
