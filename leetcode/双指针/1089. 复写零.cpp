//
// Created by 53110 on 2022/6/17.
//
#include <vector>

using namespace std;

class Solution1089 {
public:
    void duplicateZeros(vector<int>& arr) {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            if (arr[i] == 0) cnt++;
        }

        for(int n = arr.size() - 1; n >= 0; --n){
            if(arr[n] == 0) {
                cnt--;
            }

            if(n + cnt < arr.size()){
                arr[n + cnt] = arr[n];
                if(arr[n] == 0 && n + cnt + 1 < arr.size()){
                    arr[n + cnt + 1] = 0;
                }
            }
        }
    }
};