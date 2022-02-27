//
// Created by Seven on 2022/2/27.
//
#include "vector"
#include "string"
#include "iostream"
#include "unordered_map"

//给你一个字符串 s 。请返回 s 中最长的 超赞子字符串 的长度。
//
//「超赞子字符串」需满足满足下述两个条件：
//
//该字符串是 s 的一个非空子字符串
//进行任意次数的字符交换后，该字符串可以变成一个回文字符串

using namespace std;

class r_Solution1542 {
public:
    int longestAwesome(string s) {
        unordered_map<int, int> prefix{{0, -1}};
        int max_len = 0;
        int length = s.size();
        int Zero_One = 0;
        for (int i = 0; i < length; ++i) {
            int num = s[i] - '0';
            Zero_One ^= (1 << num);
            if (prefix.count(Zero_One)) {
                max_len = max(max_len, i - prefix[Zero_One]);
            } else {
                prefix[Zero_One] = i;
            }
            for (int n = 0; n < 10; ++n) {
                if (prefix.count(Zero_One ^ (1 << n))) {
                    max_len = max(max_len, i - prefix[Zero_One ^ (1 << n)]);
                }
            }
        }
        return max_len;
    }
};

int main() {
    string s = "3242415";
    int length = r_Solution1542().longestAwesome(s);
    cout << "最长超赞字符串长度为：" << length << endl;
    return 0;
}