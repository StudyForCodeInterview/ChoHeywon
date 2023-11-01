#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

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

void BFS(char* visited, Vertex* vertex)
{
    visited[vertex->_idx - 1] = 1;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        printf("%d ", frontNode->_num);
        Q.pop();

        vector<Node*>::iterator it = frontNode->_connected.begin();
        for (; it < frontNode->_connected.end(); it++)
        {
            if (visited[(*it)->_num - 1] != 1)
            {
                visited[(*it)->_num - 1] = 1;
                Q.push((*it));
            }
        }
    }
}

int main()
{
    int V;
    scanf("%d", &V);
    Vertex* vertexs = new Vertex[V];

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
}
