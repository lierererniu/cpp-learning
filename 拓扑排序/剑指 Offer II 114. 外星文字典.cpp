//
// Created by 53110 on 2022/5/31.
//

#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution114{
public:
    int visiting = 1, visited = 2;
    unordered_map<char, vector<char>> graph;
    bool isvaild = true;
    string res;
    int index;
    unordered_map<char, int> states;
    string alienOrder(vector<string>& words) {
        const int N = words.size();
        for (auto &s:words) {
            for(auto &w:s){
                if(!graph.count(w)) graph[w] = vector<char>();
            }
        }
        for (int i = 1; i < N && isvaild; ++i) {
            creatGraph(words[i - 1], words[i]);
        }
        res = string(graph.size(), ' ');
        index = graph.size() - 1;
        for (auto [u, _]: graph) {
            if(!states.count(u)) dfs(u);
        }
        if(!isvaild) return "";
        return res;
    }

    void creatGraph(string &before, string &after){
        int len1 = before.size(), len2 = after.size();
        // 索引取二者最小值
        int len = min(len1, len2);
        int i = 0;
        while(i < len){
            char c1 = before[i], c2 = after[i];
            if(c1 != c2){
                graph[c1].emplace_back(c2);
                break;
            }
            i ++;
        }
        // 后一个为前一个子串， 不合法
        if(i == len && len1 > len2) isvaild = false;
    }

    void dfs(char u){
        states[u] = visiting;
        for (auto & v: graph[u]) {
            //若它的下一个字符没有被访问过
            if(!states.count(v)){
                dfs(v);
                if(!isvaild) return;
            }else if(states[v] == visiting){
                // 下一个字符正在访问，成环  不合法
                isvaild = false;
                return;
            }
        }
        states[u] = visited;
        res[index] = u;
        index --;
    }
};
