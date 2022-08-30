//
// Created by 53110 on 2022/8/30.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;
/* 题目
 * https://leetcode.cn/problems/word-break/
 * */

class Solution139{
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset(wordDict.begin(), wordDict.end());
        /*dp[i] 代表i长度的字符串由 wordDict 中的一个或多个拼接而成*/
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // 遍历背包
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 0; j < i; ++j){ // 遍历物品  这里指遍历长度i的字符串的再拆分
                string temp = s.substr(j, i -j);
                if(wordset.find(temp) != wordset.end() && dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = Solution139().wordBreak(s, wordDict);
    cout<<result<<endl;
    return 0;
};