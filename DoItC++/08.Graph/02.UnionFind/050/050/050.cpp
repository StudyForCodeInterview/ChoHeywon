#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int set[1000000];

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
    for (int i = 0; i < N + 1; i++) set[i] = i;

    for (int i = 0; i < M; i++)
    {
        short type;
        int A, B;

        scanf("%hd", &type);
        scanf("%d", &A);
        scanf("%d", &B);

        if (type == 0)
        {
            Union(A, B);
        }
        else
        {
            if (Find(A, B)) printf("YES\n");
            else printf("NO\n");
        }
    }
}
