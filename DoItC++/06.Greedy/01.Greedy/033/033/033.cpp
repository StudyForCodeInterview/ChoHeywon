#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	priority_queue<int, vector<int>, greater<int>> cards;
	for(int i = 0; i < N; i++)
	{
		int card;
		scanf("%d", &card);
		cards.push(card);
	}

	int sum = 0;
	while (cards.size() >= 2)
	{
		int c1 = cards.top();
		cards.pop();
		sum += c1;
		
		int c2 = cards.top();
		cards.pop();
		sum += c2;

		cards.push(c1 + c2);	
	}

	if(cards.size() == 1)
	{
		int c = cards.top();
		cards.pop();
	}

	::printf("%d", sum);
}
