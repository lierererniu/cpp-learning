//
// Created by 53110 on 2022/6/3.
//

class Solution829 {
public:
    // int consecutiveNumbersSum(int n) {
    //     if(n == 1) return 1;
    //     // n 自己本身就是一个答案，无需考虑
    //     int cnt = 1;
    //     // i代表几个元素的和
    //     for(int i = 2; i < n; i++){
    //         // a 为起点
    //         // i 为元素个数
    //         // 不能整除得到的起点都是错误的
    //         if((2 * n) % i != 0) continue;
    //         if(((2 * n / i) + 1 - i) % 2 != 0) continue;
    //         int a = ((2 * n / i) + 1 - i) / 2;
    //         // 如果起点小于1,a是关于k单调递减的，所以当a小于1时 终止循环。
    //         if(a < 1) break;
    //         cnt++;
    //     }
    //     return cnt;
    // }
    // int consecutiveNumbersSum(int n) {
    //     int cnt = 1;
    //     for (int k = 2; ; ++k) {
    //         int a = (2 * n / k + 1 - k) / 2;
    //         if (a < 1) break;
    //         int s = (2 * a + k - 1) * k / 2;
    //         if (s == n) ++cnt;
    //     }
    //     return cnt;
    // }
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        int m = 2*n;
        for(int k = 1; k * (k+1) <= m; ++k){
            if(m % k == 0 && (m / k - k) & 1){
                ++ans;
            }
        }
        return ans;
    }

};