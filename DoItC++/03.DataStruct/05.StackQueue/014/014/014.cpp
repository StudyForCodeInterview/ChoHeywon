/*
BAEKJOON 11286

문제:
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

1) 배열에 정수 x (x ≠ 0)를 넣는다.
2) 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 
절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 
그 값을 배열에서 제거한다.

프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력:

첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 
다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, 
x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 
그 값을 배열에서 제거하는 경우이다. 
입력되는 정수는 -2^31보다 크고, 2^31보다 작다.

출력:
입력에서 0이 주어진 횟수만큼 답을 출력한다. 
만약 배열이 비어 있는 경우인데 
절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;

class node
{
public: 
	node(int val) : _val(val), _abs(abs(val)) {};
	bool operator < (const node other) const
	{
		if(_abs == other._abs)
			return _val > other._val;
		else
			return _abs > other._abs;
	}

public:
	int _val;
	int _abs;
};
int main()
{
	int n = 0;
	scanf("%d", &n);
	priority_queue<node, vector<node>, less<node>> q;

	int val = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		if (val == 0)
		{
			if(q.empty()) 
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", q.top());
				q.pop();
			}
		}
		else
		{
			q.push(node(val));
		}
	}
	return 0;
}
