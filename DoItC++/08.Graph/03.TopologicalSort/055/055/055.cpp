#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct CityInfo;
struct City
{
    int ref = 0;
    int prev = 0;
    bool visited = false;
    vector<CityInfo*> to;
    vector<CityInfo*> from;
};

struct CityInfo
{
    CityInfo(City* inputCity, int inputTime) : city(inputCity), time(inputTime) {};
    City* city;
    int time;
};
City* cities[10000];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++)
    {
        cities[i] = new City;
    }

    int start, end, time;
    for (int i = 0; i < M; i++)
    {   
        scanf("%d", &start);
        scanf("%d", &end);
        scanf("%d", &time);

        cities[end - 1]->ref++;
        cities[start - 1]->to.push_back(new CityInfo(cities[end - 1], time));
        cities[end - 1]->from.push_back(new CityInfo(cities[start - 1], time));
    }

    scanf("%d", &start);
    scanf("%d", &end);

    queue<City*> Q;
    Q.push(cities[start - 1]);

    while (!Q.empty())
    {
        City* city = Q.front();
        Q.pop();

        vector<CityInfo*>::iterator it = city->to.begin();
        for (; it < city->to.end(); it++)
        {
            CityInfo* info = *it;
            
            if (city->prev + info->time > info->city->prev)
                info->city->prev = city->prev + info->time;

            if (--(info->city->ref) == 0)
                Q.push(info->city);
        }
    }

    int cnt = 0;
    queue<City*> Q2;
    Q2.push(cities[end - 1]);
    while (!Q2.empty())
    {
        City* city = Q2.front();
        Q2.pop();

        vector<CityInfo*>::iterator it = city->from.begin();
        for (; it < city->from.end(); it++)
        {
            CityInfo* info = *it;
            if (info->city->prev + info->time == city->prev)
            {
                cnt++;
                if (info->city->visited == false)
                {
                    info->city->visited = true;
                    Q2.push(info->city);
                }
            }
        }
    }
    printf("%d\n%d", cities[end - 1]->prev, cnt);
}
