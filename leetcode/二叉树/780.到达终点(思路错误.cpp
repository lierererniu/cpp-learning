//
// Created by 53110 on 2022/4/10.
//
/*给定四个整数sx，sy，tx和ty，如果通过一系列的转换可以从起点(sx, sy)到达终点(tx, ty)，则返回 true，否则返回false。

从点(x, y)可以转换到(x, x+y) 或者(x+y, y)。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reaching-points
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <utility>
using namespace std;

struct Node{
    pair<int, int> val;
    Node *left;
    Node *right;
    Node(): val(make_pair(0, 0)), left(nullptr), right(nullptr) {}
    Node(pair<int, int> val): val(std::move(val)), left(nullptr), right(nullptr) {}
    Node(pair<int, int> val, Node *left, Node *right):val(std::move(val)), left(left), right(right) {}
};

class Solution780 {
public:
    //一开始想用二叉树，发现创建的过程就是找的过程，太复杂，思路错了
//    Node *CreatTree(int sx, int sy, int tx, int ty){
//        Node *head = new Node(make_pair(sx, sy));
//        Node *temp = head;
//        while(temp->val.first != tx || temp->val.second != ty) {
//            pair<int, int> l = make_pair(sx, sx + sy);
//            pair<int, int> r = make_pair(sx + sy, sy);
//
//        }
//        return head;
//    }
    // 辗转相除法
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy && tx != ty) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }
        if (tx == sx && ty == sy) {
            return true;
        } else if (tx == sx) {
            return ty > sy && (ty - sy) % tx == 0;
        } else if (ty == sy) {
            return tx > sx && (tx - sx) % ty == 0;
        } else {
            return false;
        }
    }
};