#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::bitset<32> markingBit = 1 << 29;

        while (head) {
            std::bitset<32> headval = head->val;
            bool bitMatching = (headval & markingBit).count();
            bool valIsPositive = head->val >= 0;

            if (!(bitMatching ^ valIsPositive)) {
                return true;
            } else {
                headval ^= markingBit;
                head->val = 0;
                for (size_t i = 0; i < 32; i++) {
                    head->val |= headval[i] << i;
                }
                head = head->next;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    bool ans = sol.hasCycle(head);
    cout << boolalpha << ans;

    return 0;
}
