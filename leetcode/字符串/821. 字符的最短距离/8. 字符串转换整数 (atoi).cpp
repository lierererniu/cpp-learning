//
// Created by 53110 on 2022/5/25.
//
#include <string>
#include <climits>

using namespace std;

class Solution08 {
public:
    int myAtoi(string s) {
        bool isP = true;
        int res = 0;
        int p = 0;
        int temp = 0;
        while(p < s.size() && isblank(s[p])) p++;
        if(s[p] == '-'){
            isP = false;
            p++;
            temp ++;
        }
        if(s[p] == '+'){
            isP = true;
            p++;
            temp++;
        }
        if(temp > 1) return 0;
        while(p < s.size() && isdigit(s[p])){
            int digit = s[p] - '0';
            if (res > INT_MAX / 10){
                return isP ? INT_MAX : INT_MIN;
            }
            if (res == INT_MAX / 10 && isP && digit >= INT_MAX % 10){
                return INT_MAX;
            }
            if (res == INT_MAX / 10 && !isP && digit >= -1 * (INT_MIN % 10)){
                return INT_MIN;
            }
            res = res * 10 + digit;
            p++;
        }
        return isP ? res: -1 * res;
    }
};