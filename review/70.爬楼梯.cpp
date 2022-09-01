//
// Created by 53110 on 2022/8/30.
//
#include <vector>
#include <iostream>
using namespace std;
/* 题目：
 * https://leetcode.cn/problems/climbing-stairs/
 * */

class Solution70{
public:
    int climbStairs(int n){
        if(n <= 1) return n;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main(){
    int n;
    cin>>n;
    cout<<Solution70().climbStairs(n)<<endl;
    return 0;
}