#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define dfMAX 2147483647
int arr[100][100];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    fill_n(&arr[0][0], 10000, dfMAX);
    for (int i = 0; i < 100; i++)
        arr[i][i] = 0;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        arr[A - 1][B - 1] = 1;
        arr[B - 1][A - 1] = 1;
    } 

    for (int k = 0; k < N; k++)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j) continue;
                if (arr[i][k] != dfMAX && arr[k][j] != dfMAX)
                {
                    arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
                }
            }
        }
    }

    int num = 1;
    int min = dfMAX;
    for (int i = 0; i < N; i++)
    {
        int total = 0;
        for (int j = 0; j < N; j++)
            if(i != j) total += arr[i][j];

        if (total < min)
        {
            min = total;
            num = i + 1;
        }
    }
   
    printf("%d\n", num);
}
