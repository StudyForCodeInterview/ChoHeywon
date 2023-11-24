#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int idx;
    int parent;
    vector<Node*> child;
};

bool visited[50];
Node nodes[50];

int main()
{
    int N;
    scanf("%d", &N);
    
    int root = 0;
    for (int i = 0; i < N; i++)
    {
        int parent;
        scanf("%d", &parent);

        if (parent == -1) 
            root = i;
        else
            nodes[parent].child.push_back(&nodes[i]);

        nodes[i].idx = i;
        nodes[i].parent = parent;        
    }

    int remove;
    scanf("%d", &remove);

    if(remove == root)
    {
        printf("0");
        return 0;
    }

    queue<Node*> Q;
    Q.push(&nodes[root]);
    visited[root] = true;

    int cnt = 0;
    while (!Q.empty())
    {
        Node* node = Q.front();
        Q.pop();

        int size = node->child.size();
        if (size == 0) cnt++;

        for (int i = 0; i < size; i++)
        {
            Node* child = node->child[i];

            if (child->idx == remove)
            {               
                visited[child->idx] = true;
                if (size == 1) cnt++;
            }

            if (visited[child->idx] == false)
            {
                visited[child->idx] = true;
                Q.push(child);
            }
        }
    }

    printf("%d", cnt);
}

