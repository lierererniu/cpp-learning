//
// Created by Seven on 2022/2/17.
//
#include "string"
#include "iostream"

using namespace std;

class Solution1576{
public:
    string modifyString(string s){
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'c'; ++ch) {
                    if ((i > 0 && s[i - 1] == ch) || (i < n - 1 && s[i + 1] == ch)) {
                        continue;
                    }
                    s[i] = ch;
                    break;
                }
            }
        }
        return s;
    }
};

void m_Pri(string s)
{
    for (int i = 0; i < s.size(); i++) {
        cout<<s[i]<<" ";
    }
}

void test1576()
{
    for (int number = 1; number <= 5; ++number)
        cout << number << " ";
    cout<<endl;

    for (int number = 1; number <= 5; number++)
        cout << number << " ";
}

int main()
{
    Solution1576 a;
    string mystr = "asfas?fsag";
    string s = a.modifyString(mystr);
    m_Pri(s);
    test1576();
    return 0;
}