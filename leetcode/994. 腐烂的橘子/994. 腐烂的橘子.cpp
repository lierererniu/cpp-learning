//
// Created by 53110 on 2022/3/21.
//
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
/*

首先分别将腐烂的橘子和新鲜的橘子保存在两个集合中；

模拟广度优先搜索的过程，方法是判断在每个腐烂橘子的四个方向上是否有新鲜橘子，如果有就腐烂它。每腐烂一次时间加 11，并剔除新鲜集合里腐烂的橘子；

当橘子全部腐烂时结束循环

作者：z1m
链接：https://leetcode-cn.com/problems/rotting-oranges/solution/yan-du-you-xian-sou-suo-python3-c-by-z1m/
来源：力扣（LeetCode）
 */

class Solution994{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min = 0, fresh = 0;
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        //获取新鲜水果数量，获取腐烂水果位置
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        // 四个方向移动的常用方法
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0},{0, -1}, {0, 1}};
        //如果仍有腐烂，继续遍历
        while(!q.empty()){
            int q_size = q.size();
            bool rotten = false;//记录本次是否腐化了水果，下面无论循环多少次，本次循环都只能增加一分钟
            //遍历腐烂水果相邻的所有位置，如果存在新鲜水果，全部腐化，并将腐烂位置更新
            for (int i = 0; i < q_size; ++i) {
                //pair<int, int> x = q.front();
                auto x = q.front();
                q.pop(); //移除队头
                for (auto cur: dirs) {
                    // 更新x , y 坐标
                    int a = x.first + cur.first;
                    int b = x.second + cur.second;
                    //如果遍历的坐标是新鲜的和符合要求的
                    //i大于0 和 j大于0 是防止数组越界的
                    if (a >= 0 && a < m && b >=0 && b < n && grid[a][b] == 1){
                        grid[a][b] = 2;
                        q.push({a, b});//腐烂的坐标加入
                        fresh--;
                        rotten = true;
                    }
                }
            }
            if (rotten) min++;
        }
        return fresh? -1: min;
    }
};

int main(){
    vector<vector<int>> arr = {{2,1,1},{1,1,0},{0,1,1}};
    int ret = Solution994().orangesRotting(arr);
    printf("%s\n", ret);
    return 0;
}