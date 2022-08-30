//
// Created by Seven on 2022/2/27.
//

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
//给你一个整数数组 nums，请你求出乘积为正数的最长子数组的长度。
//
//一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。
//
//请你返回乘积为正数的最长子数组长度。

class r_Solution1567 {
public:
    int getMaxLen(vector<int> &nums) {
        int length = nums.size();
        vector<int> pos(length), neg(length);
        if (nums[0] > 0) {
            pos[0] = 1;
        } else if (nums[0] < 0) {
            neg[0] = 1;
        }
        int maxlength = pos[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] > 0) {
                pos[i] = pos[i - 1] + 1;
                neg[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
            } else if (nums[i] < 0) {
                pos[i] = neg[i - 1] > 0 ? neg[i - 1] + 1 : 0;
                neg[i] = pos[i - 1] + 1;
            } else {
                pos[i] = 0;
                neg[i] = 0;
            }
            maxlength = max(maxlength, pos[i]);
        }
        return maxlength;
    }
};

//int main() {
//    vector<int> test0, test1, test2;
//    test0 = {1, -2, -3, 4};
//    test1 = {0, 1, -2, -3, -4};
//    test2 = {-1, -2, -3, 0, 1};
//    int length1 = r_Solution1567().getMaxLen(test0);
//    cout << "test0 = {1, -2, -3, 4}:乘积为正数的最长子数组的长度为：" << length1 << endl;
//    int length2 = r_Solution1567().getMaxLen(test1);
//    cout << "test1 = {0,1,-2,-3,-4}:乘积为正数的最长子数组的长度为：" << length2 << endl;
//    int length3 = r_Solution1567().getMaxLen(test2);
//    cout << "test2 = {-1,-2,-3,0,1}:乘积为正数的最长子数组的长度为：" << length3 << endl;
//    system("pause");
//    return 0;
//}