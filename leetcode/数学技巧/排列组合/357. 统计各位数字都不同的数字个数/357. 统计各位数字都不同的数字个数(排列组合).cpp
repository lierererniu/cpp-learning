//
// Created by 53110 on 2022/4/11.
//
#include <vector>

using namespace std;
class Solution357 {
public:
    // 排列组合
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        int res = 10;
        int cur = 9;
        for (int i = 0; i < n - 1; ++i) {
            cur = cur * (9 - i);
            res += cur;
        }
        return res;
    }
    // DP(Keyird 推理)
    int countNumbersWithUniqueDigitsRecur(int n) {
        vector<int> dp(9, 0);
        dp[0] = 1;
        dp[1] = 10;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + (dp[i-1]-dp[i-2])*(10-(i-1));
        }
        return dp[n];
    }
};