#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode();
        ListNode *nodo = ans;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                nodo->next = list1;
                nodo = nodo->next;
                list1 = list1->next;
            }
            else
            {
                nodo->next = list2;
                nodo = nodo->next;
                list2 = list2->next;
            }
        }
        if (list1 == nullptr)
            nodo->next = list2;
        else if (list2 == nullptr)
            nodo->next = list1;
        return ans->next;
    }
};

int main()
{
    Solution sol;
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode *ans = sol.mergeTwoLists(list1, list2);
    while (ans != nullptr)
    {
        cout << ans->val << " ";
        ans = ans->next;
    }
    return 0;
}
