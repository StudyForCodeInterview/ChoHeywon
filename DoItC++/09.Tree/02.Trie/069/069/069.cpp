#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    Node* child[27] = { nullptr, }; // index 26은 end
};
Node* tree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tree = new Node;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;

        Node* search = tree;
        for (int j = 0; j < input.size(); j++)
        {
            int pos = (char)input[j] - 97;
            if (search->child[pos] == nullptr)
            {
                search->child[pos] = new Node;
            }
            search = search->child[pos];
        }
        search->child[26] = new Node;
    }

    vector<string> ans;
    int cnt = 0;
    for (int i = 0; i < M; i++)
    {
        string input;
        cin >> input;

        bool exist = true;
        Node* search = tree;
        for (int j = 0; j < input.size(); j++)
        {
            int pos = (char)input[j] - 97;
            if (search->child[pos] == nullptr)
            {
                exist = false;
                break;
            }  
            search = search->child[pos];
        }
        if (search->child[26] == nullptr) exist = false;
        if (exist) cnt++;
    }

    cout << cnt;
}

