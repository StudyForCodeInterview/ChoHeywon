#include <vector>
#include <stack>
using namespace std;
int removeDuplicates(vector<int>& nums) 
{
    int k = 0;
    int start = 0;
    int end = 0;
    int max = nums.size();

    for (;;)
    {
        while (end < max && nums[start] == nums[end])
            end++;

        k++;
        if (k >= max || end >= max) break;
        nums[k] = nums[end];
        start = end;
    }
    return k;
}

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

    ::printf("cnt: %d\n", cnt);

    // 1 2 3 4 5

    ListNode* node = head; // 1
    ListNode* originNext = head->next; // 2

    while (!stk.empty())
    {
        node->next = stk.top();
        stk.pop();
        if (--cnt <= 0) break;
        // case 1: 1->4 // 2->3 // 여기서 stop // if 노드 개수가 짝수 (4)
        // case 2: 1->5 // 2->4 

        node->next->next = originNext;
        if (--cnt <= 0) break;
        // case1: 4->2 
        // case2: 5->2 // 4->3 // 여기서 stop // if 노드 개수가 홀수 (5)

        node = originNext; // 2 
        originNext = node->next; // 3
    }

}

int main()
{
    ListNode* head = new ListNode(0);
    
    ListNode* node = head;
    for (int i = 1; i < 5; i++)
    {
        node->next = new ListNode(i);
    }

    int k = reorderList(head);

    // Result

    ListNode* result = head;
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", result->val);
        result = result->next;
    }
}