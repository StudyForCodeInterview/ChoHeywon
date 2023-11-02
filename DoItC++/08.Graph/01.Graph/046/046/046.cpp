#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;

struct Node
{
    int _idx;
    vector<Node*> _connect;
};

void BFS(vector<int>& result, int N, int K, char* visited, Node* node)
{
    vector<int> distances(N, 0);  
    visited[node->_idx] = 1;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();

        vector<Node*>::iterator it = frontNode->_connect.begin();
        for (; it < frontNode->_connect.end(); it++)
        {
            if (visited[(*it)->_idx] != 1)
            {
                visited[(*it)->_idx] = 1;
                Q.push((*it));

                distances[(*it)->_idx]++;
                distances[(*it)->_idx] += distances[frontNode->_idx];
            }
        }
    }

    for (int i = 0; i < distances.size(); i++)
    {
        if (distances[i] == K)
            result.push_back(i + 1);
    }
}


int main()
{
    int N, M, K, X;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &K);
    scanf("%d", &X);

    Node* nodes = new Node[N];  
    char* visited = new char[N];
    memset(visited, 0, N);
    for (int i = 0; i < N; i++)
        nodes[i]._idx = i;      

    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        nodes[A - 1]._connect.push_back(&nodes[B - 1]);
    }

    vector<int> result;
    BFS(result, N, K, visited, &nodes[X - 1]);

    if(result.empty())
    {
        printf("-1");
    }
    else
    {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
            printf("%d\n", result[i]);
    }
}
