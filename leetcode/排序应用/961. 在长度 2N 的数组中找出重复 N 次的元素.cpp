//
// Created by 53110 on 2022/5/21.
//
#include <vector>
#include <algorithm>
using namespace std;
 class Solution {
 public:
     // 排序法
     int repeatedNTimes(vector<int>& nums) {
         int n = nums.size() / 2;
         sort(nums.begin(), nums.end());
         if(nums[n] != nums[n + 1]) return nums[n - 1];
         return nums[n];
     }
     // 数学规律
     int repeatedNTimes_(vector<int>& nums) {
         const int N = nums.size();
         for (int i = 0; i < nums.size() - 1; ++i) {
             for (int j = 1; j <= 3 && i + j < N; ++j) {
                 if (nums[i] == nums[i + j])
                     return nums[i];
             }
         }
         return -1;
     }
 };
