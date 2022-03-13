//
// Created by 53110 on 2022/3/13.
//
#include <vector>
#include <iostream>

using namespace std;

class SolutionLCP {
public:
    vector<int> fraction(vector<int> &cont) {
        int length = cont.size();
        vector<int> ret = {1, cont[length - 1]};
        vector<int> ret1(2);
        for (int i = length - 1; i > 0; --i) {
            ret1[0] = cont[i - 1] * ret[1];
            ret1[1] = ret[1];
            ret[0] = ret1[0] + ret[0];//分子
            ret[1] = ret1[1];//分母
            swap(ret[0], ret[1]); //翻转
        }
        swap(ret[0], ret[1]);
        return ret;
    }
};

int main() {
    vector<int> s = {3, 2, 0, 2};
    vector<int> res = SolutionLCP().fraction(s);
    for (auto &it: res) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
