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
	bool _use = false;
};
bool compare(Data* a, Data* b) 
{ 
	if(a->_end == b->_end)
		return a->_start < b->_start; 
	return a->_end < b->_end;
}

int main()
{
	int N;
	scanf("%d", &N);
	vector<Data*> datas(N);
	for (int i = 0; i < N; i++)
	{
		Data* data = new Data;
		scanf("%d", &data->_start);
		scanf("%d", &data->_end);
		datas[i] = data;
	}
	sort(datas.begin(), datas.end(), compare);

	int cnt = 1;
	Data* data = datas[0];

	for (int i = 1; i < N; i++)
	{
		if (data->_end <= datas[i]->_start)
		{					
			data = datas[i];
			cnt++;
		}
	}

	::printf("%d", cnt);
}
