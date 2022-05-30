//
// Created by 53110 on 2022/5/30.
//
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
class Solution436 {
public:
    // 二分查找
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return {-1};
        vector<int> start;
        map<int, int> temp;
        for(int i = 0; i < intervals.size(); ++i){
            start.push_back(intervals[i][0]);
            temp[intervals[i][0]] = i; // 记录对应起点的索引
        }
        sort(start.begin(), start.end());
        vector<int> res;
        for(auto &interval:intervals){
            int d = findFirstMin(start, interval[1]); // 找第一个大于等于终点的起点值
            res.push_back((d == -1? -1: temp[start[d]]));
        }
        return res;
    }
    int findFirstMin(vector<int> &start, int target){
        int L = 0;
        int R = start.size() - 1;
        if(target > start[R]) return -1;
        while(L < R){
            int mid = (L + R) / 2;
            if(start[mid] >= target){
                R = mid;
            }else{
                L = mid + 1;
            }
        }
        return L; //须返回索引， 返回值的话有可能是-1，与特殊条件冲突
    }

    // 双指针
    vector<int> findRightInterval_Double(vector<vector<int>>& intervals){
        if(intervals.size() == 1) return {-1};
        const int N = intervals.size();
        vector<pair<int, int>> start(N);
        vector<pair<int, int>> end(N);
        for (int i = 0; i < N; ++i) {
            start[i] = make_pair(intervals[i][0], i);
            end[i] = make_pair(intervals[i][1], i);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int p1 = 0;
        int p2 = 0;
        vector<int> res(N, -1);
        while(p1 < N && p2 < N){
            if(start[p1].first < end[p2].first){
                p1 ++;
            }else{
                res[end[p2].second] = start[p1].second;
                p2++;
            }
        }
        return res;
    }
};