//
// Created by 53110 on 2022/3/18.
//

/*
 * 题目
 * 一种特殊的单链表节点类描述如下：
 class Node{
    int val;
    Node *next;
    Node *rand;
    Node(int x): val(x) {}
};
rand指针是单链表节点结构中新增的指针，rand可能指向链表中的任意一个节点，也有可能
 指向nullptr。给定一个由node节点类型组成的无环单链表的头节点head，请实现一个函数完成这个链表的赋值，并返回复制的新链表的头结点。
 要求：时间复杂度O（N），额外空间复杂度O（1）
 */
#include <map>

using namespace std;

struct Node {
    int val;
    Node *next;
    Node *rand;

    Node(int x) : val(x) {}
};


class SolutionRandnode {
public:
    //解法：哈希表
    /*key为老节点：value（新节点）*/
    static Node *copyListWithRandMap(Node *head) {
        map<Node *, Node *> copy;
        Node *cur = head;
        while (cur) {
            copy[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur) {
            //copy[cur] 新
            //cur
            copy[cur]->next = copy[cur->next];
            copy[cur]->rand = copy[cur->rand];
            cur = cur->next;
        }
        return copy[head];
    }
    //解法2：非哈希表  遍历的方法
    //根据克隆的位置关系，省掉哈希表
    static Node *copyListWith(Node *head){
        if (!head){
            return nullptr;
        }
        Node *cur = head;
        Node *next = nullptr;
        while (cur){
            next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        Node *curCopy = nullptr;
        //克隆节点的rand指向
        while (cur){
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->rand = cur->rand? cur->rand->next: nullptr;
            cur = next;
        }
        //克隆结果
        Node *res = head->next;
        //拆分
        cur = head;
        while (cur){
            next =  cur->next->next;
            curCopy = cur->next;
            cur->next = next;
            curCopy->next = next?next->next: nullptr;
            cur = next;
        }
        return res;
    }

};