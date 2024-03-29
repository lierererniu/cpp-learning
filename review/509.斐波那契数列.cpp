//
// Created by 53110 on 2022/8/30.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution509{
public:
    int fib(int n){
        /*第i个数的斐波那契数的值为dp[i]*/
        if(n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
int main(){
    int n;
    cin>>n;
    int res = Solution509().fib(n);
    cout<<res<<endl;
    return 0;
}