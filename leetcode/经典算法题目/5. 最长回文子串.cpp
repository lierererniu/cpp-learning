//
// Created by 53110 on 2022/3/22.
//

#include <string>
#include <iostream>
/*先进行正向和反向hash
假设中点在 mid，臂长为l
如果当前mid-l的哈希值不等于mid+l的哈希值
说明当前中点到两边的回文长度小于前一个 直接continue进行下一个
如果哈希值相等 则判断l+1之后的两字符是否相等，如果相等，说明l+1后还为回文串继续判断l+1直到不满足
储存更新的 mid和l
输出

作者：kongqi
链接：https://leetcode-cn.com/problems/longest-palindromic-substring/solution/czi-fu-chuan-ha-xi-jin-si-onjie-fa-by-ko-aa95/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
using namespace std;
class Solution5{
public:
    //定义一个unsigned long long的形式，他超出的部分会自动削减掉
    typedef unsigned long long ULL;
    int t = 0, P = 131;
    char a[3000];
    ULL hl[3000], hr[3000], p[3000];
    string longestPalindrome(string s){
        string res;
        int ans = 0, mid = 0, l;
        //在每个字符中间插入# , 使新字符数组长度永远为奇数
        a[++t] = '#';
        for (int i = 0; i < s.size(); ++i) {
            a[++t] = s[i];
            a[++t] = '#';
        }
        //插入结尾标志
        a[t + 1] = '\0'; //不对t进行修改


        int sa = t;
        p[0] = 1;
        //每个元素都代表者一个子字符串的映射
        for (int i = 1; i <= sa; ++i) {
            hl[i] = hl[i - 1] * P + a[i];
            hr[i] = hr[i - 1] * P + a[sa - i + 1];//从右往左子字符串映射
            p[i] = p[i - 1] * P;
        }
        for (int i = 1; i <= sa; ++i) {
            l = ans;
            // 左臂长超出 或 右臂长超出
            if (i + l > sa || i - l < 1) break;
            //判断i位置左右l长度的字串是否相等，如果不相等，则说明此l为目前最长臂长，跳出此次循环。
            //这是求取[i - l,i]位置字串映射的公式
            if(hl[i] - hl[i - l - 1] * p[l + 1] != hr[sa - i + 1] - hr[sa - i - l] * p[l + 1]) continue;
            //左右臂长l各进1，如果左右字符还相等，则臂长加一
            while(i + l + 1 <= sa && i - l - 1 >= 1 && a[i + l + 1] == a[i - l - 1]) l++;
            //更新中点位置和长度
            if (l >= ans){
                ans = l;
                mid = i;
            }
        }
        //输出结果
        for (int i = mid - ans; i <= mid + ans && mid + ans <= sa ; ++i) {
            if (a[i] != '#'){
                res += (char)a[i];
            }
        }
        return res;
    }
};

int main(){
    string s = "aerwywej56isab";
    string res = Solution5().longestPalindrome(s);
    cout<<res;
}