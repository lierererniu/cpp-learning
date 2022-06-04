//
// Created by 53110 on 2022/6/4.
//
#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution929 {
public:
    // 各种库函数
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> temp;
        for(auto& email: emails){
            // 先处理+号，把+号之后的字符直接清理掉
            int pos1 = email.find('@');
            int pos3 = email.find('+');
            if(pos1 > pos3 && pos3 != -1){
                email.erase(pos3, pos1 - pos3);
                //清理完+号， 更新@的位置
                pos1 -= (pos1 - pos3);
            }
            for(int i = 0; i < pos1; ++i){
                if(email[i] == '.') {
                    email.erase(i, 1);
                }
            }
            temp.insert(email);
        }
        return temp.size();
    }
    // 有限状态机
    // state = 0  + 号之前
    // state = 1 + 号之后 @ 之前
    // state = 2 @ 域名部分
    int numUniqueEmails_state(vector<string>& emails) {
        unordered_set<string> temp;
        for(auto &email:emails){
            int state = 0;
            string ss1, ss2;
            for(auto c:email){
                if(c == '+') state = 1;
                if(c == '@') state = 2;
                if(c == '.' && state == 0) continue;
                if(state == 0) ss1 += c;
                else if(state == 2) ss2 += c;
            }
            email = ss1 + ss2;
            temp.insert(email);
        }
        return temp.size();
    }
};
