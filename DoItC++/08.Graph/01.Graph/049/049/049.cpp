#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

short fullA;
short fullB;
short fullC;

struct Node
{
    Node(short A, short B, short C) : _A(A), _B(B), _C(C) {};
    char _visited = 0;
    short _A, _B, _C;
    vector<Node*> _connect;
};

struct cmp {
    bool operator() (Node* const &n1, Node* const& n2) const
    {
        if (n1->_A == n2->_A)
        {
            if (n1->_C == n2->_C)
            {
                return n1->_B < n2->_B;
            }
            return n1->_C < n2->_C;
        }
        return n1->_A < n2->_A;
    }
};

// 물통이 세개일 때 가능한 경우의 수는 6개 밖에 없음~
// A->B A->C B->C B->A C->A C->B
void CreateNode(set<Node*, cmp>& result, Node* node)
{
    // A->B
    if (node->_A > 0 && node->_B < fullB)
    {  
        short A, B, C;
        if (node->_A >= fullB - node->_B)
        {
            A = node->_A - (fullB - node->_B);
            B = fullB;
            C = node->_C;
        }
        else
        {
            A = 0;
            B = node->_B + node->_A;
            C = node->_C;
        }

        //printf("A->B: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if(check.second) node->_connect.push_back(newNode);
    }

    // A->C
    if (node->_A > 0 && node->_C < fullC)
    {
        short A, B, C;
        if (node->_A >= fullC - node->_C)
        {
            A = node->_A - (fullC - node->_C);
            B = node->_B;
            C = fullC;
        }
        else
        {
            A = 0;
            B = node->_B;
            C = node->_C + node->_A;
        }
    
        //printf("A->C: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if (check.second) node->_connect.push_back(newNode);
    }

    // B->C
    if (node->_B > 0 && node->_C < fullC)
    {
        short A, B, C;
        if (node->_B >= fullC - node->_C)
        {
            A = node->_A;
            B = node->_B - (fullC - node->_C);
            C = fullC;
        }
        else
        {
            A = node->_A;
            B = 0;
            C = node->_C + node->_B;
        }
        //printf("B->C: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if (check.second) node->_connect.push_back(newNode);
    }

    // B->A
    if (node->_B > 0 && node->_A < fullA)
    {
        short A, B, C;
        if (node->_B >= fullA - node->_A)
        {
            A = fullA;
            B = node->_B - (fullA - node->_A);
            C = node->_C;
        }
        else
        {
            A = node->_A + node->_B;
            B = 0;
            C = node->_C;
        }

        //printf("B->A: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if (check.second) node->_connect.push_back(newNode);
    }

    // C->A
    if (node->_C > 0 && node->_A < fullA)
    {
        short A, B, C;
        if (node->_C >= fullA - node->_A)
        {
            A = fullA;
            B = node->_B;
            C = node->_C - (fullA - node->_A);
        }
        else
        {
            A = node->_A + node->_C; 
            B = node->_B;
            C = 0;
        }

        //printf("C->A: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if (check.second) node->_connect.push_back(newNode);
    }

    // C->B
    if (node->_C > 0 && node->_B < fullB)
    {
        short A, B, C;
        if (node->_C >= fullB - node->_B)
        {
            A = node->_A;
            B = fullB;
            C = node->_C - (fullB - node->_B);
        }
        else
        {
            A = node->_A;
            B = node->_B + node->_C;
            C = 0;
        }

        //printf("C->B: % d % d % d\n", A, B, C);

        Node* newNode = new Node(A, B, C);
        pair<set<Node*, cmp>::iterator, bool> check = result.insert(newNode);
        if (check.second) node->_connect.push_back(newNode);
    }
}

void BFS(set<Node*, cmp>& result, Node* node)
{
    node->_visited = 1;
    queue<Node*> Q;
    Q.push(node);
    result.insert(node);

    while (!Q.empty())
    {
        Node* frontNode = Q.front();
        Q.pop();

        //printf("<%d %d %d>\n", frontNode->_A, frontNode->_B, frontNode->_C);
        CreateNode(result, frontNode);
        //printf("\n");

        vector<Node*>::iterator it = frontNode->_connect.begin();
        for (; it < frontNode->_connect.end(); it++)
        {          
            if ((*it)->_visited== 0)
            {
                (*it)->_visited == 1;
                Q.push((*it));
            }
        }
    }
}

int main()
{
    scanf("%hd", &fullA);
    scanf("%hd", &fullB);
    scanf("%hd", &fullC);

    set<Node*, cmp> result;
    Node* initNode = new Node(0, 0, fullC);
    BFS(result, initNode);
    
    //printf("\n");
    set<Node*>::iterator it = result.begin();
    for (; it != result.end(); it++)
    {
        if ((*it)->_A != 0) break;
        printf("%d ", (*it)->_C);
    }
}
