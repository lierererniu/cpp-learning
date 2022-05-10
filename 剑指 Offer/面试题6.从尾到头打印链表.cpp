//
// Created by 53110 on 2022/5/10.
//
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class Solution6_{
public:
    static void PrintListReversingly_Iteratiovely(ListNode *head){
        if(head == nullptr) return;
        stack<int> stk;
        while(head != nullptr){
            stk.push(head->val);
            head = head->next;
        }
        while(!stk.empty()){
            cout<< stk.top();
        }
    }

    // 栈方法， 修改了原链表
    // vector<int> reversePrint(ListNode* head) {
    //     if(head == NULL){
    //         return {};
    //     }
    //     stack<int> stk;
    //     while(head != NULL){
    //         stk.push(head->val);
    //         head = head->next;
    //     }
    //     vector<int> res;
    //     while(!stk.empty()){
    //         res.push_back(stk.top());
    //         stk.pop();
    //     }
    //     return res;
    // }

    // 递归法


    // vector  insert特性
    vector<int> reversePrint_insert(ListNode* head){
        vector<int> res;
        ListNode *pre = head;
        while(pre){
            res.insert(res.begin(), pre->val);
            pre=pre->next;
        }
        return res;
    }

};