#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Way
{
    Way(int inputIdx, int inputCost) : idx(inputIdx), cost(inputCost) {};
    int idx;
    int cost;
};
struct City
{
    int total = 100000000;
    vector<Way> ways; 
};
City cities[1000];

struct cmp
{
    bool operator()(const Way n1, const Way n2)
    {
        return cities[n1.idx].total > cities[n2.idx].total;
    }
};

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &from);
        scanf("%d", &to);
        scanf("%d", &cost);
        cities[from - 1].ways.push_back(Way(to - 1, cost));
    }
    scanf("%d", &from);
    scanf("%d", &to);
    from--;
    to--;

    cities[from].total = 0;
    priority_queue<Way, vector<Way>, cmp> Q;
    Q.push(Way(from, 0));

    while (!Q.empty())
    {
        City* city = &cities[Q.top().idx];
        int cost = Q.top().cost;
        Q.pop();

        if (cost > city->total) continue;      
        vector<Way>::iterator it = city->ways.begin();
        for (; it < city->ways.end(); it++)
        {
            if (cities[(*it).idx].total > city->total + (*it).cost)
            {
                cities[(*it).idx].total = city->total + (*it).cost;
                Q.push((*it));
            }
        }
    }

    printf("%d", cities[to].total);
}
