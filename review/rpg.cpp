//
// Created by 53110 on 2022/8/31.
//

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>> arr(2, vector<int>(5, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < m; ++j) {
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> temp(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin>>temp[i][j];
        }
    }
    sort(arr[0].begin(), arr[0].end(),cmp);
    sort(arr[1].begin(), arr[1].end());
    for (int i = 0; i < n; ++i) {
        vector<int> a = temp[i];
        int mul1 = a[0];
        int mul2 = a[1];
        int res = 0;
        for (int j = 0; j < m; ++j) {
            if(arr[0][j] * mul1 <= arr[1][j] * mul2) break;
            int dele =  arr[0][j] * mul1 - arr[1][j] * mul2;
            res += dele;
        }
        cout<< res <<endl;
    }

    return 0;
}