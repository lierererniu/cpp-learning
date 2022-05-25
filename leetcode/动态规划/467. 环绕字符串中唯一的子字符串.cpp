//
// Created by 53110 on 2022/5/25.
//

#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
using namespace std;

class Solution467{
public:
    bool isContinous(char prev, char curr){
        if(prev == 'z') return curr == 'a';
        return prev + 1 == curr;
    }
    int findSubstringInwarproundString(string p){
        vector<int> dp(26, 0);
        int k = 0;
        for (int i = 0; i < p.size(); ++i) {
            if(i > 0 && isContinous(p[i - 1], p[i])){
                ++k;
            }else{
                k = 1;
            }
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], k);
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
