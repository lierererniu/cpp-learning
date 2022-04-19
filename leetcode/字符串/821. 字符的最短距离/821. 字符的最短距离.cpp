//
// Created by 53110 on 2022/4/19.
//
#include <vector>
#include <string>
#include <iostream>

/*字符串查找的坑
str.rfind(s, pos)   从前往或查找，一直到pos位置，包含pos，返回最后一个匹配的位置
如果pos大于str.size(), 搜索整个字符串  */
using namespace std;
class Solution821 {
public:
    vector<int> shortestToChar(string s, char c) {
        int size_ = s.size();
        vector<int> res(size_);
        int n = 0;
        int temp = string::npos;
        int a = string::npos;
        for(int i = 0; i < size_; ++i){
            if(i != size_) temp = s.find(c, i);
            if( i != 0) a = s.rfind(c, i);
            if(temp !=  string::npos && a !=  string::npos){
                n = min(i - a, temp - i);
            }else{
                n = temp != string::npos ? temp - i: i - a;
            }
            res[i] = n;
        }
        return res;
    }
};

int main(){
    string s = "loveleetcode";
    vector<int> res = Solution821().shortestToChar(s, 'e');
    for(auto &v: res) {
        cout << v << " ";
    }
}