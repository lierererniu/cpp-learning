//
// Created by Seven on 2022/2/20.
//

#include "string"
#include "iostream"
#include "unordered_map"

using namespace std;

class Solution1542 {
public:
    int longestAwesome(string s) {
        int n = s.size();
        unordered_map<int, int> prefix = {{0, -1}};
        int ans = 0;
        int sequence = 0;
        for (int j = 0; j < n; ++j) {
            int digit = s[j] - '0';
            sequence ^= (1 << digit);
            if (prefix.count(sequence)) {
                ans = max(ans, j - prefix[sequence]);
            } else {
                prefix[sequence] = j;
            }
            for (int k = 0; k < 10; ++k) {
                if (prefix.count(sequence ^ (1 << k))) {
                    ans = max(ans, j - prefix[sequence ^ (1 << k)]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution1542 a;
    string s = "1242411";
    int length = a.longestAwesome(s);
    cout << "最长超赞字符串长度为：" << length << endl;
    return 0;
}