//
// Created by 53110 on 2022/3/8.
//
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution1636{
public:
    vector<int> frequencySort(vector<int>& nums) {
        int length = nums.size();
        unordered_map<int , int> fre;
        for (int i = 0; i < length; ++i) {
            fre[nums[i]] += 1;
        }

        sort(nums.begin(), nums.end(), [&](int v1, int v2)->bool {
            if (fre[v1] != fre[v2]){
                return fre[v1] < fre[v2];
            } else{
                return v1 > v2;
            }
        });
        return nums;
    }
};

int main(){
    vector<int> nums = {1,1,2,2,2,3};
    vector<int> ret = Solution1636().frequencySort(nums);
    for (auto &it: ret) {
        cout<<it<<" ";
    }
}