#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

#define MAX 2097152
#define MID 1048576
#define DIV 1000000007
long long arr[MAX] = { 0, };

int main()
{
    int N, M, K;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);

    for (int i = 0; i < N; i++)
    {
        long long input;
        scanf("%lld", &input);
        arr[MID + i] = input;
    }

    for (int i = MID - 1; i > 0; i--)
    {
        arr[i] = ((arr[i * 2] % DIV) * (arr[i * 2 + 1] % DIV)) % DIV;
    }

    for (int i = 0; i < (M + K); i++)
    {
        short a;
        long long b, c;
        scanf("%hd", &a);
        scanf("%lld", &b);
        scanf("%lld", &c);

        if (a == 1)
        {
            arr[b + MID - 1] = c;
            int idx = (b + MID - 1) / 2;
            while (idx > 0)
            {
                arr[idx] = ((arr[idx * 2] % DIV) * (arr[idx * 2 + 1] % DIV)) % DIV;
                idx = idx / 2;
            }
        }
        else if (a == 2)
        {
            long long res = 1;
            int start = b + MID - 1;
            int end = c + MID - 1;
            while (start <= end)
            {
                if (start % 2 == 1) res = ((res % DIV) * (arr[start] % DIV)) % DIV;
                if (end % 2 == 0) res = ((res % DIV) * (arr[end] % DIV)) % DIV;
                start = (start + 1) / 2;
                end = (end - 1) / 2;
            }
            printf("%lld\n", res);
        }
    }
}


