#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10][10];
int unionSet[100];

bool Find(int A, int B)
{
    int a = unionSet[A];
    int b = unionSet[B];
    while (a != unionSet[a]) a = unionSet[a];
    while (b != unionSet[b]) b = unionSet[b];
    if (a == b) return true;
    return false;
}

void Union(int A, int B)
{
    int a = unionSet[A];
    int b = unionSet[B];
    while (a != unionSet[a]) a = unionSet[a];
    while (b != unionSet[b]) b = unionSet[b];

    if (a != b)
    {
        if (a < b) unionSet[b] = a;
        else unionSet[a] = b;
    }
}

struct Pos
{
    Pos(int inputX, int inputY) : x(inputX), y(inputY) {};
    int x;
    int y;
};

struct Island
{
    int num = 0;
    vector<Pos> lands;
};
Island islands[6];

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
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
            unionSet[num] = num;
            num++;
        }
    }

    num = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1)
            {
                if (i > 0 && arr[i - 1][j] == 1)
                {
                    Union(num - M, num);
                }
                if (j > 0 && arr[i][j - 1] == 1)
                {
                    Union(num - 1, num);
                }
            }
            else
            {
                unionSet[num] = -1;
            }
            num++;
        }
    }

    int islandCnt = 0;
    set<int> tmp;
    for (int i = 0; i < num; i++)
    {
        if (unionSet[i] != -1)
        {
            auto it = tmp.insert(unionSet[i]);
            if (it.second) islandCnt++;
            islands[islandCnt].num = unionSet[i];
            islands[islandCnt].lands.push_back(Pos(i % M, i / M));
        }
    }

    for (int i = 0; i < islandCnt; i++)
    {
        int is = islands[i].num;
        int size = islands[i].lands.size();
        for (int j = 0; j < size; j++)
        {
            int oriX = islands[i].lands[j].x;
            int oriY = islands[i].lands[j].y;
            
            int x = oriX + 1;
            while (x < M)
            {
                if (unionSet[oriY * M + x] != -1)
                {
                    if(x - oriX > 2 &&
                        unionSet[oriY * M + x] != is)
                    {
                        edges.push_back(Edge(
                            unionSet[oriY * M + x], is, x - oriX - 1));
                    }
                    break;
                }
                x++;
            }

            x = oriX - 1;
            while (x >= 0)
            {
                if (unionSet[oriY * M + x] != -1 )
                {
                    if(oriX - x > 2 &&
                        unionSet[oriY * M + x] != is)
                    {
                        edges.push_back(Edge(
                            unionSet[oriY * M + x], is, oriX - x - 1));
                    }
                    break;
                }
                x--;
            }

            int y = oriY + 1;
            while (y < N)
            {
                if (unionSet[y * M + oriX] != -1 )
                {
                    if(y - oriY > 2 &&
                        unionSet[y * M + oriX] != is)
                    {
                        edges.push_back(Edge(
                            unionSet[y * M + oriX], is, y - oriY - 1));
                    }
                    break;
                }
                y++;
            }

            y = oriY - 1;
            while (y >= 0)
            {
                if (unionSet[y * M + oriX] != -1)
                {
                    if(oriY - y > 2 &&
                        unionSet[y * M + oriX] != is)
                    {
                        edges.push_back(Edge(
                            unionSet[y * M + oriX], is, oriY - y - 1));
                    }
                    break;
                }
                y--;
            }
        }
    }

    int wTotal = 0;
    int edgeTotal = 0;
    ::sort(edges.begin(), edges.end(), cmp);

    for (int i = 0; i < edges.size(); i++)
    {
        if (!Find(edges[i].n1, edges[i].n2))
        {
            Union(edges[i].n1, edges[i].n2);
            wTotal += edges[i].w;
            edgeTotal++;
            if (edgeTotal == (islandCnt - 1)) break;
        }
    }

    if (edgeTotal != (islandCnt - 1)) printf("-1");
    else printf("%d", wTotal);
}

