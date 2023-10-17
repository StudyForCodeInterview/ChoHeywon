/*
BAEKJOON 1253

문제:
N개의 수 중에서 어떤 수가 다른 수 두 개의 합으로 나타낼 수 있다면 그 수를 “좋다(GOOD)”고 한다.
N개의 수가 주어지면 그 중에서 좋은 수의 개수는 몇 개인지 출력하라.
수의 위치가 다르면 값이 같아도 다른 수이다.

입력:
첫째 줄에는 수의 개수 N(1 ≤ N ≤ 2,000), 
두 번째 줄에는 i번째 수를 나타내는 Ai가 N개 주어진다. 
(|Ai| ≤ 1,000,000,000, Ai는 정수)

출력:
좋은 수의 개수를 첫 번째 줄에 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
    int cnt = 0;
    scanf("%d", &cnt);
    long long* numArray = new long long[cnt];
    for (int i = 0; i < cnt; i++)
    {
        scanf("%lld", &numArray[i]);
    }
    sort(numArray, 0, cnt - 1, cnt);

    int result = 0;
    for (int i = 0; i < cnt; i++)
    {
        int start = 0;
        int end = cnt - 1;
        long long target = numArray[i];

        while (start < end)
        {
            long long sum = numArray[start] + numArray[end];
            if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            else
            {
                if (start == i) 
                {
                    start++;
                }
                else if (end == i) 
                {
                    end--;
                }
                else
                {
                    result++;
                    break;
                }
            }
        }
    }
    printf("%d", result);

    return 0;
}

