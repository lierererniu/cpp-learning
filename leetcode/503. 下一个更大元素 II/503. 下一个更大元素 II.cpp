//
// Created by 53110 on 2022/3/20.
//
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    // 遍历的方法, leetcode中超时了。。。
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n_size = nums.size();
        vector<int> ret(n_size);
        vector<int> temp(n_size, -1);
        for(int i = 0; i < n_size; i++){
            for(int j = i + 1; j < n_size * 2 - 1; j++){
                if((nums[i] < nums[j % n_size]) && temp[i] == -1){
                    ret[i] = nums[j % n_size];
                    temp[i] = 1;
                }
            }
            if(temp[i] == -1){
                ret[i] = -1;
            }
        }
        return ret;
    }
    // 单调栈
    vector<int> nextGreaterElementsStk(vector<int>& nums) {
        int n_Size = nums.size();
        stack<int> stk;
        //如果没找到，默认为1
        vector<int> ret(n_Size, -1);
        for (int i = 0; i < 2 * n_Size - 1; ++i) {
            while(!stk.empty() && nums[stk.top()] < nums[i % n_Size]){
                ret[stk.top()] = nums[i % n_Size];
                stk.pop();
            }
            stk.push(i % n_Size);
        }
        return ret;
    }
};