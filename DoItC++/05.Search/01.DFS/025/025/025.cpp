#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

struct Node
{
    int _idx = 0;
    vector<Node*> _friends;
};

bool g_result = false;
void DFS(int& cnt, char* visited, Node* node)
{
    visited[node->_idx] = 1;
    if (cnt >= 4) 
    {
        g_result = true;
        return;
    }
    
    vector<Node*>::iterator iter = node->_friends.begin();
    for (; iter < node->_friends.end(); iter++)
    {
        if (visited[(*iter)->_idx] == 0)
        {
            cnt++;
            DFS(cnt, visited, (*iter));
            cnt--;
        }
    }
    visited[node->_idx] = 0;
}


int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    Node* nodes = new Node[N];
    char* visited = new char[N];

    for (int i = 0; i < N; i++)
    {
        nodes[i]._idx = i;
    }

    for (int i = 0; i < M; i++)
    {
        int u, v = 0;
        scanf("%d", &u);
        scanf("%d", &v);
        nodes[u]._friends.push_back(&nodes[v]);
        nodes[v]._friends.push_back(&nodes[u]);
    }

    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        memset(visited, 0, N);
        DFS(cnt, visited, &nodes[i]);
        if (g_result)
        {
            printf("1");
            delete[] nodes;
            delete[] visited;
            return 0;
        }
    }

    printf("0");
    delete[] nodes;
    delete[] visited;
    return 0;
}

