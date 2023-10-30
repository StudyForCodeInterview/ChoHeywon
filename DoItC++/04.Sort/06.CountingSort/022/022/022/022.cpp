#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int main()
{
    int N = 0;
    scanf("%d", &N);
    int count[10001] = { 0, };

    short value;
    for (int i = 0; i < N; i++)
    {
        scanf("%hd", &value);
        count[value]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        while (count[i] > 0)
        {
            printf("%hd\n", i);
            count[i]--;
        }
    }
}

/*
    short value;
    short idx;
    short divisor;
    queue<short> Q[10];

    int cnt0[10] = { 0, };
    int cnt1[10] = { 0, };

    for (int i = 0; i < N; i++)
    {
        scanf("%hd", &value);
        idx = value % 10;
        Q[idx].push(value);
        cnt0[idx]++;
    }

    divisor = pow(10, 1);
    for (char i = 0; i < 10; i++)
    {
        while(cnt0[i] > 0)
        {
            value = Q[i].front();
            idx = (value / divisor) % 10;
            Q[i].pop();
            cnt0[i]--;

            Q[idx].push(value);
            cnt1[idx]++;
        }
    }

    ...

    for (char i = 0; i < 10; i++)
    {
        while (cnt0[i] > 0)
        {
            value = Q[i].front();
            Q[i].pop();
            cnt0[idx]--;
            printf("%hd\n", value);
        }
    }

*/