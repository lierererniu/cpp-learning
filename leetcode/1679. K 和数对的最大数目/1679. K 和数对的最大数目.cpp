//
// Created by Seven on 2022/3/1.
//

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution1679 {
public:
    int maxOperations(vector<int> &nums, int k) {
        int Siz = nums.size();
        sort(nums.begin(), nums.end());
        int L = 0;
        int R = Siz - 1;
        int ret = 0;
        while (L < R) {
            if (nums[L] + nums[R] == k) {
                ret += 1;
                L += 1;
                R -= 1;
            } else if (nums[L] + nums[R] < k) {
                L += 1;
            } else {
                R -= 1;
            }
        }
        return ret;
    }
};

int main() {
    int k = 5;
    vector<int> nums = {1,2,3,4};
    int result = Solution1679().maxOperations(nums, k);
    cout << result << endl;
}