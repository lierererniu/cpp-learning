//
// Created by 53110 on 2022/3/15.
//
/*给定两个有序链表的头指针head1和head2，打印两个链表的公共部分。
 * 如果两个链表的长度之和为N，时间复杂度要求为O（N),额外空间复杂度为O（1）
 * */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct Listnode {
    int val;
    Listnode *next;

    Listnode() : val(0), next(nullptr) {}

    Listnode(int x) : val(x), next(nullptr) {}

    Listnode(int x, Listnode *next) : val(x), next(next) {}
};

class SolutionI{
public:
    Listnode *commonnode(Listnode *head1, Listnode *head2){
        Listnode *ret = nullptr;
        Listnode *dummy = new Listnode(0, ret);
        while (head1 || head2){
            if (head1->val == head2->val){
                ret->next = head1;
                head1 = head1->next;
                head2 = head2->next;
                ret = ret->next;
            } else if (head1->val > head2->val){
                head2 = head2->next;
            } else{
                head1 = head1->next;
            }
        }
        ret->next = nullptr;
        return dummy->next->next;
    }
};

//int main(){
//
//    Listnode *head1 = nullptr;
//    Listnode *head2 = nullptr;
//    Listnode *temp = nullptr;
//    int n_size = 5;
//    for (int i = 1; i < n_size + 1; ++i) {
//        if (!temp) {
//            head1 = temp = new Listnode(i);
//        } else {
//            temp->next = new Listnode(i);
//            temp = temp->next;
//        }
//    }
//}