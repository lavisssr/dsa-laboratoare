#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }


    ListNode* reverseListRec(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = reverseListRec(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

ListNode* build(const vector<int>& v) {
    ListNode dummy; ListNode* t = &dummy;
    for (int x : v) { t->next = new ListNode(x); t = t->next; }
    return dummy.next;
}
void print(ListNode* h) {
    cout << '[';
    for (; h; h = h->next) cout << h->val << (h->next ? "," : "");
    cout << "]\n";
}

int main() {
    Solution s;
    print(s.reverseList(build({1,2,3,4,5})));
    print(s.reverseListRec(build({1,2,3,4,5})));
    print(s.reverseList(build({1,2})));
    print(s.reverseList(build({})));
    return 0;
}
