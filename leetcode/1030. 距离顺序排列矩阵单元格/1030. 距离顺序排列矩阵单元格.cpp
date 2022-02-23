//
// Created by Seven on 2022/2/23.
//


#include<iostream>
#include <vector>
#include "algorithm"
using  namespace std;


class Solution1030 {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ret;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ret.push_back({i, j});
            }
        }

        sort(ret.begin(), ret.end(), [=](vector<int>& a, vector<int>& b) {
            return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
        });
        return ret;
    }
};

int main()
{
    vector<vector<int>> result;
    int row = 2;
    int col = 3;
    int rC = 1;
    int cC = 2;
    Solution1030 a;
    result = a.allCellsDistOrder(row, col, rC, cC);

    for (vector<vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
        for (vector<int>::iterator bit = (*it).begin(); bit != (*it).end(); bit++) {
            cout << *bit << " ";
        }
        cout<<endl;
    }



}