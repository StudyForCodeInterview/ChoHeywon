#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void merge(int* array, int start, int middle, int end, int cnt)
{
    int* sortArray = new int[cnt];

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

void sort(int* array, int start, int end, int cnt)
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
    int cnt = 0;
    scanf("%d", &cnt);
    int* numArray = new int[cnt];
    for (int i = 0; i < cnt; i++)
        scanf("%d", &numArray[i]);

    sort(numArray, 0, cnt - 1, cnt);

    for (int i = 0; i < cnt; i++)
        printf("%d\n", numArray[i]);

}