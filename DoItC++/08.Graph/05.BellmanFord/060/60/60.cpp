#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define dfMIN -9223372036854775806
struct Edge
{
    int from = 0;
    int to = 0;
    int cost = 0;
};
Edge edges[50];
int pays[50];
long long maxs[50];

struct Node
{
    int num;
    vector<Node*> connected;
};
Node nodes[50];
bool visited[50];

void BFS(Node* node)
{
    visited[node->num] = true;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();

        vector<Node*>::iterator it = frontNode->connected.begin();
        for (; it < frontNode->connected.end(); it++)
        {
            if (visited[(*it)->num] == false)
            {
                visited[(*it)->num] = true;
                Q.push((*it));
            }
        }
    }
}

int main()
{
    int N, start, dest, M;
    scanf("%d", &N);
    scanf("%d", &start);
    scanf("%d", &dest);
    scanf("%d", &M);
    fill(maxs, maxs + 50, dfMIN);

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        scanf("%d", &from);
        scanf("%d", &to);
        scanf("%d", &cost);

        edges[i].from = from;
        edges[i].to = to;
        edges[i].cost = cost;
        nodes[from].connected.push_back(&nodes[to]);
    }

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &pays[i]);
        nodes[i].num = i;
    }

    maxs[start] = pays[start];
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            Edge e = edges[j];
            if (maxs[e.from] != dfMIN && maxs[e.to] < maxs[e.from] - e.cost + pays[e.to])
            {
                maxs[e.to] = maxs[e.from] - e.cost + pays[e.to];
            }
        }
    }
    
    bool gee = false;
    for (int j = 0; j < M; j++)
    {
        Edge e = edges[j];
        if (maxs[e.from] != dfMIN && maxs[e.to] < maxs[e.from] - e.cost + pays[e.to])
        {
            maxs[e.to] = maxs[e.from] - e.cost + pays[e.to];

            fill(visited, visited + 50, false);
            BFS(&nodes[e.to]);
            if (visited[dest]) 
            {
                gee = true;
                break;
            }
        }
    }

    if (maxs[dest] == dfMIN)
        printf("gg\n");
    else if (gee)
        printf("Gee\n");
    else
        printf("%lld\n", maxs[dest]);

}

