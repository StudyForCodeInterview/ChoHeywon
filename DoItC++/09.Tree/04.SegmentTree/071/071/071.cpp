#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

#define MAX 2097152
#define MID 1048576
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
        arr[i] = arr[i * 2] + arr[i * 2 + 1];
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
            while(idx > 0)
            {
                arr[idx] = arr[idx * 2] + arr[idx * 2 + 1];
                idx = idx / 2;
            }
        }
        else if (a == 2)
        {   
            long long sum = 0;
            int start = b + MID - 1;
            int end = c + MID - 1;           
            while(start <= end)
            {
                if (start % 2 == 1) sum += arr[start];
                if (end % 2 == 0) sum += arr[end];
                start = (start + 1) / 2;
                end = (end - 1) / 2;
            }
            printf("%lld\n", sum);
        }
    }
}


