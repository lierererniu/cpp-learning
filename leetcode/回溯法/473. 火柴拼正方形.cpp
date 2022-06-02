//
// Created by 53110 on 2022/6/2.
//

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution473 {
public:
    bool makesquare(vector<int>& matchsticks) {
        // 先判断特殊情况
        if(matchsticks.size() < 4) return false; //筷子数小于4
        int tatal = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(tatal % 4 != 0) return false;  // 不能整除4
        int edge = tatal / 4;  //每条边的边长
        vector<int> edges(4, 0); //初始化每条边的初始边长，然后取筷子在上面堆放
        // 从大到小排序， 减少回溯运算量（增大减枝的命中率
        sort(matchsticks.begin(), matchsticks.end(), [&](int a, int b)->bool{
            return a > b;
        });
        return bfs(0, matchsticks, edges, edge);
    }

    bool bfs(int index, vector<int>& matchsticks, vector<int>& edges, int edge){
        // 边界条件, 筷子用完了, 当用完时，则说明所有筷子都按要求放在各自的边了
        if(index == matchsticks.size()) return true;
        // 每条边都尝试放这根筷子
        for (int i = 0; i < 4; ++i) {
            // 如果这条边不能放这条筷子继续
            if(matchsticks[index] + edges[i] > edge) continue;
            // 剪枝 如果元素和相等，那么 matchsticks[index] 选择上一个桶和选择当前桶可以得到的结果是一致的
            if(i > 0 && edges[i - 1] == edges[i]) continue;
            edges[i] += matchsticks[index];
            // 是否选择下一个筷子
            if(bfs(index + 1, matchsticks, edges, edge)) return true;

            //选择这条路行不通，撤销选择，拿出筷子
            edges[i] -= matchsticks[index];
        }
        // 筷子在每一条边上都无法放上
        return false;
    }
};
