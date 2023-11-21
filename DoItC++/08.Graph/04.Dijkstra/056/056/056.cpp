#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define INF 300000
struct Node
{
    int dist = INF;
    vector<short> idx;
    vector<short> w;
};

struct cmp
{
    bool operator()(const Node* n1, const Node* n2)
    {
        return n1->dist > n2->dist;
    }
};
Node nodes[20000];
int main()
{
    int V, E, K;
    scanf("%d", &V);
    scanf("%d", &E);
    scanf("%d", &K);
    
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d", &u);
        scanf("%d", &v);
        scanf("%d", &w);

        nodes[u - 1].idx.push_back(v - 1);
        nodes[u - 1].w.push_back(w);
    }

    K--;
    nodes[K].dist = 0;
    priority_queue<Node*, vector<Node*>, cmp> Q;
    Q.push(&nodes[K]);

    while (!Q.empty())
    {
        Node* node = Q.top();
        Q.pop();

        int size = node->idx.size();
        for (int i = 0; i < size; i++)
        {
            short idx = node->idx[i];
            short w = node->w[i];

            if (nodes[idx].dist > node->dist + w)
            {
                nodes[idx].dist = node->dist + w;
                Q.push(&nodes[idx]);
            }           
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (i == K)
            printf("0\n");
        else if (nodes[i].dist == INF)
            printf("INF\n");
        else
            printf("%d\n", nodes[i].dist);
    }
}
