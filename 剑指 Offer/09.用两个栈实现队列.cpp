//
// Created by 53110 on 2022/5/24.
//
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class CQueue{
private:
    stack<T> stk1;
    stack<T> stk2;
public:
    CQueue();

    void appendTail(const T& val);

    T deleteHead();
};

template<typename T>
CQueue<T>::CQueue() {
    while(!stk1.empty()){
        stk1.pop();
    }
    while(!stk2.empty()){
        stk2.pop();
    }
}

template<typename T>
void CQueue<T>::appendTail(const T &val) {
    stk1.push(val);
}

template<typename T>
T CQueue<T>::deleteHead() {
    // 辅助栈为空时,将栈1的数据压入栈2，用来删除队列头
   if(stk2.size() == 0){
       while(!stk1.empty()){
           T data = stk1.top();
           stk1.pop();
           stk2.push(data);
       }
   }
   // 如果此时stk2仍未空， 则说明此时队列空
   if(stk2.empty()) throw "queue is empyty";
   T head = stk2.top();
   stk2.pop();
   return head;
}

