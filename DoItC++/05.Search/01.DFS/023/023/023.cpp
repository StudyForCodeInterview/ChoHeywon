#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

struct Node
{
    int _num = 0;
    vector<Node*> _connected;
};

void DFS(bool* visited, Node* node)
{
    visited[node->_num] = true;

    for (int i = 0; i < node->_connected.size(); i++)
    {
        if (!visited[node->_connected[i]->_num])
        {
            DFS(visited, node->_connected[i]);
        }
    }
}

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    Node* nodes = new Node[N]; 
    bool* visited = new bool[N];

    for (int i = 0; i < N; i++)
    {
        nodes[i]._num = i;
        visited[i] = false;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v = 0;
        scanf("%d", &u);   
        scanf("%d", &v);
        nodes[u - 1]._connected.push_back(&nodes[v - 1]);
        nodes[v - 1]._connected.push_back(&nodes[u - 1]);
    }


    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        { 
            DFS(visited, &nodes[i]);
            count++;
        }
    }
    printf("%d", count);
}
