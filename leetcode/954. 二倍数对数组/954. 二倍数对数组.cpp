//
// Created by 53110 on 2022/4/7.
//

/*给定一个长度为偶数的整数数组 arr，只有对 arr 进行重组后可以满足
 * “对于每个 0 <=i < len(arr) / 2，都有 arr[2 * i + 1] = 2 * arr[2 * i]”时，
 * 返回 true；否则，返回 false。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/array-of-doubled-pairs
*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
class Solution954{
public:
    // 排序，队列
    bool canReorderDoubled(vector<int> &arr){
        sort(arr.begin(), arr.end());
        queue<int> que;
        for (int i = 0; i < arr.size(); ++i) {
            if (que.empty()){
                que.push(arr[i]);
            }else if(arr[i] * 2 == que.front() || arr[i] == 2 * que.front()){
                que.pop();
            }else{
                que.push(arr[i]);
            }
        }
        return que.empty();
    }
    // 哈希表
    bool canReorderDoubledHash(vector<int> &arr){
        map<int, int> cnt;
        for (int num: arr) {
            cnt[num] ++;
        }
        if (cnt[0] % 2 != 0){
            return false;
        }
        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        // 按绝对值排序
        sort(vals.begin(), vals.end(), [] (int a, int b){return abs(a) < abs(b);});
        for (int x: vals) {
            //  绝对值最小的元素，只能与2 * x匹配，如果2 * x不够，则无法匹配
            if (cnt[2*x] < cnt[x]){
                return false;
            }
            // 成功配对的消除
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};

int main(){
    vector<int> arr = {4, -2, 2, -4};
    cout<< Solution954().canReorderDoubled(arr) <<endl;
    cout<< Solution954().canReorderDoubledHash(arr) <<endl;
    return 0;
}