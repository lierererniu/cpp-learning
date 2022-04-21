//
// Created by 53110 on 2022/4/20.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

/*
 * 注意：
 * 值可能很大，你应该对结果取余
 * 本代码未取余
*/
class BallInBox {
private:
    // a >= b
    int conmb(int a, int b) {
        if (a == b || b == 0) return 1;
        return conmb(a, b - 1) * (a - b + 1) / b;
    }

    ll stirling(int n, int m) //n个球，m个盒子
    {
        if (n < m || !n || !m)return 0;
        if (n == m)return 1;
        else return stirling(n - 1, m - 1) + stirling(n - 1, m) * m;
    }

public:
    map<vector<int>, int> rem;

    // 球同, 盒同，允许为空,就是将n分为m个自然数的和的个数
    int BallSameBoxSameIsEmpty(int n, int m) {
        if (m == 1 || n == 0) return 1;
        if (rem.count({n, m})) {
            return rem[{n, m}];
        }
        if (m > n) return BallSameBoxSameIsEmpty(n, n);
        rem[{n, m}] = BallSameBoxSameIsEmpty(n, m - 1) + BallSameBoxSameIsEmpty(n - m, m);
        return rem[{n, m}];
    }

    map<vector<int>, int> rem1;

    //球同盒同，不允许为空，  n分为m个正整数的和的个数
    int BallSameBoxSameNotEmpty(int n, int m) {
        if (n < m) return 0;
        if (m == 1 || n == m) return 1;
        if (rem1.count({n, m})) {
            return rem1[{n, m}];
        }
        rem1[{n, m}] = BallSameBoxSameIsEmpty(n - m, m);
        return rem[{n, m}];
    }

    // 球同盒不同，不允许空盒
    // 隔板法
    int BallSameBoxDiffNoEmpty(int n, int m) {
        if (n < m) return 0;
        if (n == m) return 1;
        return conmb(n - 1, m - 1);
    }

    // 球同盒不同，允许空盒
    // 加入虚拟球  再隔板
    int BallSameBoxDiffAllowEmpty(int n, int m) {

        return conmb(n + m - 1, m - 1);
    }

    // 异球同盒


    // 异球同盒无空  // sbirling 数 斯特林数
    int diffBoxSameBallNoEmpty(int n, int m) {
        if (n < m || !n || !m)return 0;
        if (n == m)return 1;
        else return diffBoxSameBallNoEmpty(n - 1, m - 1) + diffBoxSameBallNoEmpty(n - 1, m) * m;
    }

    // 异球同盒可空  k个盒子不空的情况， S(n,k) k ~ 1 - m
    ll diffBoxSameBallIsEmpty(int n, int m) {
        ll res = 0;
        for (int i = 1; i <= m; ++i) {
            res += stirling(n, i);
        }
        return res;
    }


    // 异球异盒无空
    // 异球同盒无空情况下， 乘 盒子数量的阶乘
    ll diffBoxDiffBallNoEmpty(int n, int m) {
        ll temp = 1;
        ll res;
        for (int i = 1; i <= m; ++i) {
            temp *= i;
        }
        res = temp * diffBoxSameBallNoEmpty(n, m);
        return res;
    }

    // 异球异盒可空
    ll diffBoxDiffBallIsEmpty(int n, int m) {
        ll res = pow(m, n);
        return res;
    }
};