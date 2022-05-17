//
// Created by 53110 on 2022/5/3.
//
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution937{
public:
    vector<string> reorderLogFiles(vector<string>& logs){
        stable_sort(logs.begin(), logs.end(), [&](const string &logs1,
                const string &logs2)->bool{
                        int pos1 = logs1.find_first_of(" ");
                        int pos2 = logs2.find_first_of(" ");
                        bool isDigit1 = isdigit(logs1[pos1 + 1]);
                        bool isDigit2 = isdigit(logs2[pos2 + 1]);
                        if(isDigit1 && isDigit2){
                            return false;
                        }else if (!isDigit1 && !isDigit2){
                            string s1 = logs1.substr(pos1);
                            string s2 = logs2.substr(pos2);
                            if (s1 != s2){
                                return s1 < s2;
                            }
                            return logs1 < logs2;
                        }
                        return !isDigit1;
                });
        return logs;
    }
};
