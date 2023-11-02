#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

short set[200];
void Union(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];

    if (a != b)
    {
        if (a > b) set[b] = a;
        else set[a] = b;
    }
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

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++) set[i] = i;  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            short val;
            scanf("%hd", &val);
            if (val == 1) Union(i, j);
        }
    }

    int cur, prev;
    bool flag = true;
    scanf("%d", &prev);
    for (int i = 1; i < M; i++)
    {
        scanf("%d", &cur);
        if (!Find(prev - 1, cur - 1))
        {
            flag = false;
            break;
        }
        prev = cur;
    }

    if (flag) printf("YES\n");
    else printf("NO\n");
}
