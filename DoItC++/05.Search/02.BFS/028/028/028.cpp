#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct Edge;
struct Vertex
{
    int _idx;
    vector<Edge*> _edges;
};

struct Edge
{
    Edge(Vertex* v, int dist) : _v(v), _dist(dist) {};
    Vertex* _v;
    int _dist;
};

int dists[100000];
Vertex vertexs[100000];
char visited[100000];

int BFS (char* visited, Vertex* v, int V)
{
    visited[v->_idx] = 1;    
    memset(dists, 0, sizeof(int) * V);
    queue<Vertex*> Q;
    Q.push(v);

    int max = 0;
    while (!Q.empty())
    {
        Vertex* front = Q.front();     
        Q.pop();

        for (int i= 0; i < front->_edges.size(); i++)
        {
            Edge* e = front->_edges[i];
            if (visited[e->_v->_idx] != 1)
            {
                visited[e->_v->_idx] = 1;          
                dists[e->_v->_idx] = e->_dist;
                dists[e->_v->_idx] += dists[front->_idx]; 
                if (dists[e->_v->_idx] > max) max = dists[e->_v->_idx];
                Q.push(e->_v);
            }         
        }
    }
    return max;
}

int main()
{
    int V;
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
    {
        int v_idx;
        scanf("%d", &v_idx);
        Vertex* v = &vertexs[v_idx - 1];
        v->_idx = v_idx - 1;

        for (;;)
        {
            int u_idx = 0;
            int dist = 0;
            scanf("%d", &u_idx);
            if (u_idx == -1) break;
            scanf("%d", &dist);

            Edge* e = new Edge(&vertexs[u_idx - 1], dist);
            v->_edges.push_back(e);
        }   
    }

    memset(visited, 0, V);
    BFS(visited, &vertexs[0], V);

    int max = 0;
    for (int i = 1; i < V; i++)
    {
        if (dists[i] > dists[max]) max = i;
    }

    memset(visited, 0, V);
    int result = BFS(visited, &vertexs[max], V);
    ::printf("%d", result);
}
