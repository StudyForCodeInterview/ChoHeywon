#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int n) 
{
	for (int i = 2; i <= sqrt(n); i++) 
		if (n % i == 0) return false;
	return true;
}

int main()
{
    short N;
    scanf("%hd", &N);
	vector<int>* prime = new vector<int>[N];
	
	for (int i = 2; i < 10; i++)
	{
		if (isPrime(i)) prime[0].push_back(i);
	}

	for (int i = 1; i < N; i++)
	{
		vector<int>::iterator iter = prime[i - 1].begin();
		for (; iter < prime[i - 1].end(); iter++)
		{
			for (int j = 1; j < 10; j++)
			{
				int value = (*iter) * 10 + j;
				if (isPrime(value)) prime[i].push_back(value);
			}
		}
	}
	
	sort(prime[N - 1].begin(), prime[N - 1].end());
	vector<int>::iterator iter = prime[N - 1].begin();
	for (; iter < prime[N - 1].end(); iter++)
	{
		printf("%d\n", *iter);
	}
}

/*
<메모리 초과>

	int max = pow(10, N);
	int min = pow(10, N - 1) * 2;
	char* table = new char[max];
	vector<int> prime;

	table[0] = 0;
	for (int i = 1; i < max; i++)
		table[i] = 1;

	for (int i = 2; i < max; i++)
	{
		if (table[i] == 1)
		{
			if (min <= i)
			{
				prime.push_back(i);
			}
			for (int j = i * 2; j < max; j += i) table[j] = 0;
		}
	}

	bool flag;
	vector<int>::iterator iter = prime.begin();
	for (; iter != prime.end();)
	{
		flag = true;
		for (short j = 1; j < N; j++)
		{
			int idx = (*iter) / pow(10, j);
			if (table[idx] == 0)
			{
				flag = false;
				break;
			}
		}

		if (!flag)
		{
			iter = prime.erase(iter);
		}
		else
		{
			printf("%d\n", *iter);
			iter++;
		}
	}

	delete[] table;

*/