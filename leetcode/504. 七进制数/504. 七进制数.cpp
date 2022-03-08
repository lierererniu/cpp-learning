//
// Created by 53110 on 2022/3/8.
//
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution504 {
public:
    string convertToBase7(int num) {
        string s = "";
        if (num == 0) { return "0"; }
        bool negative = num < 0;
        num = abs(num);
        while (num) {
            int base7 = num % 7;
            num = num / 7;
            s += to_string(base7);
        }
        if (negative) { s += "-"; }

        reverse(s.begin(), s.end());
        return s;
    }
};

int main() {
    int num = -7;
    string result = Solution504().convertToBase7(num);
    cout << to_string(num) << " 的7进制数为：" << result << endl;
}