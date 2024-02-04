#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int color[50];
long long table[50][50];

int main()
{
    for (int i = 0; i < 50; i++)
    {
        table[i][i] = 1;
        table[i][0] = 1;
        table[i][1] = i; 
    }

    for (int i = 2; i < 50; i++)
    {
        for (int j = 1; j < i; j++)
        {
            table[i][j] = table[i - 1][j] + table[i - 1][j - 1];
        }
    }

    int m, k, total = 0;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &color[i]);
        total += color[i];
    }
    scanf("%d", &k);

    double result = 0;
    for (int i = 0; i < m; i++)
    {
        if(color[i] >= k)       
        {
            double tmp = 1;
            for (int j = 0; j < k; j++)
            {
                tmp *= ((color[i] - j) / (double) (total - j));
            }
            result += tmp;
        }   
    }
    
    printf("%.18lf\n", result);
}
