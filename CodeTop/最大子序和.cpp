//
// Created by 53110 on 2022/5/12.
//
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution_53{
public:
    static int maxSubArray(vector<int> &nums){
        // 贪心算法
        int result = INT_MIN;
        int temp = 0;
        for(auto &num : nums){
            temp += num;
            result = max(temp, result);
            if(temp < 0){
                temp = 0;
            }
        }
        return result;
    }
    // 动态规划
    static int maxSubArray_dp(vector<int> &nums){
        if(nums.size() == 1) return nums[0];
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if(dp[i - 1] > 0){
                dp[i] = dp[i - 1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
            res = max(dp[i], res);
        }
        return res;
    }
    //动态规划  优化空间
    static int maxSubArray_dp_mem(vector<int> &nums){
        int res = nums[0];
        int pre = 0;
        for (auto &num: nums) {
            pre = max(num, pre + num);
            res = max(res, pre);
        }
        return res;
    }

    // 分治算法
    /***********************************/
    // 打印最大子数组和
    int storeMaxSubArray(vector<int> &nums){
        int res = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int start = 0;
        int length = 1;
        int maxStart = 0, maxLen = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if(dp[i - 1] > 0){
                dp[i] = dp[i - 1] + nums[i];
                length += 1;
            }else{
                //更新了子数组的开始
                dp[i] = nums[i];
                length = 1;
                start = i;
            }
            if(dp[i] > res){
                res = dp[i];
                maxStart = start;
                maxLen = length;
            }
        }
        // maxArray.resize(maxLen);
        for(int i = maxStart; i < maxStart + maxLen; ++i){
            maxArray.push_back(nums[i]);
        }
        return res;
    }

    vector<int> maxArray;
};

int main(){
    Solution_53 s = Solution_53();
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = s.storeMaxSubArray(nums);
    cout<< res <<endl;
    for (auto &num: s.maxArray) {
        cout<< num << " ";
    }
    return 0;
}