//
// Created by 53110 on 2022/4/6.
//
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
/*找出数组中重复的数字
 * 在一个长度为n的数组里的所有数字都在0~n-1的范围。
 * 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道重复的了几次。
 * 请找出数组中任意一个重复的数字。
 * 例如，如果输入长度为7的数组{2,3,1,0,2,5,3},那么对应的输出是重复的数字2或者3.
 * */
using namespace std;
class Solution03_{
public:
    // 方法1：排序的方法
    int FindRepeatNum_Sort(vector<int> &arr){
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i) {
            if(i != arr[i]){
                return arr[i];
            }
        }
    }
    // 方法2：哈希表
    int FindRepeatNum_Hash(vector<int> &arr){
        map<int, int> hash;
        for (int i = 0; i < arr.size(); ++i) {
            if (hash.count(arr[i])){
                return arr[i];
            } else{
                hash.insert(make_pair(arr[i], i));
            }
        }
    }
    // 方法3：下标O(n)  O(1)
    static bool FindRepeatNum_fast(vector<int> &arr, int **duplication){
        if (arr.size() == 0){
            return false;
        }
        int size_ = arr.size();
        for (int i = 0; i < size_; ++i) {
            if (arr[i] < 0 || arr[i] > size_ + 1){
                return false;
            }
        }
        for (int i = 0; i < size_; ++i) {
            while (arr[i] != i){
                if (arr[i] == arr[arr[i]]){
                    *duplication = &arr[i];
                    return true;
                }
                int temp = arr[i];
                arr[i] = arr[temp];
                arr[temp] = temp;
            }
        }
        return false;
    }
};

int main(){
    vector<int> arr = {2,3,1,0,2,5,3};
    int *duplication;
    cout<< Solution03_().FindRepeatNum_Sort(arr) << endl;
    cout<< Solution03_().FindRepeatNum_Hash(arr) << endl;
    bool res = Solution03_::FindRepeatNum_fast(arr, &duplication);
    cout << res <<"  repeatnum:"<< *duplication << endl;
}