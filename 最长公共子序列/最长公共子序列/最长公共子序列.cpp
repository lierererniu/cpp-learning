#include<iostream>
#include<string>
#include <vector>
using namespace std;
//using std::vector;

//class Solution {
//public:
//    int longestCommonSubsequence(string text1, string text2) {
//        int n = text1.size(), m = text2.size();
//        vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
//        for (int i = 1; i <= n; ++i) {
//            for (int j = 1; j <= m; ++j) {
//                if (text1[i - 1] == text2[j - 1]) {
//                    f[i][j] = f[i - 1][j - 1] + 1;
//                }
//                else {
//                    f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//                }
//            }
//        }
//        return f[n][m];
//    }
//};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (text1[i - 1] != text2[j - 1]) {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
        }

        // 计算一个最长公共子序列的实际字符串(计算多个可以使用递归)
        string res;
        int curI = n, curJ = m;
        int len = dp[n][m];
        while (len > 0) {
            if (text1[curI - 1] == text2[curJ - 1]) {
                res.push_back(text1[curI - 1]);
                --curI, --curJ, --len;
            }
            else {
                if (dp[curI - 1][curJ] > dp[curI][curJ - 1]) {
                    --curI;
                }
                else {
                    --curJ;
                }
            }
        }
        reverse(res.begin(), res.end());
        std::cout << res << "\n";
        return dp[n][m];
    }
};

int main()
{   
    Solution lcs;
    string text1 = "program";
    string text2 = "algorithm";
    int length = lcs.longestCommonSubsequence(text1, text2);
    cout << length << endl;
    system("pause");
    return 0;
}