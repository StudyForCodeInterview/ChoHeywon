#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Vertex
{
    Vertex(int inputIdx, int inputCost) : idx(inputIdx), cost(inputCost) {};
    int idx;
    int cost;
};

struct Edge
{
    priority_queue<int> dists;
    vector<Vertex> vertexs;
};

struct Node
{
    Node(int inputIdx, int inputTotal) : idx(inputIdx), total(inputTotal) {};
    int idx;
    int total;
};

struct cmp
{
    bool operator()(const Node n1, const Node n2)
    {
        return n1.total > n2.total;
    }
};
Edge edges[1000];

int main()
{
    int n, m, k;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &k);
    k;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        edges[a - 1].vertexs.push_back(Vertex(b - 1, c));
    }
   
    priority_queue<Node, vector<Node>, cmp> Q;
    Q.push(Node(0, 0)); 
    edges[0].dists.push(0);

    while (!Q.empty())
    {
        Node n = Q.top();
        int idx = n.idx;
        Q.pop();

        vector<Vertex>::iterator it = edges[idx].vertexs.begin();
        for (; it < edges[idx].vertexs.end(); it++)
        {
            Vertex v = *it;
            int dist = n.total + v.cost;

            if (edges[v.idx].dists.size() < k)
            {
                edges[v.idx].dists.push(dist); 
                Q.push(Node(v.idx, dist));
            }
            else if (dist < edges[v.idx].dists.top())
            {
                edges[v.idx].dists.pop();
                edges[v.idx].dists.push(dist);
                Q.push(Node(v.idx, dist));
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (edges[i].dists.size() == k)
            printf("%d\n", edges[i].dists.top());           
        else
            printf("-1\n");
    }

}
