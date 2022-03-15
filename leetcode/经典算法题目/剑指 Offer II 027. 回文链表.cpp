//
// Created by 53110 on 2022/3/15.
//

#include <stack>

using namespace std;

struct Listnode{
    int val;
    Listnode *next;
    Listnode(int x): val(x), next(nullptr){}
    Listnode(): val(0), next(nullptr){}
    Listnode(int x, Listnode *next): val(x), next(next){}
};

class Solution027 {
public:
    //栈  入栈后，出栈为逆序，依次对比 额外空间n
    bool isPalindromestack(Listnode* head) {
        stack<Listnode*> stk;
        Listnode *temp = head;
        while(head){
            stk.push(head);
            head = head->next;
        }
        while(temp){
            if(stk.top()->val != temp->val){
                return false;
            }
            temp = temp->next;
            stk.pop();
        }
        return true;
    }

    //快慢指针 n/2额外空间
    bool isPalindromestackSF(Listnode* head){
        //如果链表为空， 或者元素个数为1
        if(!head || !head->next){
            return true;
        }
        Listnode *right = head->next;
        Listnode *cur = head;

        //下一个为空，到达终点，停止循环，下下个为空、
        //慢指针在快指针结束时到中点后的元素，
        while (cur->next && cur->next->next){
            right = right->next;
            cur = cur->next->next;
        }
        stack<Listnode*> s;
        while (right){
            s.push(right);
            right = right->next;
        }
        while (!s.empty()){
            if (head->val!= s.top()->val){
                return false;
            }
            head = head->next;
            s.pop();
        }
        return true;
    }
    // 0(1)额外空间复杂度
    bool isPalindromeO1(Listnode* head){
        //如果链表为空， 或者元素个数为1
        if(!head || !head->next){
            return true;
        }
        Listnode *n1 = head;
        Listnode *n2 = head;
        while (n2->next && n2->next->next){
            n1 = n1->next; //mid
            n2 = n2->next->next; //n2->end
        }
        n2 = n1->next;
        n1->next = nullptr;
        Listnode *n3 = nullptr;
        //逆序， 后半部分反转
        while(n2){
            n3 = n2->next; //n3 保存下一个节点
            n2->next = n1; //
            n1 = n2;
            n2 = n3;
        }
        n3 = n1;  //n3  保存最后一个节点
        n2 = head;  // 左边第一个节点
        bool res = true;
        while (n1 && n2){
            if (n1->val != n2->val){
                res = false;
                break;
            }
            n1 = n1->next;
            n2 = n2->next;
        }
        n1 = n3->next;
        n3->next = nullptr;
        //翻转回来
        while (n1){
            n2 = n1->next;
            n1->next = n3;
            n3 = n1;
            n1 = n2;
        }
        return res;
    }
};