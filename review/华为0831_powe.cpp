//
// Created by 53110 on 2022/9/1.
//

#include <vector>
#include <iostream>
using namespace std;

int D, N;
vector<int> dis;
vector<int> wait;
/*
 * dp[i][j]: 从第i个充电桩走到终点，剩余公里数为j的时候，最少需要多少时间
 * */
int main(){
    cin>>D;
    cin>>N;
    dis = vector<int>(N + 1, 0);
    wait = vector<int>(N + 1,0);
    for (int i = 1; i <= N; ++i) {
        cin>>dis[i]>>wait[i];
        if(dis[i] - dis[i - 1] > 1000){
            cout<< -1 <<endl;
            return 0;
        }
    }
    if(D - dis[N] > 1000){
        cout<< -1 <<endl;
        return 0;
    }

    /*
     * dp[i][j]
     * d = dis[i + 1] - dis[i]
     * if j > d: 充电或者不充电
     *     min(dp[i + 1][j - d] + d / 100, dp[i + 1][1000 - d] + d/100 + wait[i] + 1);
     * else:  只能充电
     * dp[i + 1][1000 - d] + d / 100 + wait[i] + 1;
     * base case dp[N][j];  //
     * */
    vector<vector<int>> dp(N + 1, vector<int>(1001, 0));
    // 初始化  从第N个站点出发， 剩余公里数为j时 需要的时间
    for (int j = 0; j < 1000; ++j) {
        int d = D - dis[N];
        if(j >= d) dp[N][j] = d / 100;
        else dp[N][j] = d / 100 + wait[N] + 1;
    }
    // 逆推
    for (int i = N - 1; i >= 0; --i) {
        for (int j = 0; j <= 1000; ++j) {
            int d = dis[i + 1] - dis[i];
            if(j >= d){
                // 剩余公里数大于距离  充或者不充
                dp[i][j] = INT_MAX;
                if(dp[i + 1][j - d] != -1) dp[i][j] = min(dp[i][j], dp[i + 1][j - d] + d / 100);
                if(dp[i + 1][1000 - d] != -1) dp[i][j] = min(dp[i][j], dp[i + 1][1000 - d] + d / 100 + wait[i] + 1);
                if(dp[i][j] == INT_MAX) dp[i][j] = -1;
            }
            else{
                // 必须充电
                if(dp[i + 1][1000 - d] == -1) dp[i][j] = -1;
                else{
                    dp[i][j] = dp[i + 1][1000 - d] + d / 100 + wait[i] + 1;
                }
            }
        }
    }
    cout<< dp[0][1000] << endl;
    return 0;
}