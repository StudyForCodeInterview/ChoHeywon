#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[10][10];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &arr[i][j]);
}

