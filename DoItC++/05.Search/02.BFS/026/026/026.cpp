#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int _num = 0;
    vector<Node*> _connected;
};

void DFS(char* visited, Node* node)
{
    printf("%d ", node->_num);
    visited[node->_num] = 1;

    vector<Node*>::iterator it = node->_connected.begin();
    for (; it < node->_connected.end(); it++)
    {
        if (visited[(*it)->_num] == 0)
        {
            DFS(visited, *it);
        }
    }
}

void BFS(Node* node)
{

}

int main()
{
    int N, M, V;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &V);
    Node* nodes = new Node[N];
    char* visited = new char[N];

    for (int i = 0; i < M; i++)
    {
        int u, v = 0;
        scanf("%d", &u);
        scanf("%d", &v);
        nodes[u - 1]._connected.push_back(&nodes[v - 1]);
        nodes[v - 1]._connected.push_back(&nodes[u - 1]);
    }

    for (int i = 0; i < N; i++)
    {
        visited[i] = 0;
        nodes[i]._num = i + 1;
        sort(nodes[i]._connected.begin(), nodes[i]._connected.end());
    }

    DFS(visited, &nodes[V - 1]);
    printf("\n");
    BFS(&nodes[V - 1]);
  
    return 0;
}
