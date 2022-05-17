//
// Created by 53110 on 2022/5/17.
//

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution953{
public:
    // 字符映射
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mapping;
        for (int i = 0; i < order.size(); ++i) {
            mapping[order[i]] = i;
        }
        vector<string> newWords;
        for (auto &word:words) {
            string temp;
            for(auto &s : word){
                temp += (mapping[s] + 'a');
            }
            newWords.push_back(temp);
        }
        return is_sorted(newWords.begin(), newWords.end());
    }

    // 节省内存
    bool isAlienSorted_low(vector<string>& words, string order){
        unordered_map<char, int> mapping;
        for (int i = 0; i < order.size(); ++i) {
            mapping[order[i]] = i;
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            string pre = words[i];
            string cur = words[i + 1];
            bool is_low = false;
            for (int j = 0; j < min(pre.size(), cur.size()); ++j) {
                if(mapping[pre[j]] < mapping[cur[j]]){
                    is_low = true;
                    break;
                }else if (mapping[pre[j]] > mapping[cur[j]]){
                    return false;
                }
            }
            if(!is_low && (pre.size() > cur.size())){
                return false;
            }
        }
        return true;
    }
};