//
// Created by 53110 on 2022/4/5.
//
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr){}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right){}
};

class Solution95{
public:
    vector<TreeNode *> generateTrees(int start, int end){
        if(start > end) return { nullptr };
        vector<TreeNode *> allTrees;
        for (int i = start; i <= end; ++i) {
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            for (auto &left:leftTrees) {
                for (auto &right:rightTrees) {
                    TreeNode *curTree = new TreeNode(i);
                    curTree->left = left;
                    curTree->right = right;
                    allTrees.emplace_back(curTree);
                }
            }
        }
        return allTrees;
    }
};