//
// Created by 53110 on 2022/9/17.
//

#include <vector>
#include <string>
#include <iostream>
using namespace std;


bool isValid(char s, int index, string& str){
    if(index == 0 && index + 1 < str.size()){
        if(str[index] == str[index + 1]){
            return false;
        }
    }
    if(index > 0 && index < str.size() - 1){
        if(str[index] == str[index + 1] || str[index] == str[index - 1]){
            return false;
        }
    }
    if(index == str.size() - 1 && index - 1 >= 0){
        if(str[index] == str[index - 1]){
            return false;
        }
    }
    return true;
}

bool isThree(string s){
    int num = 0;
    for (auto a:s) {
        num += a - '0';
    }
    if(num % 3 == 0) return true;
    return false;
}

void backtracking(string &str, int startIndex, string& temp){
    if(startIndex >= str.size()){
        if(str < temp && isThree(str)){
            temp = str;
            return;
        }
        return;
    }
    for (int i = startIndex; i < str.size(); ++i) {
        if(str[i] >= '0' && str[i] <= '9') continue;

        for (char j = '0'; j < '9'; ++j) {
            if(i == 0 && str[i] == '?' && j == '0') continue;
            str[i] = j;
            if(i < str.size() - 1 && str.substr(0, i + 1) > temp.substr(0, i + 1)) continue;
            if(isValid(j, i, str)){
                backtracking(str, i + 1, temp);
            }
            str[i] = '?';
        }
    }
}

int main(){
    string str;
    cin>>str;
    string temp(str.size(), '9');
    backtracking(str, 0, temp);
    cout<< temp;
    return 0;
}