//
// Created by 53110 on 2022/8/31.
//
#include <vector>
#include <iostream>
#include <numeric>
using namespace std;
/*
 * 题目
 * https://leetcode.cn/problems/last-stone-weight-ii/
 * */

/*
 * dp[i] 容量i的背包最多能装的石头数量
 * 背包容量target = sum / 2;
 * 这道题就是尽量让每个人都拥有一半石头，  最少的方案就是让一个人尽量拿一半的石头
 * */
class Solution1049 {
public:
    int lastStoneWeightII(vector<int>& stones) {
        vector<int> dp(15001, 0);
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;  // 尽量让两个背包相等， 剩下的元素就是结果

        // 第一层  遍历石头
        for(int i = 0; i < stones.size(); ++i){
            // 第二层  遍历背包，逆序，避免重复
            for(int j = target; j >= stones[i]; ++j){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};

int main(){
    vector<int> stones = {31,26,33,21,40};
    int a = Solution1049().lastStoneWeightII(stones);
//    cout<<Solution1049().lastStoneWeightII(stones)<<endl;
    return 0;
}