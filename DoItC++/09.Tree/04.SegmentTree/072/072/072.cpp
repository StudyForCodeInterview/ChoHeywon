#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MAX 262144
#define MID 131072

int arr[MAX];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    ::fill(arr, arr + MAX, 1000000001);

    for (int i = 0; i < N; i++)
    {
        int input;
        scanf("%d", &input);
        arr[MID + i] = input;
    }

    for (int i = MID - 1; i > 0; i--)
    {
        arr[i] = min(arr[i * 2], arr[i * 2 + 1]);
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        scanf("%d", &a);
        scanf("%d", &b);

        int res = 1000000001;
        int start = a + MID - 1;
        int end = b + MID - 1;
        while (start <= end)
        {
            if (start % 2 == 1) res = min(res, arr[start]);
            if (end % 2 == 0) res = min(res, arr[end]);
            start = (start + 1) / 2;
            end = (end - 1) / 2;
        }
        printf("%d\n", res);
    }
}
