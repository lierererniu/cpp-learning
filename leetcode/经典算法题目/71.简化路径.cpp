//
// Created by 53110 on 2022/3/23.
//
#include <string>
#include <deque>
#include <iostream>

using namespace std;

class Solution71 {
public:
    string simplifyPath(string path) {
        deque<string> st;
        int n = path.size(), i = 0;
        while (i < n) {
            if (path[i] == '/') i++;
            else {
                string temp;
                while (path[i] != '/') temp += path[i++];
                if (temp == ".." && !st.empty()) st.pop_back();
                else if (temp != ".." && temp != ".") st.push_back(temp);
            }
        }
        string res = "/";
        while (!st.empty()) {
            res += st.front() + "/";
            st.pop_front();
        }
        if (res.size() > 1) res.pop_back();
        return res;
    }
};

int main() {
    string a = "/a/./b/../../c/";
    string res = Solution71().simplifyPath(a);
    cout << res << endl;
    return 0;
}
