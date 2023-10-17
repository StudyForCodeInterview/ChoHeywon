/*
BAEKJOON 1940

문제:
주몽은 철기군을 양성하기 위한 프로젝트에 나섰다. 
그래서 야철대장을 통해 철기군이 입을 갑옷을 만들게 하였다. 
야철대장은 주몽의 명에 따르기 위하여 연구에 착수하던 중 아래와 같은 사실을 발견하게 되었다.

갑옷을 만드는 재료들은 각각 고유한 번호를 가지고 있다. 갑옷은 두 개의 재료로 만드는데 
두 재료의 고유한 번호를 합쳐서 M(1 ≤ M ≤ 10,000,000)이 되면 갑옷이 만들어 지게 된다. 
야철대장은 자신이 만들고 있는 재료를 가지고 갑옷을 몇 개나 만들 수 있는지 궁금해졌다. 
이러한 궁금증을 풀어 주기 위하여 N(1 ≤ N ≤ 15,000) 개의 재료와 M이 주어졌을 때 몇 개의 갑옷을 만들 수 있는지를 구하는 프로그램을 작성하시오.

입력:
첫째 줄에는 재료의 개수 N(1 ≤ N ≤ 15,000)이 주어진다. 
그리고 두 번째 줄에는 갑옷을 만드는데 필요한 수 M(1 ≤ M ≤ 10,000,000) 주어진다. 
그리고 마지막으로 셋째 줄에는 N개의 재료들이 가진 고유한 번호들이 공백을 사이에 두고 주어진다. 
고유한 번호는 100,000보다 작거나 같은 자연수이다.

출력:
첫째 줄에 갑옷을 만들 수 있는 개수를 출력한다.

*/

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
    if(start < end)
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
    long long target = 0;
    scanf("%d", &cnt);
    scanf("%lld", &target);
    int* numArray = new int[cnt];
    for (int i = 0; i < cnt; i++)
        scanf("%d", &numArray[i]);
    
    sort(numArray, 0, cnt - 1, cnt);

    long long result = 0;
    int start = 0;
    int end = cnt - 1;
    
    while (start < end)
    {
        int sum = numArray[start] + numArray[end];
        if (sum == target)
        {
            result++;
            start++;
            end--;
        }
        else if (sum < target)
        {
            start++;
        }
        else if (sum > target)
        {
            end--;
        }
    }
    printf("%lld", result);
    delete[] numArray;

    return 0;
}

