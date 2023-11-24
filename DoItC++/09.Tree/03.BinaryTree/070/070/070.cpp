#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char val;
    Node* left = nullptr;
    Node* right = nullptr;
};
Node nodes[26];

void prev(Node* node)
{
    cout << node->val;
    if (node->left != nullptr) prev(node->left);
    if (node->right != nullptr) prev(node->right);
}

void mid(Node* node)
{
    if (node->left != nullptr) mid(node->left);
    cout << node->val;
    if (node->right != nullptr) mid(node->right);
}

void post(Node* node)
{
    if (node->left != nullptr) post(node->left);
    if (node->right != nullptr) post(node->right);
    cout << node->val;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char val, left, right;
        cin >> val;
        cin >> left;
        cin >> right;

        nodes[(int)val - 65].val = val;
        if (left != '.')  nodes[(int)val - 65].left = &nodes[(int)left - 65];
        if (right != '.') nodes[(int)val - 65].right = &nodes[(int)right - 65];
    }

    prev(&nodes[0]);
    cout << endl;
    mid(&nodes[0]);
    cout << endl;
    post(&nodes[0]);
}

