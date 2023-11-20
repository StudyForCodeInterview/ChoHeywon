#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

struct Student
{
    int num;
    int ref = 0;
    vector<Student*> tallers;    
};
Student* students[32000];

int main()
{
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i = 0; i < N; i++)
    {
        students[i] = new Student;
        students[i]->num = i + 1;
    }

    for (int i = 0; i < M; i++)
    {
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        students[A - 1]->tallers.push_back(students[B - 1]);
        students[B - 1]->ref++;
    }

    queue<Student*> Q;
    for (int i = 0; i < N; i++)
    {
        if(students[i]->ref == 0)
            Q.push(students[i]);
    }

    while(!Q.empty())
    {   
        printf("%d ", Q.front()->num);
        while (!Q.front()->tallers.empty())
        {
            Student* b = Q.front()->tallers.back();
            b->ref--;
            if (b->ref == 0)
                Q.push(b);
            Q.front()->tallers.pop_back();
        }
        Q.pop();
    }
}