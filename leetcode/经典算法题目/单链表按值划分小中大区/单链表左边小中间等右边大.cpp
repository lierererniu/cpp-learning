//
// Created by 53110 on 2022/3/18.
//
#include <iostream>
/*
 * 中链表：等于区
 * 左链表：小于区
 * 右链表：大于区
 * */
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class SolutionPar {
public:
    ListNode *listPartition(ListNode *head, int pivot) {
        //小于部分的头和尾
        ListNode *sH = nullptr;
        ListNode *sT = nullptr;
        //等于部分的头和尾
        ListNode *eH = nullptr;
        ListNode *eT = nullptr;
        //大于部分的头和尾
        ListNode *mH = nullptr;
        ListNode *mT = nullptr;
        //存储下一个节点
        ListNode *next = nullptr;
        while (head) {
            next = head->next;
            head->next = nullptr;
            if (head->val < pivot) {
                //第一次碰到，更新左链表头   否则更新尾部
                if (sH == nullptr) {
                    sH = head;
                    sT = head;
                } else {
                    sT->next = head;
                    sT = head;
                }
            } else if (head->val == pivot) {
                if (eH == nullptr) {
                    eH = head;
                    eT = head;
                } else {
                    eT->next = head;
                    eT = head;
                }
            } else {
                if (mH == nullptr) {
                    mH = head;
                    mT = head;
                } else {
                    mT->next = head;
                    mT = head;
                }
            }
            head = next;
        }
        //左链表存在，选择谁去接右链表
        if (sT) {

            sT->next = eH;
            // 中链表不存在，左链表去接
            eT = eT == nullptr ? sT : eT; //谁去连右链表（大于区）
        }
        //中链表存在，直接接入右链表
        if (eT) {
            eT->next = mH;
        }
        //判断哪个链表存在
        return sH ? sH : (eH ? eH : mH);
    }
};

void testPar() {
    int arr[7] = {4, 6, 3, 5, 8, 5, 2};
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    for (int i = 0; i < 7; ++i) {
        if (!temp) {
            temp = head = new ListNode(arr[i]);
        } else {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
    }
    ListNode *ret = nullptr;
    ret = SolutionPar().listPartition(head, 5);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

int main() {
    testPar();
    return 0;
}