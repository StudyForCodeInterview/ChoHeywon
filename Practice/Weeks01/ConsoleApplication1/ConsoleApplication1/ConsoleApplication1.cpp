#include <stack>
#include <string>
#include <iostream>
using namespace std;

struct ListNode {

    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

};

void reorderList(ListNode* head) {

    int cnt = 0;
    stack<ListNode*> stk;
    ListNode* next = head->next;
    while (next != nullptr)
    {
        stk.push(next);
        next = next->next;
        cnt++;
    }

    ListNode* node = head;
    ListNode* originNext = nullptr;
    if (node != nullptr) originNext = node->next;

    ListNode* lastNode = head;
    while (originNext != nullptr && !stk.empty())
    {
        node->next = stk.top();
        lastNode = stk.top();
        stk.pop();
        if (--cnt <= 0) break;

        node->next->next = originNext;
        lastNode = originNext;
        if (--cnt <= 0) break;

        node = originNext;
        originNext = node->next;
    }

    lastNode->next = nullptr;
}

int main()
{
    string str = "abcde";
    string str2 = str.substr(1, 0);
    cout << str2;

    /*
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    reorderList(head);

    // Result

    ListNode* result = head;
    printf("%d ", result->val);
    for (int i = 0; i < 3; i++)
    {
        result = result->next;
        printf("%d ", result->val);  
    }
    */
}