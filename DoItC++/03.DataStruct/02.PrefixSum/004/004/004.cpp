/*
BAEKJOON 11660

문제:
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

    1 2 3 4
    2 3 4 5
    3 4 5 6
    4 5 6 7

예를 들어, N = 4이고, 표가 위와 같이 채워져 있는 경우를 살펴보자.
여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, (4, 4)부터 (4, 4)까지 합을 구하면 7이다.
표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.

입력:
첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 
둘째 줄부터 N개의 줄에는 표에 채워져 있는 수가 1행부터 차례대로 주어진다. 
다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, 
(x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 
표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)

출력:
총 M줄에 걸쳐 (x1, y1)부터 (x2, y2)까지 합을 구해 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int row = 0;
    int sum_cnt = 0;
    scanf("%d", &row);
    scanf("%d", &sum_cnt);
    int col = row + 1;

    int num = 0;
    int** sumArray = new int*[row];
    for (int i = 0; i < row; i++)
    {
        sumArray[i] = new int[col];
        sumArray[i][0] = 0;

        for (int j = 1; j < col; j++)
        {
            scanf("%d", &num);
            sumArray[i][j] = sumArray[i][j - 1] + num;
        }
    }

    int* startRowArray = new int[sum_cnt];
    int* startColArray = new int[sum_cnt];
    int* endRowArray = new int[sum_cnt];
    int* endColArray = new int[sum_cnt];
    for (int i = 0; i < sum_cnt; i++)
    {
        scanf("%d", &startRowArray[i]);
        scanf("%d", &startColArray[i]);
        scanf("%d", &endRowArray[i]);
        scanf("%d", &endColArray[i]);
    }

    for (int i = 0; i < sum_cnt; i++)
    {
        int sum = 0;
        for (int j = startRowArray[i] - 1; j < endRowArray[i]; j++)
        {
            sum += sumArray[j][endColArray[i]] - sumArray[j][startColArray[i] - 1];
        }
        printf("%d\n", sum);
    }


    for (int i = 0; i < row; i++)
    {
        delete[] sumArray[i];
    }
    delete[] sumArray;

    delete[] startRowArray;
    delete[] startColArray;
    delete[] endRowArray;
    delete[] endColArray;
}

