#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int idx;
    int parent;
    vector<Node*> connected;
};

bool visited[100000];
Node nodes[100000];

int main()
{
    int N;
    scanf("%d", &N);

    nodes[0].idx = 0;
    for (int i = 1; i < N; i++)
    {
        int n1, n2;
        scanf("%d", &n1);
        scanf("%d", &n2);
        nodes[n1 - 1].connected.push_back(&nodes[n2 - 1]);
        nodes[n2 - 1].connected.push_back(&nodes[n1 - 1]);
        nodes[i].idx = i;
    }
   
    queue<Node*> Q;
    Q.push(&nodes[0]);
    visited[0] = true;

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
                (*it)->parent = node->idx + 1;
                Q.push((*it));
            }
        }
    }

    for (int i = 1; i < N; i++)
    {
        printf("%d\n", nodes[i].parent);
    }
}

