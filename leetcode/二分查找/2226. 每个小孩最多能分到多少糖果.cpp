//
// Created by 53110 on 2022/6/7.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution2226 {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(auto &candie:candies){
            sum += candie;
        }
        if(sum < k) return 0;
        int left = 1;
        int right = *max_element(candies.begin(), candies.end()) + 1;
        while(left != right){
            int mid = left + (right - left) / 2;
            long long kk = 0;
            for(auto&candie: candies){
                kk += candie / mid;
            }
            // 如果能分的人少了， 则减少右边界
            if(kk < k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return right - 1;
    }
};