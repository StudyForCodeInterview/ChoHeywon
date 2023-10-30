#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Data
{
    Data() {};
    Data(int val, int idx) : _val(val), _idx(idx) {};
    int _val;
    int _idx;
};

bool compare(const Data& a, const Data& b)
{
    return a._val < b._val;
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    vector<int> originA;
    vector<Data> sortedA;
    originA.resize(N);
    sortedA.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &originA[i]);
        sortedA[i] = Data(originA[i], i);
    }

    stable_sort(sortedA.begin(), sortedA.end(), compare);

    int max = -1;
    int sub = 0;
    for (int i = 0; i < N; i++)
    {
        sub = sortedA[i]._idx - i;
        if (sub > max) max = sub;
    }

    printf("%d\n", max + 1);
}
