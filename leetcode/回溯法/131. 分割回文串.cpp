//
// Created by 53110 on 2022/6/9.
//

#include <vector>
#include <string>
using namespace std;

class Solution131{
public:
    vector<string> path;
    vector<vector<string>> res;
    vector<vector<string>> partition(string &s){
        if(s.size() == 1) return {{s}};
        backtracking(0, s);
        return res;
    }

    void backtracking(int startindex, const string &s){
        if(startindex >= s.size()){
            res.push_back(path);
            return;
        }
        for (int i = startindex; i < s.size(); ++i) {
            if(isPalindrome(s, startindex, i)){
                // 存储符合条件的路径
                path.push_back(s.substr(startindex, i - startindex + 1));
            }else{
                continue;
            }
            backtracking(i + 1, s);
            path.pop_back();
        }
    }

    bool isPalindrome(const string &s, int start, int end){
        if(start == end) return true;
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};