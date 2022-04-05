//
// Created by 53110 on 2022/4/5.
//
#include <map>
#include <iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution95_ {
public:
    map<int, int> rem;
    int numTrees(int n) {
        if(n == 1 || n == 0){
            return 1;
        }
        if(this->rem.count(n)){
            return this->rem[n];
        }
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            int leftNum = numTrees(i - 1);
            int rightNum = numTrees(n - i);
            count += leftNum * rightNum;
        }
        this->rem.insert(make_pair(n, count));
        return count;
    }
};
int main(){
    cout<< Solution95_().numTrees(3)<<endl;
}