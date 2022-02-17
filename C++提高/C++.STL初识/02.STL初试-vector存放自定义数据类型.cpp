//
// Created by Seven on 2022/2/17.
//

//
// Created by Seven on 2022/2/17.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

class Person {
public:
    Person(string name, int age) {
        this->m_name = name;
        this->m_Age = age;
    }

    string m_name;
    int m_Age;
};

void myP(Person a) {
    cout << "姓名：" << a.m_name << "年龄" << a.m_Age << endl;
}

void test2521() {
    vector<Person*> v;
    Person p1("aaaa", 10);
    Person p2("bbbb", 20);
    Person p3("cccc", 30);
    Person p4("eeee", 40);
    Person p5("dddd", 50);

    //向容器中添加数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person*>::iterator it = v.begin();  it != v.end() ; it++) {
        cout << "##姓名：" << (*it)->m_name << " 年龄" << (*it)->m_Age << endl;
    }
}

void test2522() {
    vector<Person> v;
    Person p1("aaaa", 10);
    Person p2("bbbb", 20);
    Person p3("cccc", 30);
    Person p4("eeee", 40);
    Person p5("dddd", 50);

    //向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<Person>::iterator it = v.begin();  it != v.end() ; it++) {
        cout << "##姓名：" << it->m_name << " 年龄" << it->m_Age << endl;
    }
}
//int main()
//{
//    system("chcp 65001");
//    test2522();
//    system("pause");
//    return 0;
//}