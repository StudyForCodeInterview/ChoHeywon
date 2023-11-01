#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Data
{
	int _start;
	int _end;
};

bool compareStart(Data a, Data b) { return a._start < b._start; }
bool compareEnd(Data a, Data b) { return a._end < b._end; }

int main()
{
	int N;
	scanf("%d", &N);
	vector<Data> starts(N);
	vector<Data> ends(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &starts[i]._start);
		scanf("%d", &starts[i]._end);
		ends[i]._start = starts[i]._start;
		ends[i]._end = starts[i]._end;
	}

	sort(starts.begin(), starts.end(), compareStart);
	sort(ends.begin(), ends.end(), compareEnd);

	int max = pow(2, 31) - 1;
	int cnt = 1;
	Data data = ends[0];
	for (int i = 0; i < N; i++)
	{
		if (data._end <= starts[i]._start)
		{						
			int idx = -1;
			int min = max;
			for (int j = i; j < N; j++)
			{
				if (min >= starts[j]._end) 
				{
					min = starts[j]._end;
					idx = j;
				}
			}
			
			if (idx == -1) break;
			data = starts[idx];
			cnt++;
		}
	}

	::printf("%d", cnt);
}
