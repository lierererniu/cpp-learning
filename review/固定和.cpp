//
// Created by 53110 on 2022/8/31.
//

#include <iostream>
using namespace std;
typedef unsigned long long ull;

int main(){
    ull a, b, c;
    cin>>a>>b>>c;
    ull sum = a + b;
    ull temp = sum / c; // 最大
//    ull res = 0;
//    if((sum - (temp + 1) * c) % c == 0) res =
    ull res = ((temp + 1) * c - sum) % c;
//    for()
    cout << res << endl;
    return 0;
}