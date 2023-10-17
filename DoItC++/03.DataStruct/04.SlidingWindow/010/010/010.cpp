/*
BAEKJOON 11003

문제:
N개의 수 A1, A2, ..., AN과 L이 주어진다.
Di = Ai-L+1 ~ Ai 중의 최솟값이라고 할 때, 
D에 저장된 수를 출력하는 프로그램을 작성하시오. 
이때, i ≤ 0 인 Ai는 무시하고 D를 구해야 한다.

입력:
첫째 줄에 N과 L이 주어진다. (1 ≤ L ≤ N ≤ 5,000,000)
둘째 줄에는 N개의 수 Ai가 주어진다. (-109 ≤ Ai ≤ 109)

출력:
첫째 줄에 Di를 공백으로 구분하여 순서대로 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <deque>
using namespace std;

class node
{
public:
	node(int idx, int val) : _idx(idx), _val(val) {};

public:
	int _idx;
	int _val;
};

int main()
{
	int n = 0;
	int l = 0;
	scanf("%d", &n);
	scanf("%d", &l);
	deque<node> deq;

	for (int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);

		while (deq.size() && deq.back()._val > val)
			deq.pop_back();

		deq.push_back(node(i, val));

		if (deq.front()._idx <= i - l)
			deq.pop_front();

		printf("%d ", deq.front()._val);
	}

	return 0;
}