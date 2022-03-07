//
// Created by 53110 on 2022/3/7.
//
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution807 {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int n_Size = grid.size();
        int res = 0;
        vector<int> m_row(n_Size);
        vector<int> m_col(n_Size);
        for (int i = 0; i < n_Size; ++i) {
            for (int j = 0; j < n_Size; ++j) {
                m_row[i] = max(m_row[i], grid[i][j]);
                m_col[j] = max(m_col[j], grid[i][j]);
            }
        }
        for (int i = 0; i < n_Size; ++i) {
            for (int j = 0; j < n_Size; ++j) {
                res += min(m_row[i], m_col[j]) - grid[i][j];
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> grid = {{3, 0, 8, 4},
                                {2, 4, 5, 7},
                                {9, 2, 6, 3},
                                {0, 3, 1, 0}};
    int res = Solution807().maxIncreaseKeepingSkyline(grid);
    cout << "建筑物可以增加的最大高度增量总和为:" << res << endl;
};