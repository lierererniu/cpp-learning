//
// Created by 53110 on 2022/3/24.
//

/*题目
 * 给定两个可能有环也可能无环的单链表，头节点head1和head2。
 * 请实现一个函数，如果两个链表相交，请返回相交的第一个节点。如果不想交，返回null
 */
//要求：如果两个链表长度之和为N，时间复杂度为O（N），额外空间复杂度请达到O（1）
//以下所有算法均为O（N）复杂度
#include <iostream>

using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next){}
};

class SolutionIsPar{
private:
    //  判断是否有环，并返回入环节点
    // 找到链表第一个入环节点，如果无环，返回null
    /*- 同时从头位置出发，如果快指针最后指向空，则不存在环
    - 如果两个指针最后相遇，快指针回到头结点，慢指针不动，继续前进（两指针此时均前进一步）
    - 如果快慢指针相遇，则该节点即为环的第一个节点。*/
    ListNode *getLoopNode(ListNode *head){
        if(head == nullptr || head->next == nullptr || head->next->next = nullptr){
            return nullptr;
        }
        ListNode *n1 = head->next;
        ListNode *n2 = head->next->next;
        while(n1 != n2){
            //如果存在结尾，没有有环链表
            if(n2->next == nullptr || n2->next->next == nullptr){
                return nullptr;
            }
            n2 = n2->next->next;
            n1 = n1->next;
        }

        // 每次走一步
        n2 = head;
        while(n1 != n2){
            n2 = n2->next;
            n1 = n1->next;
        }
        // 返回入环节点
        return n1;
    }
public:
    // 找到两链表(无环)相交的第一个节点, 有环链表和无环链表不可能相交
    /*1. 先判断两链表是否相交

   - 遍历两个链表head1，head2并记录长度，len1，len2
   - 判断两个链表终节点是否相同，如果相同，两链表必相交

    2. 寻找两链表相交节点

   - **技巧**

   - 长链表先走|len1 - len2|步

   - 然后，长短链表同时走（步进1）

   - 如果相等，必然是相交节点的第一个节点。
     */

    ListNode *CrossNodeNoLoop(ListNode *head1, ListNode *head2){
        if(head1 == nullptr || head2 == nullptr){
            return nullptr;
        }
        ListNode *cur1 = head1;
        ListNode *cur2 = head2;
        int n = 0;
        while (cur1->next != nullptr){
            n++;
            cur1 =  cur1->next;
        }
        while (cur2->next != nullptr){
            n--;
            cur2 = cur2->next;
        }
        if(cur1 != cur2){
            return nullptr;
        }
        // n = len1 - len2(链表1 - 链表2）
        cur1 = n > 0 ? head1: head2; //谁长谁做为头结点cur1
        cur2 = cur1 == head1? head2: head1; //谁短，谁的头变成cur2
        n = abs(n);
        //长链表先走差值步
        while(n != 0){
            n--;
            cur1 = cur1->next;
        }
        //同时走一步
        while(cur1 != cur2){
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    // loop1，2为环节点
    ListNode *bothLoop(ListNode *head1, ListNode *loop1, ListNode *head2, ListNode *loop2){
        ListNode *cur1 = nullptr;
        ListNode *cur2 = nullptr;
        if (loop1 == loop2){
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while(cur1 != loop1){
                n ++;
                cur1 = cur1->next;
            }
            while(cur2 != loop2){
                n --;
                cur2 = cur2->next;
            }
            cur1 = n > 0? head1:head2;
            cur2 = cur1 == head1? head2:head1;
            n = abs(n);
            while(n != 0){
                n --;
                cur1 = cur1->next;
            }
            while(cur1 != cur2){
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        }else{
            // 第三种情况，两个环起点不同
            cur1 = loop1->next;
            while(cur1 != loop1){
                if (cur1 == loop2){
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return nullptr;
        }
    }
    //
    ListNode *getIntersectNode(ListNode *head1, ListNode *head2){
        if (head1 == nullptr || head2 == nullptr){
            return nullptr;
        }
        ListNode *loop1 = getLoopNode(head1);
        ListNode *loop2 = getLoopNode(head2);
        // 两个无环链表相交问题
        if (loop1 == nullptr && loop2 == nullptr){
            return CrossNodeNoLoop(head1, head2);
        }
        // 两个有环链表的相交问题
        if (loop1 != nullptr && loop2 != nullptr){
            return bothLoop(head1, loop1, head2, loop2);
        }
        // 不存在相交节点
        return nullptr;
    }
};

