//
// Created by 53110 on 2022/6/12.
//
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution890 {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto&word:words){
            unordered_map<char, char> W;
            unordered_map<char, char> P;
            bool flag = true;
            for(int i = 0; i < pattern.size(); ++i){
                if((W.count(word[i]) && W[word[i]] != pattern[i]) || (P.count(pattern[i]) && P[pattern[i]] != word[i])){
                    flag = false;
                    break;
                }
                W[word[i]] = pattern[i];
                P[pattern[i]] = word[i];
            }
            if(flag){
                res.push_back(word);
            }
        }
        return res;
    }
};