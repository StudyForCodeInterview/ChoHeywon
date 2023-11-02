#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

vector<int> party[50];
int set[50];

void Union(int A, int B)
{
    int a = set[A];
    int b = set[B];
    while (a != set[a]) a = set[a];
    while (b != set[b]) b = set[b];
    if (a < b) set[b] = a;
    else if (a > b) set[a] = b;
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
    int N, M, T;
    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &T);

    if (T == 0)
    {
        printf("%d", M);
        return 0;
    }

    for (int i = 0; i < N; i++) set[i] = i;

    int truthIdx = 0;
    scanf("%d", &truthIdx);
    truthIdx--;

    for (int i = 1; i < T; i++)
    {
        int idx;
        scanf("%d", &idx);
        idx--;
        Union(truthIdx, idx);
    }

    for (int i = 0; i < M; i++)
    {
        int P;
        scanf("%d", &P);

        int partyIdx;
        scanf("%d", &partyIdx);
        partyIdx--;
        party[i].push_back(partyIdx);

        for (int j = 1; j < P; j++)
        {
            int idx;
            scanf("%d", &idx);
            idx--;
            party[i].push_back(idx);
            Union(partyIdx, idx);
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        bool flag = true;
        for (int j = 0; j < party[i].size(); j++)
        {
            if (Find(party[i][j], truthIdx))
            {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    printf("%d", cnt);
}
