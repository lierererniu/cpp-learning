//
// Created by 53110 on 2022/9/15.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution977{
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int size_ = nums.size();
        vector<int> res(size_, 0);
        while(left <= right){
            if(abs(nums[left]) < abs(nums[right])){
                res[--size_] = nums[right] * nums[right];
                right--;
            }else{
                res[--size_] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
    }
};

int main(){
    vector<int> arr = {-4,-1,0,3,10};
    auto res = Solution977().sortedSquares(arr);
    for(auto r: res){
        cout<<r<<" ";
    }

    return 0;
}