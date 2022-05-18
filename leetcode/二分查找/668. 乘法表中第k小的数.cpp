//
// Created by 53110 on 2022/5/18.
//

#include <algorithm>

using namespace std;

class Solution668{
public:
    int findKthNumber(int m, int n, int k){
        int left = 1;
        int right = m * n;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(count(m, n, mid) >= k){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    int count(int m, int n, int mid){
        int res = 0;
        for (int i = 1; i <= m; ++i) {
            res += min(mid / i, n);
        }
        return res;
    }
};
