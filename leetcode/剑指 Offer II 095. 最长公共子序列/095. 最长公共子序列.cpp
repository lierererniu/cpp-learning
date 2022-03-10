//
// Created by 53110 on 2022/3/10.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution095 {
public:
    //递归法
    int longestCommonSubsequenceFib(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        if (n == 0 || m == 0) {
            return 0;
        }
        if (text1[0] == text2[0]) {
            return longestCommonSubsequenceFib(text1.substr(1), text2.substr(1)) + 1;
        } else {
            return longestCommonSubsequenceFib(text1.substr(1), text2) >
                   longestCommonSubsequenceFib(text1, text2.substr(1)) ?
                   longestCommonSubsequenceFib(text1.substr(1), text2) :
                   longestCommonSubsequenceFib(text1, text2.substr(1));
        }
    }
    //动态规划
    int longestCommonSubsequence(string text1, string text2){
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            char c1 = text1.at(i - 1);
            for (int j = 1; j <= n; ++j) {
                char c2 = text2.at(j - 1);
                if (c1 == c2){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};


int main() {
    string text1 = "oxcpqrsvwf";
    string text2 = "shmtulqrypy";
    int result = Solution095().longestCommonSubsequence(text1, text2);
    cout << result << endl;
}