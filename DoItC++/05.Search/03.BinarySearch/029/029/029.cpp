#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    sort(A.begin(), A.end());

    int M;
    scanf("%d", &M);
    
    for (int i = 0; i < M; i++)
    {    
        int find = 0;
        scanf("%d", &find);
        
        int start = 0; 
        int end = N - 1;

        for(;;)
        {
            int mid = (start + end) / 2;

            if (find > A[mid])
            {
                start = mid + 1;
            }
            else if (find < A[mid])
            {
                end = mid - 1;
            }
            else
            {
                printf("1\n");
                break;
            }

            if (start > end)
            {
                printf("0\n");
                break;
            }
        }
    }
}