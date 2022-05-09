//
// Created by 53110 on 2022/5/9.
//

#include<unordered_set>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class Solution433{
public:
    int minMutation(string start, string end, vector<string>& bank){
        unordered_set<string> rem;
        int res = 0;
        queue<string> que;
        que.push(start);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                string cur = que.front();
                que.pop();
                if(cur == end){
                    return res;
                }
                for(auto &s:{'A', 'C', 'G', 'T'}){
                    for(int j = 0; j < cur.size(); ++j){
                        string next = cur;
                        next[j] = s;
                        if(find(bank.begin(), bank.end(), next) != bank.end() && !rem.count(next)){
                            que.push(next);
                            rem.insert(next);
                        }
                    }
                }
            }
            res++;
        }
        return -1;
    }
};
