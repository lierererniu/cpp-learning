//
// Created by 53110 on 2022/3/10.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        auto *dummy = new ListNode(0, head);
        ListNode *temp = head;
        ListNode *r = dummy;
        int length = 0;
        while (temp) {
            length++;
            temp = temp->next;
        }
        for (int i = 0; i < length - n; ++i) {
            r = r->next;
        }
        r->next = r->next->next;
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};

int main() {
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    int n_size = 5;
    for (int i = 1; i < n_size + 1; ++i) {
        if (!temp) {
            head = temp = new ListNode(i);
        } else {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
    }

    int n = 2;
    ListNode *result = Solution19().removeNthFromEnd(head, n);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}