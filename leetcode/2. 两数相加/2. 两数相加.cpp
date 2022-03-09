//
// Created by 53110 on 2022/3/9.
//
#include <string>
#include <iostream>
#include<random>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = nullptr;//记录结果的首结点
        ListNode *tail = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            //非对其补0
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            if (!head) {
                head = tail = new ListNode(sum % 10);
            } else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            carry = sum / 10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry > 0) {
            tail->next = new ListNode(carry);
            tail = tail->next;
        }
        return head;
    }
};

void Myprint(ListNode *result){
    while (result){
        cout<<result->val<<" ";
        result = result->next;
    }
    cout<<endl;
}

int main() {
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *head1 = nullptr;
    ListNode *head2 = nullptr;
    int num_node1 = 7;//第一个结点节点数
    int num_node2 = 7;//第二个链表节点数
    for (int i = 0; i < num_node1; ++i) {
        if (!l1) {
            l1 = head1 = new ListNode(rand()%(10));
        }
        head1->next = new ListNode(rand()%(10));
        head1 = head1->next;
    }

    for (int i = 0; i < num_node2; ++i) {
        if (!l2) {
            l2 = head2 = new ListNode(rand()%(10));
        }
        head2->next = new ListNode(rand()%(10));
        head2 = head2->next;
    }
    cout<<"l1链表元素为：";
    Myprint(l1);
    cout<<"l2链表元素为：";
    Myprint(l2);
    cout<<"----------------------------"<<endl;
    ListNode *result = Solution2().addTwoNumbers(l1, l2);
    cout<<"两数相加结果为：";
    Myprint(result);
    return 0;
}