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

//归并排序
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

//快速排序方法
class SolutionNodeQuicksort{
public:
    bool equal(ListNode *head){
        int head_val = head->val;
        ListNode *temp = head->next;
        while(temp != nullptr){
            if (temp->val != head_val) return false;
            temp = temp->next;
         }
        return true;
    }
    ListNode *swap(ListNode *a, ListNode *b, ListNode *prea, ListNode *preb){
        ListNode *temp = a->next;
        a->next = b->next;
        b->next = temp;
        if (prea != nullptr) prea->next = b;
        if (preb != nullptr) preb->next = a;
        return b;
    }
    //交换头结点和中间节点
    ListNode * SwapMid(ListNode *preh, ListNode *head){
        if (head == nullptr || head->next == nullptr){
            return head;
        }
        //快慢指针
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //两个元素的情况下，不需要交换
        return slow == head? head: swap(head, slow->next, preh, slow);
    }

    ListNode * ListnodeQuickSort(ListNode *head){
        ListNode *pre = new ListNode(-1, head);
        return mySortList(pre, head);
    }
    ListNode *mySortList(ListNode *pre, ListNode *head){
        if (head == nullptr || head->next == nullptr) return head;
        // 当待排序链表val全部相等直接输出
        if (equal(head)) return head;
        //交换head和mid节点，以mid节点为基准进行分割
        head = SwapMid(pre, head);

        //记录此时的头结点及其val值，进行分割
        ListNode *p = head;
        int val = head->val;
        ListNode *temp1 = head;
        ListNode *temp2 = head->next;
        while(temp2){
            if (temp2->val < val){
                ListNode *ptr = temp2->next;
                temp2->next = head;
                head = temp2;
                temp1->next = ptr;
                temp2 = ptr;
            } else{
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        //排序后面的链表
        p->next = mySortList(p,p->next);
        //p前面没有了，直接输出
        if (p == head) return p;

        //否则排序前面的
        temp1 = head;
        while(temp1->next != p){
            temp1 = temp1->next;
        }
        temp1->next = nullptr;
        head = mySortList(pre, head);

        //连接两端链表
        temp1 = head;
        while(temp1->next){
            temp1 = temp1->next;
        }
        temp1->next = p;
        return head;
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
    // ListNode *ret = SolutionNodeSort().SortListNode(head);
    ListNode *ret = SolutionNodeQuicksort().ListnodeQuickSort(head);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
}

int main() {
    test();
    return 0;
}