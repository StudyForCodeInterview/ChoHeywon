#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    vector<int> times(N, 0);

    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &times[i]);
        end += times[i];
        if (times[i] > start) start = times[i];
    }

    int mid = 0;
    while(start <= end)
    {
        int sum = 0;
        int cnt = 0;
        mid = (start + end) / 2;
        
        for (int i = 0; i < N; i++)
        {          
            if (sum + times[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += times[i];
        }

        if (sum != 0) cnt++;
        if (cnt > M) start = mid + 1;
        else end = mid - 1;
    }

    printf("%d", start);
}
