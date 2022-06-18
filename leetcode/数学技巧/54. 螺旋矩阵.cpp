//
// Created by 53110 on 2022/6/18.
//
#include <vector>

using namespace std;

 class Solution054 {
 public:
     vector<int> spiralOrder(vector<vector<int>>& matrix) {
         int m = matrix.size();
         int n = matrix[0].size();
         if(m == 1 && n == 1) return {matrix[0][0]};
         vector<int> res;
         int up = 0;
         int low = m - 1;
         int left = 0;
         int right = n - 1;
         //
         while(true){
             // 遍历上边界
             for(int i = left; i <= right; ++i){
                 res.push_back(matrix[up][i]);
             }
             // 删掉上边界
             if(++up > low) break;
             // 遍历右边界
             for(int i = up; i <= low; ++i){
                 res.push_back(matrix[i][right]);
             }
             // 删掉右边界
             if(--right < left) break;
             // 遍历下边界
             for(int i = right; i >= left; --i){
                 res.push_back(matrix[low][i]);
             }
             // 删掉下边界
             if(--low < up) break;
             // 遍历左边界
             for(int i = low; i >= up; --i){
                 res.push_back(matrix[i][left]);
             }
             // 删掉右边界
             if(++left > right) break;
         }
         return res;
     }
 };