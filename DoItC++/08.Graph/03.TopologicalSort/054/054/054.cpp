#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Building
{
    int time = 0;
    int prev = 0;
    int need = 0;
    vector<Building*> after;
};

Building* buildings[500];

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        buildings[i] = new Building;
    }

    for(int i = 0; i < N; i++)
    {
        int input = 1;
        scanf("%d", &(buildings[i]->time));
        scanf("%d", &input);
        while (input != -1)
        {
            buildings[input - 1]->after.push_back(buildings[i]);
            buildings[i]->need++;
            scanf("%d", &input);
        }
    }

    queue<Building*> Q;
    for (int i = 0; i < N; i++)
    {
        if (buildings[i]->need == 0)
            Q.push(buildings[i]);
    }

    while (!Q.empty())
    {
        Building* building = Q.front();
        Q.pop();

        vector<Building*>::iterator it = building->after.begin();
        for(; it < building->after.end(); it++)
        {
            Building* b = *it;
            if((building->time + building->prev) > b->prev)
                b->prev = building->time + building->prev;
            if (--(b->need) == 0) 
                Q.push(b);
        }        
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", buildings[i]->time + buildings[i]->prev);
    }
}

