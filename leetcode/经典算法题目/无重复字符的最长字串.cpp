//
// Created by 53110 on 2022/3/11.
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution3 {
public:
    int lenthOfLongestSubstirng(string s) {
        if (s.size() == 0) {
            return 0;
        }
        unordered_set<char> lookup;
        int maxstr = 0;
        int left = 0;
        for (int i = 0; i < s.size(); i++) {
            while (lookup.find(s[i]) != lookup.end()) {
                lookup.erase(s[left]);
                left++;
            }
            maxstr = max(maxstr, i - left + 1);
            lookup.insert(s[i]);

        }
        return maxstr;
    }
};

//int main() {
//    Solution3 s;
//    string StrL = "abcabcbb";
//    int a = s.lenthOfLongestSubstirng(StrL);
//    cout << "无重复字符的字长子串为：" << a << endl;
//    system("pause");
//    return 0;
//
//    return 0 ;
//}