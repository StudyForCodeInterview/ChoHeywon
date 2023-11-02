#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct Node
{
    int _idx;
    vector<Node*> _connect;
};

bool BFS(char* colors, Node* node)
{ 
    if (colors[node->_idx] != 0) return true;
    colors[node->_idx] = 1;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();

        vector<Node*>::iterator it = frontNode->_connect.begin();
        for (; it < frontNode->_connect.end(); it++)
        {
            if (colors[(*it)->_idx] == 0)
            {
                if (colors[frontNode->_idx] == 1) colors[(*it)->_idx] = 2;
                else if (colors[frontNode->_idx] == 2) colors[(*it)->_idx] = 1;
                Q.push((*it));
            }
            else if (colors[(*it)->_idx] == colors[frontNode->_idx])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        int V, E;
        scanf("%d", &V);
        scanf("%d", &E);
        char* colors = new char[V];
        memset(colors, 0, V);
        Node* nodes = new Node[V];
        for (int j = 0; j < V; j++)
            nodes[j]._idx = j;

        for (int j = 0; j < E; j++)
        {
            int u, v;
            scanf("%d", &u);
            scanf("%d", &v); 
            nodes[u - 1]._connect.push_back(&nodes[v - 1]);
            nodes[v - 1]._connect.push_back(&nodes[u - 1]);
        }

        bool flag = true;
        for (int j = 0; j < V; j++)
        {
            flag = BFS(colors, &nodes[j]);
            if (!flag) 
            {
                ::printf("NO\n");
                break;
            }
        }
        if(flag) ::printf("YES\n");
    }
}
