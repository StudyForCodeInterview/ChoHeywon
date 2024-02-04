#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int set[2500];
void Union(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];
    set[b] = a;
}

bool Find(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];
    if (a == b) return true;
    return false;
}

struct Edge
{
    Edge(int input1, int input2, int inputW) : n1(input1), n2(input2), w(inputW) {};
    int n1;
    int n2;
    int w;
};

bool cmp(const Edge e1, const Edge e2)
{
    return e1.w < e2.w;
}

vector<Edge> edges;

int main()
{
    int N;
    scanf("%d", &N);

    int idx = 0;
    int wTotal = 0;
    for (int i = 0; i < N; i++)
    {
        char input[50] = { '\0', };
        scanf("%s", &input);

        for (int j = 0; j < N; j++)
        {
            int val = (int)input[j];
            if (val >= 97 && val <= 122) // a-z
            {
                edges.push_back(Edge(i, j, val - 96));
                wTotal += val - 96;
            }
            else if (val >= 65 && val <= 90) // A-Z
            {
                edges.push_back(Edge(i, j, val - 38));
                wTotal += val - 38;
            }

            set[idx] = idx;
            idx++;
        }
    }

    int edgeTotal = 0;
    sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < edges.size(); i++)
    {
        if (!Find(edges[i].n1, edges[i].n2))
        {
            Union(edges[i].n1, edges[i].n2);
            wTotal -= edges[i].w;
            edgeTotal++;
            if (edgeTotal == (N - 1)) break;
        }
    }

    if (edgeTotal != N - 1) printf("-1");
    else printf("%d", wTotal);
}
