//
// Created by 53110 on 2022/5/23.
//

#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
/* 代码来源，我只是加了个注释。
 * 作者：wfnuser
        链接：https://leetcode.cn/problems/cut-off-trees-for-golf-event/solution/wei-rao-li-lun-by-wfnuser-l7ip/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};*/
class Solution675{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int m, n;
    vector<vector<int>> f;
    int bfs(pair<int, int>& s, pair<int, int>& e){
        if(s.first == e.first && s.second == e.second) return 0; // 已经到达目的地，无需搜索
        queue<pair<int, int>> q;  // 存储的为起点
        q.push(s);
        int step = 0;
        bool vis[m][n]; // 是否访问过
        memset(vis, 0, sizeof(vis));
        vis[s.first][s.second] = true;
        while(!q.empty()){
            step++;
            int size = q.size();
            while(size--){
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x = p.first + dx[i];
                    int y = p.second + dy[i];
                    // 越界
                    if(x < 0 || y < 0 || x >= m || y >= n) continue;
                    // 不可访问
                    if(f[x][y] == 0) continue;
                    // 已经访问过
                    if(vis[x][y]) continue;
                    // 到达目的地
                    if(x == e.first && y == e.second) return step;
                    // 更新
                    vis[x][y] = true;
                    q.push(make_pair(x, y));
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest){
        this->f = forest;
        m = f.size();
        n = f[0].size();
        if(f[0][0] == 0) return -1;
        vector<pair<int, pair<int, int>>> h;
        for (int i = 0; i < m; ++i) {
            for(int j = 0; j < n; j++){
                if(f[i][j] > 1){
                    h.emplace_back(f[i][j], make_pair(i, j));  //高度和索引, 保留高度是为了排序，从低到高进行搜索
                }
            }
        }
        sort(h.begin(), h.end()); // 根绝高度排序
        pair<int, int> s = make_pair(0, 0); // 记录起点
        int dis = 0;
        for (auto p:h) {
            int d = bfs(s, p.second); // 起点位置， 终点位置
            if(d == -1) return -1; // 如果无法到达该终点，则返回-1
            dis += d; // 记录需要的步数
            s = p.second; // 更新起点
        }
        return dis;
    }
};