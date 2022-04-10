//
// Created by 53110 on 2022/4/10.
//
#include <string>
#include <set>
#include <vector>

using namespace std;

class Solution804 {
public:
    const vector<string> morseF = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..",
                                   "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
                                   "-.--", "--.."};

    int uniqueMorseRepresentations(vector<string> &words) {
        set<string> s;
        int n_size = words.size();
        if (n_size == 1) return 1;
        for (auto &w: words) {
            string res;
            for (int i = 0; i < w.size(); ++i) {
                res += morseF[w[i] - 'a'];
            }
            s.insert(res);
        }
        return s.size();
    }
};