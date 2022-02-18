//
// Created by Seven on 2022/2/18.
//

#include "vector"
#include "string"
#include "iostream"

using namespace std;

class Solution1567 {
public:
    int getMaxLen(vector<int> &nums) {
        int length = nums.size();
        vector<int> positive(length), negative(length);
        if (nums[0] > 0) {
            positive[0] = 1;
        } else if (nums[0] < 0) {
            negative[0] = 1;
        }
        int maxLength = positive[0];
        for (int i = 1; i < length; ++i) {
            if (nums[i] > 0) {
                positive[i] = positive[i - 1] + 1;
                negative[i] = (negative[i - 1] > 0 ? negative[i - 1] + 1 : 0);
            } else if (nums[i] < 0) {
                positive[i] = (negative[i - 1] > 0 ? negative[i - 1] + 1 : 0);
                negative[i] = positive[i - 1] + 1;
            } else {
                positive[i] = 0;
                negative[i] = 0;
            }
            maxLength = max(maxLength, positive[i]);
        }
        return maxLength;
    }
};

int main() {
    vector<int> nums(5);
    nums[0] = 0;
    nums[1] = 1;
    nums[2] = -2;
    nums[3] = -3;
    nums[4] = -4;
    Solution1567 a;
    int len = a.getMaxLen(nums);
    cout << len;
    return 0;
}