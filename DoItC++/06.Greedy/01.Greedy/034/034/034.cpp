#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j) { return j < i; }
int main()
{
	int N;
	scanf("%d", &N);
	vector<int> minus;
	vector<int> plus;
	for (int i = 0; i < N; i++)
	{
		int val;
		scanf("%d", &val);
		if(val > 0)
			plus.push_back(val);
		else
			minus.push_back(val);
	}

	stable_sort(plus.begin(), plus.end(), compare);
	stable_sort(minus.begin(), minus.end());

	int result = 0;
	for (int i = 0; i < plus.size(); i += 2)
	{
		if (i + 1 == plus.size())
		{
			result += plus[i];
		}
		else
		{
			if (plus[i] * plus[i + 1] > plus[i] + plus[i + 1])
			{
				result += plus[i] * plus[i + 1];
			}
			else
			{ 
				result += plus[i];
				result += plus[i + 1];		
			}
		}
	}

	for (int i = 0; i < minus.size(); i += 2)
	{
		if (i + 1 == minus.size())
		{
			result += minus[i];
		}
		else
		{
			if (minus[i] * minus[i + 1] > minus[i] + minus[i + 1])
			{
				result += minus[i] * minus[i + 1];
			}
			else
			{
				result += minus[i];
				result += minus[i + 1];
			}
		}
	}

	printf("%d", result);
}
