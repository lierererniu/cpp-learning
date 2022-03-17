//
// Created by 53110 on 2022/3/17.
//
# include <map>
#include <string>
using namespace std;

class Solution1930 {
public:
    int countPalindromicSubsequence(string s) {
        int n_size = s.size();
        //记录左右字符
        map<char, int> left;
        map<char, int> right;
        map<char, int> res;
        for (int i = 0; i < n_size; ++i){
            if(left.find(s[i]) == left.end()){
                left[s[i]] = i;
            }else{
                right[s[i]] = i;
            }
        }
        int ret = 0;
        for (char i = 'a'; i <= 'z'; ++i){
            if( !left.count(i) || !right.count(i)) continue;
            map<char, int> res;
            int L = left[i], R = right[i];
            for (int j = L + 1; j < R; ++j){
                res[s[j]] = 1;
            }
            ret += res.size();
        }
        return ret;
    }
};