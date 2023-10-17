/*
BAEKJOON 10986

문제:
수 N개 A1, A2, ..., AN 이 주어진다. 
이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력:
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)
둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

출력:
첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    long long cnt = 0;
    long long div = 0;
    scanf("%lld", &cnt);
    scanf("%lld", &div);
    cnt++;

    long long* sumArray = new long long[cnt];
    long long* remArray = new long long[div];
    long long result = 0;
    sumArray[0] = 0;
    for (long long i = 0; i < div; i++) remArray[i] = 0;
    for (long long i = 1; i < cnt; i++)
    {
        long long num = 0;
        scanf("%lld", &num);
        sumArray[i] = sumArray[i - 1] + num;
        remArray[(sumArray[i] % div)]++;
    } 
    for (long long i = 0; i < div; i++)
    {
        result += (remArray[i] * (remArray[i] - 1) / 2); 
    }
    result += remArray[0];
    printf("%lld", result);

    delete[] sumArray;
    delete[] remArray;

    return 0;
}

