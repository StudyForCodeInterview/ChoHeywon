#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Dest;
struct City
{
    int ref = 0;
    int max = 1;
    int total = 0;
    vector<Dest*> dest;
};

struct Dest
{
    Dest(City* inputCity, int inputTime) : city(inputCity), time(inputTime) {};
    City* city;
    int time;
};
City* cities[10000];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int start, end, time;
    for (int i = 0; i < M; i++)
    {   
        scanf("%d", &start);
        scanf("%d", &end);
        scanf("%d", &time);
        cities[start - 1]->dest.push_back(new Dest(cities[end - 1], time));
        cities[end - 1]->ref++;
    }
    scanf("%d", &start);
    scanf("%d", &end);

    int cnt = 0;
    int time = 0;
    queue<City*> Q;
    Q.push(cities[start - 1]);

    while (!Q.empty())
    {
        City* city = Q.front();
        Q.pop();

        vector<Dest*>::iterator it = city->dest.begin();
        for (; it < city->dest.end(); it++)
        {
            Dest* d = *it;
            


            if (--(d->city->ref) == 0)
                Q.push(d->city);
        }
    }

}

