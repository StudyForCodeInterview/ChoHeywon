#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <stdio.h>
using namespace std;

int A[10] = { 0, };
int main()
{
	int N, K;
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int cnt = 0;
	int sum = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		while (sum + A[i] <= K)
		{
			sum += A[i];
			cnt++;

			if (sum == K)
			{
				printf("%d", cnt);
				return 0;
			}
		}
	}

	return 0;
}

