class Solution {
public:
    
    // bool isValid(string s) {
    //     if(s.size() % 2 == 1) return false;
    //     stack<char> stk;
    //     unordered_map<char, char> pairs = {
    //                                         {')', '('},
    //                                         {']', '['},
    //                                         {'}', '{'}
    //                                     };
    //     for(auto &str : s){
    //         if(pairs.count(str)){
    //             if(stk.empty() || stk.top() != pairs[str]){
    //                 return false;
    //             }
    //             stk.pop();
    //         }
    //         else{
    //             stk.push(str);
    //         }
            
    //     }
    //     return stk.empty();

    // }
    bool isValid(string s) {
        stack<char> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                q.push(s[i]);
            }
            else {
                if (q.empty() || (!check(q.top(), s[i])))
                    return false;
                q.pop();
            }
        }
        return q.empty();
    }
    bool check(char x, char y) {
        if (x == '(' && y == ')')
            return true;
        if (x == '{' && y == '}')
            return true;
        if (x == '[' && y == ']')
            return true;
        return false;
    }

};
