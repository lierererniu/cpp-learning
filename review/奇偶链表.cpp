//
// Created by 53110 on 2022/9/18.
//

/*
 * 给定一个单链表，使得链表中奇数位于偶数之前。
    解析：快排的思想，设置两个指针，p指向下一个或第一个奇数位置，
    q指向当前位置，每当q移动一位时，判断p指向的元素是否为奇数，
    如果是奇数，则q位置的元素和p下一位置的元素交换，p1更新为q->next。
    保持head始终在队头；
    如果是偶数，则q,p直接下移一位。时间复杂度为o(n)。
 *
*/
#include <iostream>
#include <ctime>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode():val(0), next(nullptr){}
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next): val(val), next(next){}
};

ListNode* oddEvenList(ListNode* head){
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* q = head;
    ListNode* p = head->next;
    while(p){
        if(p->val & 1){
            q->next=p->next;
            p->next=head;
            head=p;
            p=q->next;
        }else{
            q=p;
            p=p->next;
        }
    }
    return head;
}


int main(){
    // 建链表
    ListNode *head = nullptr;
    ListNode *temp = nullptr;
    int n_size = 10;
    srand(time(NULL));
    for (int i = 0; i < n_size + 1; ++i) {

        int val = rand() % 10;
        if (!temp) {
            head = temp = new ListNode(val);
        } else {
            temp->next = new ListNode(val);
            temp = temp->next;
        }
    }
    ListNode* res = oddEvenList(head);
    while(res){
        cout<< res->val<<" ";
        res = res->next;
    }
    return 0;
}