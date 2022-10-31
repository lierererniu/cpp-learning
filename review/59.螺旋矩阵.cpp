//
// Created by 53110 on 2022/9/15.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution59{
public:
    vector<vector<int>> generateMatrix(int n){
        int top = 0;
        int left = 0;
        int right = n - 1;
        int bottom = n - 1;
        vector<vector<int>> res(n, vector<int>(n, 0));
        int num = 1;
        // 左开右闭
        while(true){
            for (int i = left; i <= right; ++i) {
                res[top][i] = num;
                num++;
            }
            top++;
            if(top > bottom) break;
            for (int i = top; i <= bottom; ++i) {
                res[i][right] = num;
                num++;
            }
            right--;
            if(right < left) break;
            for (int i = right; i >= left; --i) {
                res[bottom][i] = num;
                num++;
            }
            bottom--;
            if(bottom < top) break;
            for (int i = bottom; i >= top; --i) {
                res[i][left] = num;
                num++;
            }
            left++;
            if(left > right) break;
        }
        return res;
    }
};
int main(){
    int n;
    cin>>n;
    auto arr = Solution59().generateMatrix(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}