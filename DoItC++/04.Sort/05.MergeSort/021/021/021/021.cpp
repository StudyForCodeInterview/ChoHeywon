#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long g_result = 0;
void merge(long long* array, int start, int middle, int end, int cnt)
{
    long long* sortArray = new long long[cnt];

    int i = start;
    int j = middle + 1;
    int k = start;

    while (i <= middle && j <= end)
    {
        if (array[i] <= array[j])
        {
            sortArray[k] = array[i];
            i++;

        }
        else
        {
            sortArray[k] = array[j];
            g_result += (j - k);
            j++;
        }
        k++;
    }

    if (i > middle)
    {
        for (int idx = j; idx <= end; idx++)
        {
            sortArray[k] = array[idx];
            k++;
        }
    }
    else
    {
        for (int idx = i; idx <= middle; idx++)
        {
            sortArray[k] = array[idx];
            k++;
        }
    }

    for (int idx = start; idx <= end; idx++)
    {
        array[idx] = sortArray[idx];
    }

    delete[] sortArray;
}

void sort(long long* array, int start, int end, int cnt)
{
    if (start < end)
    {
        int middle = (start + end) / 2;
        sort(array, start, middle, cnt);
        sort(array, middle + 1, end, cnt);
        merge(array, start, middle, end, cnt);
    }
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    long long* A = new long long[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%lld", &A[i]);
    }

    sort(A, 0, N - 1, N);
    printf("%lld", g_result);
}
