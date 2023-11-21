#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

#define dfMAX 9223372036854775806
struct Edge
{
    int _a = 0;
    int _b = 0;
    int _time = 0;
};

long long mins[500];
Edge edges[6000];

int main()
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    fill(mins, mins + n, dfMAX);

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &edges[i]._a);
        scanf("%d", &edges[i]._b);
        scanf("%d", &edges[i]._time);
        edges[i]._a--; 
        edges[i]._b--; 
    }

    mins[0] = 0;
    for (int i = 1; i < n; i++)
    {     
        for (int j = 0; j < m; j++)
        {
            Edge e = edges[j];
            if (mins[e._a] != dfMAX && mins[e._b] > mins[e._a] + e._time)
            {
                mins[e._b] = mins[e._a] + e._time;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        Edge e = edges[j];
        if (mins[e._a] != dfMAX && mins[e._b] > mins[e._a] + e._time)
        {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (mins[i] != dfMAX)
            printf("%lld\n", mins[i]);
        else
            printf("-1\n");
    }
}
