//
// Created by 53110 on 2022/3/14.
//
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution92 {
public:
    void reverseList(ListNode *head){
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while (cur){
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *virNode = new ListNode(0, head);
        ListNode *temp = virNode;

        //来到left前一个节点
        for (int i = 0; i < left - 1; ++i) {
            temp = temp->next;
        }
        ListNode *rightNode = temp;
        for (int i = 0; i < right - left + 1; ++i) {
            rightNode = rightNode->next;
        }

        ListNode *leftnode = temp->next;
        ListNode *curr = rightNode->next;
        temp->next = nullptr;
        rightNode->next = nullptr;
        reverseList(leftnode);
        temp->next = rightNode;
        leftnode->next = curr;
        return virNode->next;
    }
    ListNode *reverseBetweenHead(ListNode *head, int left, int right){
        ListNode *virNode = new ListNode(0, head);
        ListNode *temp = virNode;
        for (int i = 0; i < left - 1; ++i) {
            temp = temp->next;
        }
        ListNode *cur = temp->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode *next = cur->next;
            cur->next = next->next;
            next->next = temp->next;
            temp->next = next;
        }
        return virNode->next;
    }
};