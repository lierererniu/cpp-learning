//
// Created by Seven on 2022/2/28.
//

//我们将整数 x的 权重 定义为按照下述规则将 x变成 1所需要的步数：
//
//如果x是偶数，那么x = x / 2
//如果x是奇数，那么x = 3 * x + 1
//比方说，x=3 的权重为 7 。因为 3 需要 7 步变成 1 （3 --> 10 --> 5 --> 16 --> 8 --> 4 --> 2 --> 1）。
//
//给你三个整数lo，hi 和k。你的任务是将区间[lo, hi]之间的整数按照它们的权重升序排序，如果大于等于 2 个整数有相同的权重，那么按照数字自身的数值升序排序。
//
//请你返回区间[lo, hi]之间的整数按权重排序后的第k个数。
//
//注意，题目保证对于任意整数x（lo <= x <= hi），它变成 1 所需要的步数是一个 32 位有符号整数。


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class r_Solution1387 {
public:
    int getStep(int num) {

        if (num == 1) {
            return 0;
        }
        if (num & 1) {
            return getStep(num * 3 + 1) + 1;
        } else {
            return getStep(num / 2) + 1;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums;
        for (int i = lo; i <= hi; ++i) {
            nums.push_back(i);
        }
        sort(nums.begin(), nums.end(), [&](int u, int v) -> bool {
            if (getStep(u) != getStep(v)) return getStep(u) < getStep(v);
            else return u < v;
        });

        return nums[k - 1];
    }
};

//int main() {
//    int lo = 1;
//    int hi = 1000;
//    int k = 777;
//    int result = r_Solution1387().getKth(lo, hi, k);
//    cout << result << endl;
//}
