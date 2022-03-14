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

class Solution206 {
public:
    //暴力解法
    ListNode* reverseList(ListNode* head) {
        ListNode *res = new ListNode(0, head);
        ListNode *temp = head;
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        for(int j = nums.size() - 1; j > -1; --j){
            temp->val = nums[j];
            temp = temp->next;
        }
        return res->next;
    }

    //迭代法
    ListNode* reverseListiter(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *temp = head;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
    //递归法
    ListNode* reverseListFib(ListNode* head) {
        //递归基
        if (!head || !head->next){
            /*
             *  以链表1->2->3->4->5举例
                直到当前节点的下一个节点为空时返回当前节点
                由于5没有下一个节点了，所以此处返回节点5
             */
            return head;
        }
        ListNode* newHead = reverseListFib(head->next);
        /*
            第一轮出栈，head为5，head.next为空，返回5
            第二轮出栈，head为4，head.next为5，执行head.next.next=head也就是5.next=4，
                      把当前节点的子节点的子节点指向当前节点
                      此时链表为1->2->3->4<->5，由于4与5互相指向，所以此处要断开4.next=null
                      此时链表为1->2->3->4<-5
                      返回节点5
            第三轮出栈，head为3，head.next为4，执行head.next.next=head也就是4.next=3，
                      此时链表为1->2->3<->4<-5，由于3与4互相指向，所以此处要断开3.next=null
                      此时链表为1->2->3<-4<-5
                      返回节点5
            第四轮出栈，head为2，head.next为3，执行head.next.next=head也就是3.next=2，
                      此时链表为1->2<->3<-4<-5，由于2与3互相指向，所以此处要断开2.next=null
                      此时链表为1->2<-3<-4<-5
                      返回节点5
            第五轮出栈，head为1，head.next为2，执行head.next.next=head也就是2.next=1，
                      此时链表为1<->2<-3<-4<-5，由于1与2互相指向，所以此处要断开1.next=null
                      此时链表为1<-2<-3<-4<-5
                      返回节点5
            出栈完成，最终头节点5->4->3->2->1
         */
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};

