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

struct Result
{
    Result(int idx, int cnt) : _idx(idx), _cnt(cnt) {};
    int _idx;
    int _cnt;
};

bool compare(Result a, Result b)
{
    if (a._cnt == b._cnt)
        return a._idx < b._idx;
    return a._cnt > b._cnt;
}

int BFS(char* visited, Node* node)
{
    int cnt = 0;
    visited[node->_idx] = 1;
    queue<Node*> Q;
    Q.push(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();
        cnt++;

        vector<Node*>::iterator it = frontNode->_connect.begin();
        for (; it < frontNode->_connect.end(); it++)
        {
            if (visited[(*it)->_idx] != 1)
            {
                visited[(*it)->_idx] = 1;
                Q.push((*it));
            }
        }
    }
    return cnt;
}

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    Node* nodes = new Node[N];
    char* visited = new char[N];
    for (int i = 0; i < N; i++)
        nodes[i]._idx = i;

    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        nodes[B - 1]._connect.push_back(&nodes[A - 1]);
    }

    vector<Result> result;
    for (int i = 0; i < N; i++)
    {
        memset(visited, 0, N);
        int ret = BFS(visited, &nodes[i]);
        result.push_back(Result(i + 1, ret));
    }
    sort(result.begin(), result.end(), compare);

    int prev = result[0]._cnt;
    printf("%d ", result[0]._idx);
    for(int i = 1; i < result.size(); i++)
    {
        if (result[i]._cnt < prev) break;
        printf("%d ", result[i]._idx);
        prev = result[i]._cnt;
    }
}