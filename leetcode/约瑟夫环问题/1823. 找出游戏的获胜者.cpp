//
// Created by 53110 on 2022/5/4.
//
#include <queue>

using namespace std;

class Solution1823{
public:
    // 队列加模拟
    int findTheWinner(int n, int k){
        queue<int> que;
        for (int i = 1; i <= n; ++i) {
            que.emplace(i);
        }
        while(que.size() != 1){
            for (int i = 0; i < k - 1; ++i) {
                que.emplace(que.front());
                que.pop();
            }
            que.pop();
        }
        return que.front();
    }
    // 数学方法
    // 递推式： f(x) = 0  n=0;
    // f(x) = [f(n-1, m) + m] % n; n > 1;
    int findTheWinner1(int n, int k){
        int pos = 0;
        for (int i = 2; i <= n; ++i) {
            pos = (pos + k) % i;
        }

        return pos + 1;
    }

};
