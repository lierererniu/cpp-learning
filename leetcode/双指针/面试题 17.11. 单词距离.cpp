//
// Created by 53110 on 2022/5/27.
//
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution17 {
public:
    // 双指针
    int findClosest(vector<string>& words, string &word1, string &word2) {
        int index1 = -1;
        int index2 = -1;
        int res;
        for (int i = 0; i < words.size(); ++i) {
            if(words[i] == word1){
                index1 = i;
            }
            if(words[i] == word2){
                index2 = i;
            }
            if(index1 > 0 && index2 > 0){
                res = min(res, abs(index1 - index2));
            }
        }
        return res;
    }
};
