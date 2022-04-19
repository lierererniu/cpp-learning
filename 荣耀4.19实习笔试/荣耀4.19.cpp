//
// Created by 53110 on 2022/4/19.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
class Solution1{
public:
    /*通过80%，没想出错在哪，交卷后发现结果没取余。。。*/
    map<vector<int>, int> rem;
    int dis(int n, int m){
        if(m == 1 || n == 0) return 1;
        if(rem.count({n, m})){
            return rem[{n, m}];
        }
        if(m > n) return dis(n, n);
        rem[{n, m}] = dis(n, m-1) + dis(n - m, m);
        return rem[{n, m}];
    }
};

using namespace std;
class Solution2{
public:
    /*没通过，大小端字节序分析*/
    vector<string> sss(int n, string &s){
        vector<string> res(n);
        string temp;
        int pos0 = string::npos;
        int pos1 = string::npos;
        int k = 0;
        for (int i = 0; i < s.size();) {
            if (s[i] == '0') {
                temp = "";
                if (i != s.size() - 1) {

                    pos0 = s.find('0', i + 1);
                    pos1 = s.find('1', i + 1);
                }
                if (pos0 != string::npos) {
                    temp = s.substr(i + 1, pos0 - 1);
                    string ss(temp.rbegin(), temp.rend());
                    res[k] = ss;
                    k++;
                    i = pos0;
                    continue;
                } else if (pos1 != string::npos) {
                    temp = s.substr(i + 1, pos1 - 1);
                    string ss(temp.rbegin(), temp.rend());
                    res[k] = ss;
                    k++;
                    i = pos1;
                    continue;
                }else{
                    temp = s.substr(i + 1);
                    string ss(temp.rbegin(), temp.rend());
                    res[k] = ss;
                    k++;
                    break;
                }
            }else if (s[i] == '1'){
                temp = "";
                if (i != s.size() - 1) {
                    pos0 = s.find('0', i + 1);
                    pos1 = s.find('1', i + 1);
                }
                if (pos0 != string::npos) {
                    temp = s.substr(i + 1, pos0 - 1);
                    res[k] = temp;
                    sort(temp.begin(), temp.end());
                    k++;
                    i = pos0;
                    continue;
                } else if (pos1 != string::npos) {
                    temp = s.substr(i + 1, pos1 - 1);
                    sort(temp.begin(), temp.end());
                    res[k] = temp;
                    k++;
                    i = pos1;
                    continue;
                }else{
                    temp = s.substr(i + 1);
                    res[k] = temp;
                    sort(temp.begin(), temp.end());
                    k++;
                    break;
                }
            }
            return res;
        }
    }
};
int main(){
    int n = 7;
    int m = 3;
    int res1 = Solution1().dis(n, m) % 1000000007;
    cout<< res1;

    int k = 3;
    string ss = "0abcdefgh1abcdefgh0sgasdgdsh";
    vector<string> res2 = Solution2().sss(k , ss);

    for (auto &s: res2) {
        cout<< s<<" ";
    }
    return 0;
}