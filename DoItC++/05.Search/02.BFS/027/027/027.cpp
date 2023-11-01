#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

struct Node
{
    inline Node(short n, short m) : _n(n), _m(m) { };
    short _n = 0;
    short _m = 0;
    Node* _parent = nullptr;
};

Node around[4] =
{
    Node(-1, 0),
    Node(0, -1),
    Node(0, 1),
    Node(1, 0)
};

Node* BFS(char** map, char** visited, Node* start, short destN, short destM)
{
    queue<Node*> Q;
    visited[start->_n][start->_m] = 1;
    Q.push(start);

    while (!Q.empty())
    {
        Node* front = Q.front();
        Q.pop();
        if (front->_n == destN && front->_m == destM) 
            return front;

        for (short i = 0; i < 4; i++)
        {
            short n = front->_n + around[i]._n;
            short m = front->_m + around[i]._m;
            if (n < 0 || n > destN || m < 0 || m > destM) continue;

            if (map[n][m] == 1 && visited[n][m] != 1)
            {
                Node* node = new Node(n, m);
                node->_parent = front;
                visited[n][m] = 1;
                Q.push(node);
            }
        }
    }

    return nullptr;
}


int main()
{
    short N, M;
    scanf("%hd", &N);
    scanf("%hd", &M);
    char** map = new char*[N];
    char** visited = new char* [N];
    for (short n = 0; n < N; n++) map[n] = new char[M];
    for (short n = 0; n < N; n++) visited[n] = new char[M];

    char* input = new char[M];
    for (short n = 0; n < N; n++)
    {
        scanf("%s", input);
        for (short m = 0; m < M; m++)
        {
            visited[n][m] = 0;
            map[n][m] = (input[m] - 48);
        }
    }

    int cnt = 1;
    Node* start = new Node(0, 0);
    Node* node = BFS(map, visited, start, N - 1, M - 1);
    while (node != start)
    {
        node = node->_parent;
        cnt++;
    }
    printf("%d", cnt);
}

/*
    printf("\n");
    for (short n = 0; n < N; n++)
    {
        for (short m = 0; m < M; m++)
        {
            printf("%d", map[n][m]);
        }
        printf("\n");
    }
    printf("\n");
*/