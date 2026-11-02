#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        return a;
    }
};

int main() {
    Solution s;

    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);
    c1->next->next = new ListNode(5);
    ListNode* A = new ListNode(4);
    A->next = new ListNode(1);
    A->next->next = c1;
    ListNode* B = new ListNode(5);
    B->next = new ListNode(6);
    B->next->next = new ListNode(1);
    B->next->next->next = c1;
    ListNode* r = s.getIntersectionNode(A, B);
    if (r) cout << "Intersected at " << r->val << '\n'; else cout << "No intersection\n";


    ListNode* A2 = new ListNode(2); A2->next = new ListNode(6); A2->next->next = new ListNode(4);
    ListNode* B2 = new ListNode(1); B2->next = new ListNode(5);
    r = s.getIntersectionNode(A2, B2);
    if (r) cout << "Intersected at " << r->val << '\n'; else cout << "No intersection\n";
    return 0;
}
