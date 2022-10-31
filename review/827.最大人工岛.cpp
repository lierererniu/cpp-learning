//
// Created by 53110 on 2022/9/18.
//

#include <iostream>
#include <unordered_set>
#include <map>
#include <vector>

using namespace std;

class Solution{
public:
    bool isValid(vector<vector<int>>& grid, int i, int j){
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    int largestIsland(vector<vector<int>>& grid){
         int index = 2;  // 用来标记访问过的岛屿
         int row = grid.size();
         int col = grid[0].size();
         int maxArea = 0;
         map<int, int> my_m;
         for (int i = 0; i < row; ++i) {
             for (int j = 0; j < col; ++j) {
                 if(grid[i][j] == 1){
                     int curSize = dfs(grid, i, j, index);
                     my_m[index] = curSize;  // 记录面积
                     index ++;
                     maxArea = max(maxArea, curSize);
                 }
             }
         }
         if(maxArea == 0) return 1;  // 直接填一个格子
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if(grid[i][j] == 0){
                    unordered_set<int> temp = isAdjoin(grid, i, j);
                    if(temp.size() < 1) continue; // 无相邻
                    int n_size = 1;  // 默认填一个格子;
                    for(auto te :temp){
                        n_size += my_m[te];
                    }
                    maxArea = max(maxArea, n_size);
                }
            }
        }
        return maxArea;
    }

    unordered_set<int> isAdjoin(vector<vector<int>>& grid, int row, int col){
        unordered_set<int> temp;
        if(isValid(grid, row - 1, col) && grid[row - 1][col] != 0) temp.insert(grid[row - 1][col]);
        if(isValid(grid, row + 1, col) && grid[row + 1][col] != 0) temp.insert(grid[row + 1][col]);
        if(isValid(grid, row, col - 1) && grid[row][col - 1] != 0) temp.insert(grid[row][col - 1]);
        if(isValid(grid, row, col + 1) && grid[row][col + 1] != 0) temp.insert(grid[row][col + 1]);
        return temp;
    }

    int dfs(vector<vector<int>>& grid, int row, int col, int index){
        if(!isValid(grid, row, col)) return 0;
        if(grid[row][col] != 1) return 0;
        grid[row][col] = index;
        return (1 + dfs(grid, row + 1, col, index) + dfs(grid, row - 1, col, index)
                + dfs(grid, row, col + 1, index) + dfs(grid, row, col - 1, index));
    }


};

int main(){
    vector<vector<int>> arr = {{1, 0},
                               {0, 1}};
    int maxArea = Solution().largestIsland(arr);
    cout<< maxArea << endl;
    return 0;
}