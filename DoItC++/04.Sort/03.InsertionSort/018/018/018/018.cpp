#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int cnt = 0;
    scanf("%d", &cnt);
    vector<int> times;
    times.resize(cnt);
    for (int i = 0; i < cnt; i++)
        scanf("%d", &times[i]);

    stable_sort(times.begin(), times.end());

    int sum = 0;

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += times[j];
        }
    }

    ::printf("%d", sum);
}
