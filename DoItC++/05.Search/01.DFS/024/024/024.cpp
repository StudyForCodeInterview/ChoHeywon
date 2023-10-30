#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    short N;
    scanf("%hd", &N);

	int max = pow(10, N);
	int min = pow(10, N - 1);
	char* table = new char[max];
	vector<int> prime;
	
	for (int i = 0; i < max; i++) table[i] = 1;
	for (int i = 2; i < max; i++)
	{
		if (table[i] == 1)
		{
			if (min <= i) prime.push_back(i);
			for (int j = i * 2; j < max; j += i) table[j] = 0;
		}
	}

	bool flag;
	vector<int>::iterator iter = prime.begin();
	for (; iter != prime.end();)
	{
		flag = true;
		for (int j = 1; j < N; j++)
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
}
