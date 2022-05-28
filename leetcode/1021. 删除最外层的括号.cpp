//
// Created by 53110 on 2022/5/28.
//
#include <stack>
#include <string>

using namespace std;


class Solution1021 {
public:
    //栈
    string removeOuterParentheses(string s) {
        stack<char> stk;
        string res;
        for(auto st:s){
            if(st == ')'){
                stk.pop();
            }
            if(!stk.empty()){
                res += st;
            }
            if(st == '('){
                stk.push('(');
            }
        }
        return res;
    }
    // 计数
    string removeOuterParenthesesC(string s) {
        int count = 0;
        string res;
        for(auto st:s){
            if(st == ')'){
                count--;
            }
            if(count > 0){
               res += st;
            }
            if(st == '('){
                count++;
            }
        }
        return res;
    }
};