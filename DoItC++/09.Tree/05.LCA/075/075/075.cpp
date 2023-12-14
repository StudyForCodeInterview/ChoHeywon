#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100002
struct Node
{
    int idx;
    int depth = 0;
    int parent = 0;
    vector<Node*> connected;
};

bool visited[MAX];
Node nodes[MAX];

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i < N; i++)
    {
        int n1, n2;
        scanf("%d", &n1);
        scanf("%d", &n2);
        nodes[i].idx = i;
        nodes[n1].connected.push_back(&nodes[n2]);
        nodes[n2].connected.push_back(&nodes[n1]);
    }

    queue<Node*> Q;
    Q.push(&nodes[1]);
    visited[1] = true;
    int depthMax = 0;

    while (!Q.empty())
    {
        Node* node = Q.front();
        Q.pop();

        vector<Node*>::iterator it = node->connected.begin();
        for (; it < node->connected.end(); it++)
        {
            if (visited[(*it)->idx] == false)
            {
                visited[(*it)->idx] = true;
                (*it)->parent = node->idx;
                (*it)->depth = node->depth + 1;
                depthMax = max(depthMax, (*it)->depth);
                Q.push((*it));
            }
        }
    }

    int K = 0;
    while (pow(2, K) < depthMax) K++;

    int** parents_k = new int* [K];
    parents_k[0] = new int[MAX];
    for (int j = 0; j < N + 1; j++)
        parents_k[0][j] = nodes[j].parent;

    for (int i = 1; i < K; i++)
    {
        parents_k[i] = new int[MAX];
        for (int j = 0; j < N + 1; j++)
        {
            int p = parents_k[i - 1][j];
            for (int k = 0; k < i; k++)
                p = parents_k[i - 1][p];
            parents_k[i][j] = p;
        }
    }

    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        scanf("%d", &n1);
        scanf("%d", &n2);

        int p1, p2;
        if (nodes[n1].depth > nodes[n2].depth)
        {
            p1 = n1;
            p2 = n2;
        }
        else
        {
            p1 = n2;
            p2 = n1;
        }

        for (int j = K - 1; j >= 0; j--)
        {
            if (pow(2, j) <= nodes[p1].depth - nodes[p2].depth)
            {
                if (nodes[p2].depth <= parents_k[j][p1])
                {
                    p1 = parents_k[j][p1];
                }
            }
        }

        for (int j = K - 1; j >= 0; j--)
        {
            if (p1 != p2) break;
            if (parents_k[j][p1] != parents_k[j][p2])
            {
                p1 = parents_k[j][p1];
                p2 = parents_k[j][p2];
            }
        }

        int res = p2;
        if (p1 != p2)
            res = parents_k[0][res];

        printf("%d\n", res);
    }
}
