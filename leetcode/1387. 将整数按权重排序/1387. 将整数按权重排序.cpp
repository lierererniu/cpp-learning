//
// Created by Seven on 2022/2/25.
//
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution1387 {
public:
    int getF(int num) {
        if (num == 1) {
            return 0;
        } else if (num & 1) {
            return getF(num * 3 + 1) + 1;
        } else {
            return getF(num / 2) + 1;
        }
    }

    int getKth(int lo, int hi, int k) {
        vector<int> v;
        for (int i = lo; i < hi + 1; ++i) {
            v.push_back(i);
        }
        sort(v.begin(), v.end(), [&](int u, int v) {
            if (getF(u) != getF(v)) {
                return getF(u) < getF(v);
            } else {
                return u < v;
            }
        });
        return v[k - 1];
    }
};

int main() {
    int low = 12;
    int hi = 15;
    int k = 2;
    Solution1387 a;
    int num = a.getKth(low, hi, k);
    cout << num;
}