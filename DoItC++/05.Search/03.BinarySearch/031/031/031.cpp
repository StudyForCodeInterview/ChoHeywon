#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int N, k;
    scanf("%d", &N);
    scanf("%d", &k);

    int start = 1;
    int end = k;

    int result = 0; 
    while (start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0;
        for(int i = 1; i < N + 1; i++)
            sum += min(mid / i, N);

        if (sum < k)
        {
            start = mid + 1;
        }
        else
        {
            result = mid;
            end = mid - 1;
        }
    }

    printf("%d", result);
}
