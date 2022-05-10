//
// Created by 53110 on 2022/5/2.
//

/*题目：
 * 请实现一个函数，把字符串中的每个空格替换成”%20”。
 * 例如，输入”We are happy”
 * 则输出”We%20are%happy.”*/
#include <string>

using namespace std;
class Solution5_{
public:
    void RepalceBlank(string s){
        int length = s.size();
        int NumberOfBlank;
        int numOfSpace = 0;
        for(auto &st : s){
            if(st == ' '){
                numOfSpace++;
            }
        }
        int newS = length + 2 * numOfSpace;
        s.resize(length + newS);
        for(int i = length - 1, j = newS - 1; i < j; --i, --j){
            if(s[i] != ' '){
                s[j] = s[i];
            }else{
                s[j] = '0';
                s[--j] = '2';
                s[--j] = '%';
            }
        }
        return s;
    }
};