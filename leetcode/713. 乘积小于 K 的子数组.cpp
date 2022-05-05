#include <vector>

using namespace std;

class Solution713 {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if(k < 2) return 0;
        int n_size = nums.size(), r = 0, l = 0, ans = 0, prefix = 1;
        while(r != n_size){
            prefix *= nums[r];

            while(prefix >= k){
                prefix /= nums[l]; //从左边开始去掉不符合的元素
            }
            ++r;
            ans += r - l;  //对每个窗口的最大长度进行累加
        }
    }
};
