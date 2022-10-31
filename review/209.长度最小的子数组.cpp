//
// Created by 53110 on 2022/9/15.
//

#include <iostream>
#include <vector>
using namespace std;

/*长度最小的子数组*/
// 双指针 滑动窗口
class Solution209{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int left = 0;
        int sum = 0;
        int minLength = INT_MAX;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            while(sum >= target){
                int length = i - left + 1;
                minLength = min(length, minLength);
                sum -= nums[left++];
            }
        }
        return minLength == INT_MAX? -1 : minLength;
    }
};

int main(){
    vector<int> arr = {2,3,1,2,4,3};
    cout<<Solution209().minSubArrayLen(7, arr);
    return 0;
}