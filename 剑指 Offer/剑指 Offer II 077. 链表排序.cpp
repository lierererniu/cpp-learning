//
// Created by 53110 on 2022/3/19.
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}

    ListNode() : val(0), next(nullptr) {}
};

class SolutionNodeSort {
public:
    ListNode *FindMid(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr; //切断左右节点
        return mid;
    }

    ListNode *merge(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while (head1 && head2) {
            if (head1->val < head2->val) {
                temp = temp->next = head1;
                head1 = head1->next;
            } else {
                temp = temp->next = head2;
                head2 = head2->next;
            }
        }
        //如果一个没比完，直接接上
        if (head1) temp->next = head1;
        if (head2) temp->next = head2;
        return dummy->next;
    }

    ListNode *SortListNode(ListNode *head) {
        //不需要排序
        if (!head || !head->next) {
            return head;
        }
        ListNode *Left = head;
        ListNode *Right = FindMid(head);
        //左右链表各自递归
        Left = SortListNode(Left);
        Right = SortListNode(Right);
        return merge(Left, Right);
    }
};

void test() {
    int arr[7] = {4, 6, 3, 5, 8, 5, 2};
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    for (int i: arr) {
        if (!temp) {
            temp = head = new ListNode(i);
        } else {
            temp->next = new ListNode(i);
            temp = temp->next;
        }
    }
    ListNode *ret = SolutionNodeSort().SortListNode(head);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

int main() {
    test();
    return 0;
}