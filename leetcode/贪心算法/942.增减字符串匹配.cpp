//
// Created by 53110 on 2022/5/9.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // 暴力解法
    vector<int> diStringMatch(const string& s) {
        int maxNum = s.size();
        vector<int> nums(maxNum + 1);
        vector<int> res;
        for(int i = 0; i < maxNum + 1; i++){
            nums[i] = i;
        }
        for(auto &str : s){
            if(str == 'I'){
                res.push_back(*nums.begin());
                nums.erase(nums.begin());
            }
            if(str == 'D'){
                res.push_back(*(nums.end() - 1));
                nums.pop_back();
            }
        }
        res.push_back(nums[0]);
        return res;
    }

    // 优化
    vector<int> diStringMatch1(const string& s){
        int l = 0;
        int R = s.size();
        vector<int> res;
        for(auto &str:s){
            if(str == 'I'){
                res.push_back(l);
                l++;
            }else{
                res.push_back(R);
                R--;
            }
        }
        res.push_back(l);
        return res;
    }
};
