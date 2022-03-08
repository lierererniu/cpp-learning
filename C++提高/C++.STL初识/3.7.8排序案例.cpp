//
// Created by 53110 on 2022/3/8.
//
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Person {
public:
    Person(string name, int age, int height) {
        this->m_name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_name;
    int m_Age;
    int m_Height;
};


void test01() {
    list<Person> L;
    //准备数据
    Person p1("刘备", 35, 175);
    Person p2("曹操", 45, 180);
    Person p3("孙权", 40, 170);
    Person p4("赵云", 25, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);
    //插入数据
    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    for (auto &it: L) {
        cout << "姓名：" << it.m_name << " ";
        cout << "年龄：" << it.m_Age << " ";
        cout << "身高：" << it.m_Height << " " << endl;
    }
    //排序
    cout << "-------------------------------" << endl;
    cout << "排序后：" << endl;
    L.sort([=](Person &v1, Person &v2) -> bool {
        if (v1.m_Age == v2.m_Age) {
            return v1.m_Height > v2.m_Height;
        } else {
            return v1.m_Age < v2.m_Age;
        }
    });
    for (auto &it: L) {
        cout << "姓名：" << it.m_name << " ";
        cout << "年龄：" << it.m_Age << " ";
        cout << "身高：" << it.m_Height << " " << endl;
    }
}

int main() {
    test01();
    return 0;
}