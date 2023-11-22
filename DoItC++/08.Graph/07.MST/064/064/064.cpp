#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
using namespace std;

struct Edge
{
    int n1;
    int n2;
    int w;
};
Edge edges[100000];

bool cmp(const Edge e1, const Edge e2)
{
    return e1.w < e2.w;
}

int set[10000];
void Union(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];
    set[b] = a;
}

bool Find(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];
    if (a == b) return true;
    return false;
}

int main()
{
    int V, E;
    scanf("%d", &V);
    scanf("%d", &E);
    for (int i = 0; i < V; i++)
        set[i] = i;

    for (int i = 0; i < E; i++)
    {
        scanf("%d", &edges[i].n1);
        scanf("%d", &edges[i].n2);
        scanf("%d", &edges[i].w);
        edges[i].n1--;
        edges[i].n2--;
    }    

    int wTotal = 0;
    int edgeTotal = 0;
    sort(edges, edges + E, cmp);

    for (int i = 0; i < E; i++)
    {
        if (!Find(edges[i].n1, edges[i].n2))
        {
            Union(edges[i].n1, edges[i].n2);         
            wTotal += edges[i].w;
            edgeTotal++;
            if (edgeTotal == (V - 1)) break;
        }        
    }

    printf("%d", wTotal);
}
