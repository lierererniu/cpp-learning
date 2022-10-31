//
// Created by 53110 on 2022/9/1.
//

#include <iostream>
using namespace std;
//只能动态分配
class A
{
protected:
    A(){}
    ~A(){}
public:
    static A* create(){return new A();}
    void destory(){delete this;}
};

//只能静态分配
class B
{
private:
    void* operator new(size_t t){}          //注意函数的第一个参数和返回值都是固定的
    void operator delete(void* ptr){}       //重载了new就需要重载delete
public:
    B(){}
    ~B(){}
};

int main()
{
    A* a = A::create();
    B b;
    return 0;
}