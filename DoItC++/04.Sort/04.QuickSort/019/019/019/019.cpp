#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int N = 0;
    scanf("%d", &N);
    int K = 0;
    scanf("%d", &K);

    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        scanf("%lld", &A[i]);
   
    stable_sort(A.begin(), A.end());
    printf("%lld", A[K - 1]);
}
