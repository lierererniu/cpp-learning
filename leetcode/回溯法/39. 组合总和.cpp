//
// Created by 53110 on 2022/6/19.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates, target, 0, 0);
        return res;
    }

    void backtracking(vector<int>& candidates, int target, int startIndex, int sum){
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < candidates.size(); ++i){
            if(candidates[i] + sum > target) continue;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i, sum);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};