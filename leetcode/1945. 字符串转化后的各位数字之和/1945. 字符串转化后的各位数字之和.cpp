//
// Created by Seven on 2022/3/2.
//
#include <string>
#include <iostream>

using namespace std;

class Solution1945 {
public:
    int getLucky(string s, int k) {
        int n_size = s.size();
        int ret = 0;
        int num = 0;
        int temp = 0;
        for (int i = 0;i < n_size; ++i){
            num = s[i] - 'a' + 1;
            ret += num % 10;//个位相加
            ret += num / 10;//10位相加
        }

        while(--k){
            temp = ret;
            ret = 0;
            while(temp){
                ret += temp % 10;
                temp = temp / 10;
            }
        }
        return ret;
    }
};

int main(){
    string s = "asgsadhgdsh";
    int k = 2;
    int result = Solution1945().getLucky(s, k);
    cout << result;
}

