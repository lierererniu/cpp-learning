//
// Created by Seven on 2022/2/28.
//

//给定四个整数 row, cols ,rCenter 和 cCenter 。有一个rows x cols的矩阵，你在单元格上的坐标是(rCenter, cCenter) 。
//
//返回矩阵中的所有单元格的坐标，并按与(rCenter, cCenter)的 距离 从最小到最大的顺序排。你可以按 任何 满足此条件的顺序返回答案。
//
//单元格(r1, c1) 和 (r2, c2) 之间的距离为|r1 - r2| + |c1 - c2|。
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class r_Solution1030{
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> arr;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                arr.push_back({i, j});
            }
        }
        sort(arr.begin(), arr.end(), [=] (vector<int> &a, vector<int> &b) ->bool{
            return abs(a[0] -rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
        });
        return arr;
    }
};
int main(){
    int rows = 2;
    int cols = 2;
    int rCenter = 0;
    int cCenter = 1;
    vector<vector<int>> result = r_Solution1030().allCellsDistOrder(rows, cols, rCenter, cCenter);
    for (auto & it : result) {
        for (int & bit : it) {
            cout<< bit;
        }
        cout<<endl;
    }
    return 0;
}